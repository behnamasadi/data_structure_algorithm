#include <stdio.h>
#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>

//The following examples are taken from "Competitive Programmer's Handbook" written by Antti Laaksonen https://cses.fi/book.html
/*
Coin problem
In this problem we are interdted to make a sum of money x with set of coins values {c1,c2,...ck} by using the minimum nuber of coins

*/

int c[]={1,3,4}; // value of coins
int k=3; //number of cpins that we have

/*
The d[20] array is for memorization, for instance if we computed f_coin_problem_memo(3),
we put this value in d[3] and we don't compute it again, we just use d[3] instead of f_coin_problem_memo(3)
*/
int d[20];
int f_coin_problem_memo(int x)
{
    if (x < 0) return 1e9;
    if (x == 0) return 0;
    if (d[x]) return d[x];
    int u = 1e9;
    int u_old = 1e9;
    for (int i = 0; i < k; i++)
    {
        u_old=u;
        u = std::min(u, f_coin_problem_memo(x-c[i]) +1);
    }
    d[x] = u;
    return d[x];
}


/***************************** Paths in a grid *****************************/
/*

finding a path in an n × n grid from the upper-left corner to the lower-right corner. We are only allowed
 to move right or down.

1,1  1,2 .... 1,X
2,1  2,2 .... 2,X
.
.
.
Y,1  Y,2 .... Y,X


3 7 9 2 7
9 8 3 5 5
1 7 9 8 5
3 8 6 4 10
6 3 9 7 8

*/

int grid[5][5]={{3,7, 9, 2, 7},{9, 8, 3 ,5 ,5},{1, 7 ,9 ,8 ,5},{3, 8, 6 ,4 ,10},{6, 3 ,9 ,7 ,8}};
int memo[5][5]{{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1},{-1,-1,-1,-1,-1}};

std::vector<int>x_solution,y_solution;

int f_paths_in_grid(int y,int x)
{
    if((x==0)&& (y==0))
    {
        memo[y][x]=grid[0][0];
    }
    else if (x==0)
    {
        if(memo[y][x]<0)
        {
            memo[y][x] =f_paths_in_grid(y-1,x) +grid[y][x];
        }
    }
    else if(y==0)
    {
       if(memo[y][x]<0)
       {
            memo[y][x]=f_paths_in_grid(y,x-1) +grid[y][x];
       }
    }
   else if(memo[y][x]<0)
   {
        memo[y][x]=std::max(f_paths_in_grid(y,x-1)  ,f_paths_in_grid(y-1,x)  )+grid[y][x];
    }
    return  memo[y][x];
}



//Levenshtein distance in c

int LevenshteinDistance(const char *s, int len_s, const char *t, int len_t)
{
  int cost;

  /* base case: empty strings */
  if (len_s == 0) return len_t;
  if (len_t == 0) return len_s;

  /* test if last characters of the strings match */
  if (s[len_s-1] == t[len_t-1])
      cost = 0;
  else
      cost = 1;

  /* return minimum of delete char from s, delete char from t, and delete char from both */
  return std::min(   std::min(LevenshteinDistance(s, len_s - 1, t, len_t    ) + 1,LevenshteinDistance(s, len_s    , t, len_t - 1) + 1 )    ,  LevenshteinDistance(s, len_s - 1, t, len_t - 1) + cost );
}


//Levenshtein distance in c++

int LevenshteinDistance(std::string s, std::string t )
{
  int cost;

  /* base case: empty strings */
  if (s.length() == 0) return t.length();
  if (t.length() == 0) return s.length();

  /* test if last characters of the strings match */
  if (s.at(s.length()-1)  == t.at(t.length()-1) )
      cost = 0;
  else
      cost = 1;

  /* return minimum of delete char from s, delete char from t, and delete char from both */

  return std::min(   std::min(LevenshteinDistance(s.substr(0, s.size()-1 ),t ) + 1,LevenshteinDistance(s  , t.substr(0, t.size()-1 )) + 1 )    ,  LevenshteinDistance(s.substr(0, s.size()-1 ), t.substr(0, t.size()-1 )) + cost );
}


//seam carving

int main(int argc, char** argv)
{



/******************************** Coin Example ********************************/
    std::cout<<"******************************** Coin Example ********************************"<<std::endl;
    std::cout<<"The minimum number of coins from the set {1,3,4} to sum up value of 12 is:"<<std::endl;
    std::cout<<f_coin_problem_memo(12)<<std::endl;



/******************************** Levenshtein Distance ********************************/
    std::cout<<"******************************** Levenshtein Distance ********************************"<<std::endl;

//  calling c-style string function
//    char* s="saturday";
//    char* t="sunday";
//    std::cout<<LevenshteinDistance(s,8,t,6)<<std::endl;

    std::string s="saturday";
    std::string t="sunday";
    std::cout<<"The Levenshtein distance between "<<s <<" and "<< t<<" is:"<<std::endl;
    std::cout<<LevenshteinDistance( s, t )<<std::endl;

/******************************** The Most Costly Path on a Grid ********************************/

    std::cout<<"******************************** Most Costly Path on a Grid ********************************"<<std::endl;
    std::cout<<"maximum sum on a path from the upper-left corner to the lower-right corner is:" <<std::endl;
    std::cout<< f_paths_in_grid(4,4)<<std::endl;

    std::cout<<"******************************** Cost on the Grid ********************************"<<std::endl;
    for(std::size_t y=0;y<5;y++)
    {
        for(std::size_t x=0;x<5;x++)
        {
            std::cout<< memo[y][x] <<"|";
        }
        std::cout<< "\n";
        std::cout<< "---------------"<<std::endl;
    }


    return 0;
}



