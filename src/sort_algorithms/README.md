# Sort Algorithms
```
                              ┐                  ┐
1)Bubble                      | O(N^2)           |
2)Insertion                   |                  |
3)Selection                   ┘                  |
                              ┐                  | Comparison Based Sorts
4)Heap Sort                   |                  |
5)Merge Sort                  | O(NLog(N))       |
6)Quick Sort                  |                  |
7)Tree Sort                   ┘                  |
                              ┐                  |
8)Shell Sort                  ┘ O(N^3/2)         |
                                                 ┘
9)Count Sort                  ┐
10)Bucket/Bin Sort            | O(N)               Index Based Sorts
11)Radix Sort                 ┘
```
### Criteria of Analysis

1)Number of comparisons.  
2)Number of swaps.  
3)Adaptive: if any algorithm takes less time or minimum time on an already sorted data, we called it adaptive.  
4)Stable:  
5)Extra Memory: Extra spaces required beside teh data that we need to sort.  


## Buble Sort
Number of Comparison:
`Min O(N), Max O(N^2)`

Number of Swaps:
`Min O(1), Max O(N^2)`

Time:
`Max O(N^2)`

It is adaptive.  
It is suitable for linkedlists.  

## Insertion

Number of comparison:
`Min  O(N), Max`

Number of swaps:
`Min O(1), Max O(N^2)`

Time:
`Min O(N), Max O(N^2)`

It is adaptive.  
It is Stable if we keep `arr[j]>key` in the loop, if we chaneg it to `arr[j]>=key` then  
it is not adaptive.

In this algorithm, we try to insert an item in an array that has already been sorted, so we have to find 
the location for new element by shifting all elements to the right side.


**Example**: We have the following array:   
`2 6 10 15 20 25 30 x`   
And we want to insert `12`, so we check if `12` is bigger than `30`, it is not so we shift it to the right:   

`2 6 10 15 20 25 30 30`  

we check if `12` is bigger than `25`, it is not so we shift it to the right:  
`2 6 10 15 20 25 25 30`   

we check if `12` is bigger than `20`, it is not so we shift it to the right:  
`2 6 10 15 20 20 25 30`   

we check if `12` is bigger than `15`, it is not so we shift it to the right:  
`2 6 10 15 15 20 25 30`   

we check if `12` is bigger than `10`, it is, so we insert it here:  
`2 6 10 12 15 20 25 30`   


### Algorithm
We start we an unsorted array, the most left element is sorted. 

Initial Array:  
`4 3 2 10 12 1 5 6` 

The next element that should be sorted, `array[i]` is `3`, we make back up of it in `key`. `i` is loop variable that start from index `1` to 
the end of array. `j` is the other loop variable that traverse from `i-1` to the beggining of the array to find the correct location for the key.
We compare `array[j]` with our key and if it is bigger than key we shift elements to the right. If it is smaller, we insert our `key` in `array[j]`.
If we have reached the begining of the array we insert our `key` at the irst element of the array;

```
4 is sorted, we start from 3:  
i=1
j=i-1
key=3
4 3 2 10 12 1 5 6
↑ ↑
j i

shifting to the right:
4 4 2 10 12 1 5 6
inserting key at j
3 4 2 10 12 1 5 6


i=2
j=i-1
key=2
3 4 2 10 12 1 5 6
  ↑ ↑
  j i

shifting to the right untill we find the location for our key:
3 3 4 10 12 1 5 6
inserting key at j
2 3 4 10 12 12 5 6


i=3
j=i-1
key=2
2 3 4 10 12 12 5 6
    ↑ ↑
    j i

...

2 3 4 10 10 12 5 6
2 3 4 4 10 12 5 6
2 3 3 4 10 12 5 6
2 2 3 4 10 12 5 6
1 2 3 4 10 12 12 6
1 2 3 4 10 10 12 6
1 2 3 4 5 10 12 12
1 2 3 4 5 10 10 12
1 2 3 4 5 6 10 12
```

## Selection Sort
The idea behid the this sort algorithm is that smallest element should be at `array[0]`, the second smallest element should be at 
`array[1]` and so on. So we use three variables, `i,j,k`.

