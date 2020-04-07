/*****************************************************************************
 * bug.c
 *****************************************************************************
 *
 * Author:      S. Winkler
 * Description: Reproduces a crash that occured in gen_image_to_world_plane
 *
 * (c) 2015 by MVTec Software GmbH
 *             www.mvtec.com
 *
 ****************************************************************************/

#include "stdlib.h"
#include "stdio.h"
#include "math.h"
#include <algorithm>
/* PROBLEM DESCRIPTION:
   This program crashes sporadically in IPMapImageCoordMap with the
   map created by IPGenImageToWorldPlaneCoordMap.
   (if built with the -fsanitize=address flag with gcc, an error is
    reported)

   Context:
   These two functions are used to transform a camera image to a plane
   in world coordinates (e.g. to measure something in the mapped
   image)

   IPMapImageCoordMap is supposed to omit checks on valid memory
   accesses for performance reasons. IPGenImageToWorldPlaneCoordMap
   (which is most likely an offline operation) must create maps such
   that IPMapImageCoordMap does not access invalid
   addresses. Especially the region of the map must only contain
   those parts of the map where correct accesses are possible.

   What is the cause for this problem?

   And how would you fix it?

   This file compiles in Visual Studio in a C++ console project or on
   UNIX systems with gcc.
*/


/* some typedefs and defines that would otherwise be located in HALCON
   header files */
typedef unsigned int Herror;
typedef double Hhom_mat_3d[3][4];
typedef double (*pHhom_mat_3d)[4];
typedef signed int HIMGDIM;
typedef signed int INT4_8;
typedef signed  int INT4;
typedef unsigned char HBOOL;
typedef short HIMGCOOR;
typedef signed int HITEMCNT;
typedef signed int HINT;
typedef unsigned char HBYTE;

#define TRUE  1
#define FALSE 0

/* to reduce the complexity, there are only two error codes */
#define H_MSG_OK 1;
#define H_ERR    42;

/* Simplified (no kind of distortion) struct to represent camera
   parameters */
struct Scamera
{
  double        cx, cy;       /**< Principal point [pixel] */
  double        b;            /**< Principal distance [mm]. */
  double        sx, sy;       /**< Pixel distance on sensor in the x and
                                   y direction [mm] */
  INT4          width;        /**< Witdh of the image */
  INT4          height;       /**< Height of the image */
};
typedef struct Scamera Tcamera;

/* In HALCON region data is represented by a special variant of the
   runlength encoding -- a chord encoding: For every line (chord) of a
   region its row index ("y coordinate", "line number") and the column
   index ("x coordinate") of its start and end point is stored. Both
   the start point and the end point belong to the region.

   Chord data must fulfill the following conditions:

      - a chord is limited to one row
      - chords may not overlap
      - chords are sorted in ascending order
*/

/* Data type for a single run of a region encoded with runlength encoding   */
typedef struct
{
  HIMGCOOR l;               /* line number (row) of run                     */
  HIMGCOOR cb;              /* column index of beginning of run             */
  HIMGCOOR ce;              /* column index of ending of run                */
} Hrun;


typedef struct
{
  HITEMCNT    num;          /* number of runs                               */
  HITEMCNT    num_max;      /* maximum number of runs                       */
  Hrun        *rl;          /* pointer on array of run lengths              */
} Hrlregion;

/* E.g. the simple (one line) region (all pixels marked with x) below 
 
    0 1 2 3 4 5 6 7 8 9   
   | |x|x| | | |x|x|x| |

   would be stored in the region r, with

   r.num = 2,
   r.num_max >= 2,

   r->rl[0] = {l=0, cb=1, ce=2},
   r->rl[1] = {l=0, cb=6, ce=8}.

 */


/* compute linear image coordinates */
#define HLinCoor(L,C,W) (((INT4_8)(L)*(INT4_8)(W))+(INT4_8)(C))

/*****************************************************************************/
/** HImageCoordMap: a coordinate map
 *****************************************************************************
 * \ingroup calibration
 *****************************************************************************/
typedef struct
{
  Hrlregion  *region;    /**< of image map */
  HIMGDIM    width;      /**< of map */
  HIMGDIM    height;     /**< of map */
  float      *row;       /**< subpixel precise row coordinates */
  float      *col;       /**< subpixel precise col coordinates */
} HImageCoordMap;