```
i is pointing to the index of the point in the array which should be i'th min element.
j is variable that search for the i'th min element.
k is pointing to the latest i'th min element found by j.
```
Example:
initial array:
```
8 6 3 2 5 4`
↑ 
i
j
k
```
We are looking for smallest element `(i=0)` to place it at `array[i`]`, so we increase `j`: 

```
8 6 3 2 5 4
↑ ↑ 
i
  j
k
``` 

since `6` is smaller than `array[k]`, we move `k` so it also point at smallest element that we found so far:

```
8 6 3 2 5 4
↑ ↑ 
i
  j
  k
```
Again we increase `j` and since `3` is smaller than `array[k]` we move also the `k`

```
8 6 3 2 5 4
↑   ↑ 
i
    j
    k
```

And the next steps are:

```
8 6 3 2 5 4
↑     ↑ 
i
      j
      k
```

next:
```
8 6 3 2 5 4
↑         ↑ 
i
      ↑   j
      k
```

After `j` reached the end of the array, `k` is pointing to the smallest element we swap the `array[i]` and `array[k]` and increase the `i` and repeat:

```
2 6 3 8 5 4
  ↑         
  i
  j
  k
```

## Heap Sort

## Merge Sort
It is based on merging two already sorted list. We compare the first element of first list with second list, if it is smaller,
we copy it to the final list and increas the index pointing two the first and also the final list list by one, and if 
the element from the second list.
```
First    Second      Final
2   <-   5    <-         <-
8        9
15       12
18       17


First    Second      Final
2        5    <-     2    
8   <-   9               <-
15       12
18       17


First    Second      Final
2        5           2    
8   <-   9    <-     8   
15       12              <-
18       17

First    Second      Final
2        5           2    
8        9    <-     5   
15  <-   12          8   <-
18       17
.
.
.

First    Second      Final
2        5           2    
8        9           5   
15       12          8   
18  <-   17   <-     9
                     12
                     15
                     17
                     18  <- 					 

```


## Quick Sort 
The idea behind this algorithm is that an element is at sorted position if it is bigger than all elements on its left
 and smaller than all elements on its right. It doesn't matter if element on the right or left hand side are not ordered.
In the following array `50` is at sorted position.

`40 30 20 50 90 70 80`


Like Merge Sort, QuickSort is a Divide and Conquer algorithm. It picks an element as pivot and put elements that are smaller than the pivot before the pivot and elements that are larger after the pivot.

There are many different versions of quickSort that pick pivot in different ways.

1) Always pick first element as pivot.
2) Always pick last element as pivot.
3) Pick a random element as pivot.
4) Pick median as pivot.

In quick sort all the major work is done while dividing the array into subarrays (during partitioning), while in case of merge sort, 
all the real work happens during merging the subarrays. In case of quick sort, the combine step does absolutely nothing.


### Algorithm
We pick a pivot, we partition the array around the pivot such that the elements on the left are smaller than 
the pivot and the elements on the right side are bigger than the pivot. The we call quick sort on the left and right hand side sub arrays.

```
quickSort(arr[], low, high)
{
    if (low < high)
    {
        pi = partitioning(arr, low, high);
        quickSort(arr, low, pi - 1);  // Before pi
        quickSort(arr, pi + 1, high); // After pi
    }
}
```
In `partitioning` we find the new location for pivot and we put elemets smaller than pivot on the left and larger elements on right.


```
partitioning(arr[],  low,  high)
{
    //we pick the first element as pivot.
    pivot=arr[low];
    
    i=low;
    j=high;

    /*
	The most exterier loop checks if lower bound if smaller than the higher bound
    */	
    do
    {
        /*
              In this loop we go forward untill the left element of the pivot are smaller than the pivot.
        */
        do
        {
            i++;
        }while (arr[i] <=pivot);

        /*
              In this loop we go backward untill the right element of the pivot are bigger than the pivot.
        */
        do
        {
            j--;
        }while (arr[j] >pivot);
       /*
              We reach here if there is an element on the left side of pivot is bigger than pivot or there is an element on the right
              side of pivot is smaller than pivot 
       */
        if(i<j)
               swap(arr[i],arr[j]);

    }while(i<j);

    swap(arr[low],arr[j]);
    return j;
}
```
For example partitioning `9, 7, 5, 11, 6, 2, 14, 3, 10, 12`:

```
We can pick any element as pivot, here we pick the first element as pivot:

pivot=9

9, 7, 5, 11, 6, 2, 14, 3, 10, 12
↑                                            ↑
i                              j

First this loop will give us this:
do
{
    i++;
}while (arr[i] <=pivot);

9, 7, 5, 11, 6, 2, 14, 3, 10, 12
         ↑                             ↑
         i                    j

This loop will give us the following
do
{
    j--;
}while (arr[j] >pivot);

9, 7, 5, 11, 6, 2, 14, 3, 10, 12
         ↑                  ↑
         i             j

now we swap(arr[i],arr[j])
9, 7, 5, 3, 6, 2, 14, 11, 10, 12
         ↑                 ↑
         i            j

since still i<j (in while(i<j)), we go back to the first part and repeat forwarding i:
9, 7, 5, 3, 6, 2, 14, 11, 10, 12
                  ↑    ↑
                  i    j

backwarding j
9, 7, 5, 3, 6, 2, 14, 11, 10, 12
               ↑  ↑
               j   i

since i<j is false we cant swap(arr[i],arr[j]) and we exit the main loop and we swap(arr[low],arr[j])
9, 7, 5, 3, 6, 2, 14, 11, 10, 12
↑                    ↑
low            j

2, 7, 5, 3, 6, 9, 2, 11, 10, 12
↑                    ↑
low            j

2, 7, 5, 3, 6, 9, 2, 11, 10, 12

and the location of pivot is at 5 (arr[5]=9 ).
```




## Shell Sort
Usefull for sorting very large lists. Shellsort is a generalization of insertion sort. In insertion sort the gap size is 1 but shell sort the gapp size start with `N/2` and then `N/4` and so on.

```
Initial array:

4 3 2 10 12 1 5 14 19 

Gap size is:4

4 3 2 10 12 1 5 14 19 

Gap size is:2

2 1 4 10 12 3 5 14 19 
2 1 4 10 12 3 5 14 19 
2 1 4 10 12 3 5 14 19 
2 1 4 3 12 10 5 14 19 

Gap size is:1

1 2 4 3 5 10 12 14 19 

```

Refs: [1](https://brilliant.org/wiki/sorting-algorithms/)