/*****************************************************************************/
/** HHomMat3DApply: apply the affine transformation given by matrix
 *****************************************************************************
 * \ingroup transformations_3d_transformations
 *****************************************************************************/
static void HHomMat3DApply(const pHhom_mat_3d matrix,
                           double px, double py, double pz,
                           double *qx, double *qy, double *qz)
{
  *qx = matrix[0][0]*px + matrix[0][1]*py + matrix[0][2]*pz + matrix[0][3];
  *qy = matrix[1][0]*px + matrix[1][1]*py + matrix[1][2]*pz + matrix[1][3];
  *qz = matrix[2][0]*px + matrix[2][1]*py + matrix[2][2]*pz + matrix[2][3];
}

/****************************************************************************/
/** IPGenImageToWorldPlaneCoordMap: Generate a projection map that
 *                                  describes the mapping between the
 *                                  image plane and a the plane z=0 of
 *                                  a world coordinate system.
 ****************************************************************************
 * Computes a vector field (map->row, map->col) containing the
 * projection of each pixel from a world plane into the image plane
 * using the nearest neighbor.
 *
 * Note: the scale-value is passed in [m], the campar-values in [mm]
 *
 * \ingroup calibration
 ****************************************************************************/
Herror IPGenImageToWorldPlaneCoordMap(Hhom_mat_3d matrix,
                                      const Tcamera * campar,
                                      double scale, HIMGDIM width,
                                      HIMGDIM height,
                                      HImageCoordMap * map)
{
  double        o_x_c, o_y_c, o_z_c;
  double        dx_x_c, dx_y_c, dx_z_c;
  double        dy_x_c, dy_y_c, dy_z_c;
  double        ox_x, ox_y, ox_z;
  double        oy_x, oy_y, oy_z;
  INT4_8        row_w, col_w;
  double        row_c, col_c;
  double        sum_x, sum_y, sum_z, sum_z_inv;
  INT4_8        l_w;
  double        u, v;
  double        sx_inv, sy_inv;
  HIMGDIM       width_minus_1, height_minus_1;
  HBOOL         inside;
  Hrun          *rl;
  INT4_8        num, num_max;
  /* retrieve parameters from  HImageCoordMap struct */
  HIMGDIM       width_map = map->width;
  HIMGDIM       height_map = map->height;
  float         *map_row = map->row;
  float         *map_col = map->col;
  Hrlregion     *region_mapped = map->region;

  if (campar->sx == 0.0 || campar->sy == 0.0)
    return H_ERR;

  /* Transform the origin of the world plane into camera coordinates: */
  HHomMat3DApply(matrix,0.0,0.0,0.0,&o_x_c,&o_y_c,&o_z_c);
  /* Transform the position of the first point (in x-direction)
     beneath the origin in the world plane from world coordinates into
     camera coodinates: */
  HHomMat3DApply(matrix,scale,0.0,0.0,&dx_x_c,&dx_y_c,&dx_z_c);
  /* Transform the position of the first point (in y-direction)
     beneath the origin in the world plane from world coordinates into
     camera coodinates: */
  HHomMat3DApply(matrix,0.0,scale,0.0,&dy_x_c,&dy_y_c,&dy_z_c);
  /* Calculate the two unit vectors in the camera coordinate
     system. They describe the relative position of two neighboring
     pixels that lie in the world plane using camera coordinates: */
  ox_x = dx_x_c-o_x_c;
  ox_y = dx_y_c-o_y_c;
  ox_z = dx_z_c-o_z_c;

  oy_x = dy_x_c-o_x_c;
  oy_y = dy_y_c-o_y_c;
  oy_z = dy_z_c-o_z_c;

  /* Some calculations to speed up the loop: */
  sx_inv = 1.0/campar->sx;
  sy_inv = 1.0/campar->sy;
  height_minus_1 = height-1;
  width_minus_1 = width-1;
  /* Test if a region chord is already open: */
  inside = FALSE;
  num = 0;
  num_max = region_mapped->num_max;
  rl = region_mapped->rl;
  region_mapped->num = 0;    /* If an error occurs */
  
  /* Run through all pixels of the mapped output image: */
  //for (row_w = 0; row_w < height_map; row_w++)
  for (row_w = 0; row_w <std::min(height_map-1,height_minus_1) ; row_w++)
  {
    /* Calculate the coordinates of the leftmost point in a row of the
     * output image in the camera system: */
    sum_x = o_x_c+(double)row_w*oy_x;
    sum_y = o_y_c+(double)row_w*oy_y;
    sum_z = o_z_c+(double)row_w*oy_z;

    l_w = row_w*width_map;
    for (col_w = 0; col_w <std::min(width_map-1,width_minus_1) ; col_w++)
    {
      /* Transform the 3D point from the camera coordinate system to the
       * image plane: */

      /* Pinhole camera: */
      /* z=0 not allowed for pinhole cameras. */
      if (sum_z != 0.0)
        sum_z_inv = 1.0/sum_z;
      else
        return H_ERR;

      u = campar->b * sum_x * sum_z_inv;
      v = campar->b * sum_y * sum_z_inv;

      /* Quantisation */
      col_c = (u * sx_inv) + campar->cx;
      row_c = (v * sy_inv) + campar->cy;

      /* Check whether the projected pixel lies inside the input
         image: */
      if (row_c > 0 && row_c < height_minus_1 &&
          col_c > 0 && col_c < width_minus_1 )
      {
        map_row[l_w] = (float)row_c;
        map_col[l_w] = (float)col_c;

        /* If no chord is open: */
        if (!inside)
        {
          /* Open a new chord and store the first pixel in it: */
          if (num >= num_max)
            return H_ERR;
          inside = TRUE;
          rl[num].l = (HIMGCOOR)row_w;
          rl[num].cb = (HIMGCOOR)col_w;
        }
      }
      /* Check if the projected pixel lies in the 0.5 pixel wide
       * border of the input image (regarding the pixels as small
       * areas): */
      else if (!(row_c <= -0.5 || row_c >= height_minus_1 ||
                 col_c <= -0.5 || col_c >= width_minus_1))
      {
        /* Clipping should do the trick */
        if (row_c <= 0)
          row_c = 0;
        if (col_c <= 0)
          col_c = 0;

        map_row[l_w] = (float)row_c;
        map_col[l_w] = (float)col_c;
        /* If no chord is open: */
        if (!inside)
        {
          /* Open a new chord and store the first pixel in it: */
          if (num >= num_max)
            return H_ERR;
          inside = TRUE;
          rl[num].l = (HIMGCOOR)row_w;
          rl[num].cb = (HIMGCOOR)col_w;
        }
      }
      else
      {
        /* If the pixel is outside the input image: */
        if (inside)
        {
          /* Close an open chord: */
          inside = FALSE;
          rl[num].ce = col_w - 1;
          num++;
        }
      }

      l_w++;
      /* Calculate the camera coordinates of the next pixel in the row: */
      sum_x += ox_x;
      sum_y += ox_y;
      sum_z += ox_z;
    }
    if (inside)
    {
      /* Close a open chord at the end of an image row: */
      inside = FALSE;
      rl[num].ce = width_map-1;
      num++;
    }
  }

  region_mapped->num = num;

  return H_MSG_OK;
}


/*****************************************************************************/
/** IPBMapImageCoordMap:Applies an arbitrary projection map to the input image.
 *****************************************************************************
 * Action procedure of map_image using
 *   -- image type: BYTE_IMAGE
 *   -- interpolation: using a coordinate map
 * Applies an arbitrary projection map (e.g., generated by
 * gen_image_to_world_plane_map and converted by convert_map) to the input
 * image. The projection map contains two images describing the mapping of
 * each pixel.
 *
 * Input paramters:
 * \pi  image_in     image data to be mapped
 * \pi  width_in     width of input image
 * \pi  map          mapping data; containes the coordinates of each pixel
 *                   mapping
 *
 * Output paramters:
 * \po  image_out:  image data containing the mapped pixels
 *
 * \ingroup calibration
 ****************************************************************************/
void IPBMapImageCoordMap(HBYTE *image_in,
                         HIMGDIM width_in,
                         HImageCoordMap *map,
                         HBYTE *image_out)
{
  INT4_8       l, r, le, l_in, l_in_down;
  INT4_8       num_chords, chord;
  Hrun         *rl;
  INT4         row_int, col_int;
  INT4         width_map = map->width;
  Hrlregion    *region_mapped = map->region;
  double       dx, dy, value_interpol;
  const float  *  row = map->row;
  const float  *  col = map->col;
  HBYTE        *  out = image_out;
  HBYTE        *  in = image_in;

  rl = region_mapped->rl;
  num_chords = region_mapped->num;

  /* run through all pixels lying inside the mapped region: */
  for (chord = 0; chord < num_chords; chord++)
  {
    r = rl[chord].l;
    le = HLinCoor(r,rl[chord].ce,width_map);
    for (l = HLinCoor(r,rl[chord].cb,width_map); l <= le; l++)
    {
      row_int = (INT4)row[l];
      dy = row[l] - row_int;
      col_int = (INT4)col[l];
      dx = col[l] - col_int;
      l_in = (INT4_8)row_int*width_in + col_int;
      l_in_down = l_in+width_in;
      value_interpol = in[l_in]       * (1.0-dx) * (1.0-dy) +
                       in[l_in+1]     * dx * (1.0-dy) +
                       in[l_in_down]  * (1.0-dx) * dy +
                       in[l_in_down+1]* dx * dy;

      out[l] = (HBYTE)(value_interpol+0.5);
    }
  }
}


/*****************************************************************************/
/** HAllocImageCoordMap: helper to allocate a coord_sub_pix map
 *****************************************************************************
 *
 * \ingroup calibration
 *****************************************************************************/
Herror HAllocImageCoordMap(HImageCoordMap * map,
                           Hrlregion * region_mapped,
                           HIMGDIM width_map, HIMGDIM height_map)
{
  map->row = (float*)malloc(sizeof(*map->row)*width_map*height_map);
  map->col = (float*)malloc(sizeof(*map->col)*width_map*height_map);
  map->region = region_mapped;
  map->width = width_map;
  map->height = height_map;

  return H_MSG_OK;
}




int main(int argc, char* argv[])
{
  Hhom_mat_3d     matrix = {0.99997500037979259, 0.0062966418968722470, 0.0032172839875109580, -0.28922659101699999,
                            -0.0063063227569094167, 0.99997559146565307, 0.0030077842680089487, -0.42127175828500002,
                            -0.0031982665178855465, -0.0030279983057704637, 0.99999030111173615, 2.0524869157899999};
  double          scale = 0.00012830085103181400;
  HIMGDIM         width_in = 4384+10;
  HIMGDIM         height_in = 6602+10;
//  HIMGDIM         width_in = 4384;
//  HIMGDIM         height_in = 6576;
  Tcamera         campar;
  HImageCoordMap  coord_map;
  Hrlregion       region_mapped;
  HBYTE           *image_in, *image_out;

  /* preallocate memory for the map and the region contained in the map */
  region_mapped.num = 0;
  /* the resulting region is either barell or cushion shaped so two run
     lengths per line are sufficient */
  region_mapped.rl = (Hrun*)malloc(sizeof(*region_mapped.rl)*2*6602);
  region_mapped.num_max = 2*6602;
  HAllocImageCoordMap(&coord_map,&region_mapped,4387,6602);

  /* the camera parameters for the problematic case */
  /* center point */
  campar.cx = 2250.9623380799999;
  campar.cy = 3278.8358246700004;

  /* focus */
  campar.b = 87.990791599199994;

  /* pixel size */
  campar.sx = 0.0055000703663300003;
  campar.sy = 0.0054999999999999997;

  /* now, create the map */
  //IPGenImageToWorldPlaneCoordMap(matrix,&campar,scale,4384,6576,&coord_map);
  IPGenImageToWorldPlaneCoordMap(matrix,&campar,scale,width_in,height_in,&coord_map);

  /* uninitialized images are sufficient to reproduce the problem */
  image_in = (HBYTE*)malloc(sizeof(*image_in)*width_in*height_in);
  image_out = (HBYTE*)malloc(sizeof(*image_out)*coord_map.width*coord_map.height);

  IPBMapImageCoordMap(image_in,width_in,&coord_map,image_out);


  free(image_in) ;
  free(image_out);
  free(region_mapped.rl);
  free(coord_map.row);
  free(coord_map.col);

  return 0;
}
