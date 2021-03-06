#include <iostream>
#include <algorithm>
#include <vector>
#include <list>
#include <cmath>

template
<typename T>
void printArray(T arr[], size_t size, size_t start=0)
{
    for (size_t i= start; i < size; i++)
        std::cout<<arr[i]<<" ";
    std::cout<<std::endl;
}

template
<typename T>
void bubleSortAlgorithm(T arr[], size_t size)
{

    for(size_t i=0;i<size-1;i++)
    {
        for(size_t j=i+1;j<size;j++)
            if(arr[i] >arr[j] )
                std::swap(arr[i],arr[j] );
    }
}


template
<typename T>
void insertionSortAlgorithm(T arr[], size_t size)
{
    for(size_t i=1;i<size;i++)
    {
        T key=arr[i];
        size_t j=i-1;
        while(arr[j]>key && j>=0)
        {
            arr[j+1]=arr[j];
            j--;
            printArray( arr,   size);
        }
        arr[j+1]=key;
    }
}


template
<typename T>
void shellSort(T arr[], size_t n)
{
    for (size_t gap = n/2; gap > 0; gap /= 2)
    {
        std::cout<<"gap size is:"<<gap <<std::endl;
        for (size_t i = gap; i < n; i += 1)
        {
            int key = arr[i];
            size_t j;
            for (j = i; j >= gap && arr[j - gap] > key; j -= gap)
            {
                arr[j] = arr[j - gap];
            }
            arr[j] = key;
            printArray(arr,n);
        }

    }
    return ;
}

template
<typename T>
void shellSortAlgoritm(T A[],size_t n)
{
    size_t gap,i,j;
    T temp;

    for(gap=n/2;gap>=1;gap/=2)
    {
        for(i=gap;i<n;i++)
        {
            temp=A[i];
            j=i-gap;
            while(j>=0 && A[j]>temp)
            {
                A[j+gap]=A[j];
                j=j-gap;
            }
            A[j+gap]=temp;
        }
    }

}

template
<typename T>
void selectionSortAlgorithm(T arr[], size_t size)
{
/*
    i is pointing to the index of the point in the array which should be i'th min element
    j is variable that search for the i'th min element
    k is pointing to the latest i'th min element found by j
*/
    size_t k;
    for(size_t i=0;i<size-1;i++)
    {
        k=i;
        for(size_t j=i;j<size;j++)
        {
            if(arr[k]>arr[j])
            {
                k=j;
            }
        }
        std::swap(arr[i],arr[k]);
    }

}

template
<typename T>
size_t partitioning(T arr[], size_t low, size_t high)
{
    //we pick the first element as pivot.
    T pivot=arr[low];
    size_t i,j;

    i=low;
    j=high;

    do
    {
        do
        {
            i++;
        }while (arr[i] <=pivot);
        //std::cout<<"arr["<<i<<"] is :"<<arr[i]<<std::endl;
        do
        {
            j--;
        }while (arr[j] >pivot);
        //std::cout<<"arr["<<j<<"] is :"<<arr[j]<<std::endl;
        if(i<j)
        {
            std::swap(arr[i],arr[j]);
            printArray(&arr[0],high);
        }

    }while(i<j);

    std::swap(arr[low],arr[j]);
    return j;
}

template
<typename T>
void quickSort(T arr[], size_t low, size_t high)
{
    size_t j;
    if (low < high)
    {
        
        j = partitioning(arr, low, high);
        quickSort(arr, low, j);
        quickSort(arr,  j+1, high);
    }
}


template
<typename T>
void quickSortAlgorithm(T arr[], size_t size)
{
    size_t low=0;
    size_t high=size;
    quickSort(arr, low, high);
}



template
<typename T>
void merging(T* first, size_t firstSize, T* second, size_t secondSize, T* final)
{
    size_t i, j, k;
    i = 0;
    j = 0;
    k = 0;
    while (i< firstSize && j<secondSize)
    {
        if (first[i] < second[j]) 
        {
            final[k] = first[i];
            i++;
        }
        else
        {
            final[k] = second[j];
            j++;
        }
        k++;
    }
    while (i < firstSize)
    {
        final[k] = first[i];
        i++;
        k++;
    }
    while (j < secondSize) 
    {
        final[k] = second[j];
        j++;
        k++;
    }
}

template
<typename T>
void merging(T* array,  size_t low, size_t mid, size_t high)
{
	size_t i, j, k;
	i = low;
	j = mid+1;
	//k = low;
    k = 0;
    std::vector<T> B;
    size_t arraySize = high - low + 1;
    B.resize(arraySize);
	while (i <= mid && j <= high)
	{
		if (array[i] < array[j])
		{
			B[k] = array[i];
			i++;
		}
		else
		{
			B[k] = array[j];
			j++;
		}
		k++;
	}
    while (i <= mid)
	{
		B[k] = array[i];
		i++;
		k++;
	}
    while (j <= high)
	{
		B[k] = array[j];
		j++;
		k++;
	}
    for (i=low;i<=high;i++) 
    {
        array[i] = B[i- low];
    }
}

//https://www.youtube.com/watch?time_continue=128&v=lOUe8Q9jQow&feature=emb_title
template
<typename T>
void mergeSortIterativeltAlgorithm(T* array, size_t size)
{
    /* complexity nlog(n), because the total number of time that we merge is log(n) and each time we process n elements */
    size_t p, low, mid, high;
    for (p = 1; p < size; p = p * 2)
    {
        for (low = 0; low  < size-p; low += 2* p)
        {
            high = std::min(low+p+p-1,size-1);
            mid = low + p-1;
            std::cout<<  "low: "<< low << " mid: " <<mid <<" high: "<< high <<std::endl;
            merging(array, low, mid, high);
        }
    }
}


template
<typename T>
void mergeSortRecursiveAlgorithm(T* array, size_t low, size_t high)
{
    if(low<high)
    {
        size_t mid=(low+high)/2;
        mergeSortRecursiveAlgorithm(array, low, mid);
        mergeSortRecursiveAlgorithm(array, mid+1, high);
        merging(array, low, mid, high);
    }
}




template
<typename T>
void heapSortAlgorithm(std::vector<T>& array)
{
    size_t size = array.size();
    std::make_heap(array.begin(), array.end());
    for (size_t i = 0;i < size; i++)
    {
        std::pop_heap(array.begin(), array.end());// moves the largest to the end
        std::cout << array[array.size()-1]   <<" ";
        array.pop_back();
    }
    
}

template
<typename T>
void countSortAlgorithm(std::vector<T>& A )
{
    size_t A_size=A.size();
    T max_value=(*std::max_element( A.begin(), A.end()));


    std::vector<T> C(max_value+1,0);
    std::vector<T> B(A_size,0);
    for(size_t i=0;i<A_size;i++)
    {
       C[A[i]]++;
    }

    for(size_t i=1;i<=max_value;i++)
    {
       C[i]=C[i]+C[i-1];
    }

    for(int i=A_size-1;i>=0;i--)
    {
       C[A[i]]--;
       B[C[A[i]]]=A[i];
    }
    A=B;

}

template
<typename T>
void stdSort(T* array, size_t array_size)
{
    std::sort(array,array+array_size);
}


struct Employee
{
    int age;
    std::string name;  // Does not participate in comparisons
};


auto cmp = [](const Employee & lhs, const Employee & rhs) { return (lhs.age < rhs.age);};


template
<typename T>
void stdStableSortAlgorithm(std::vector<T>& array)
{
    std::stable_sort(array.begin(),array.end(),cmp);
}



template
<typename T>
void radixSortAlgorithm(std::vector<T>& A )
{
    T max_value=(*std::max_element( A.begin(), A.end()));
    T numberOfReaptingCountSortAlgorithm=log10(max_value)+1;
    std::vector<T> nthDigit=A;
    for(size_t i=0;i<=numberOfReaptingCountSortAlgorithm;i++)
    {
        for(size_t j=0;j<A.size();j++)
        {
            nthDigit[j]=(A[j]/ int(pow(10,i)))% 10;
        }

        /////////////// Count Sort /////////////////
        size_t nthDigit_size=nthDigit.size();
        T max_value=(*std::max_element( nthDigit.begin(), nthDigit.end()));
        std::vector<T> C(max_value+1,0);
        std::vector<T> B(nthDigit_size,0);
        for(size_t i=0;i<nthDigit_size;i++)
        {
           C[nthDigit[i]]++;
        }
        for(size_t i=1;i<nthDigit_size;i++)
        {
           C[i]=C[i]+C[i-1];
        }
        for(int i=nthDigit_size-1;i>=0;i--)
        {
           C[nthDigit[i]]--;
           B[C[nthDigit[i]]]=A[i];
        }
        A=B;


    }

}


int main()
{
    std::vector<int> unsorted_array={4,3,2,10,12,1,5,14,19};
    size_t n = sizeof(unsorted_array)/sizeof(unsorted_array[0]);

    std::cout<<"Unsorted Array: "<<std::endl;
    std::cout<<"Array size: "<<n  <<std::endl;
    printArray(&unsorted_array[0],  n);

    {
        std::cout<<"**************** Selection Sort Algorithm **************** "<<std::endl;
        std::vector<int> vec(unsorted_array);
        selectionSortAlgorithm(&vec[0], vec.size());
        printArray(&vec[0],  n);
    }

    {
        std::cout<<"**************** Quick Sort Algorithm **************** "<<std::endl;
        std::cout<<"Partitioning array: ";
        std::vector<int> arr={9, 7, 5, 11, 6, 2, 14, 3, 10, 12};
        size_t low=0;
        size_t high=10;
        printArray(&arr[0], high);
        size_t pivot= partitioning( &arr[0], low, high);

        //std::cout<<"After Partitioning: ";
        printArray(&arr[0], high);
        //std::cout<<"partition index is: "<<pivot <<std::endl;

        std::cout<<"**************************************" <<std::endl;
        std::vector<int> vec(unsorted_array);
        quickSortAlgorithm(&vec[0], vec.size());
        printArray(&vec[0], vec.size());
    }


    {
        std::cout<<"**************** Buble Sort Algorithm **************** "<<std::endl;
        std::vector<int> vec(unsorted_array);
        bubleSortAlgorithm(&vec[0], vec.size());
        printArray(&vec[0],  vec.size());
    }


    {
        std::cout<<"**************** Insertion Sort Algorithm **************** "<<std::endl;

        std::vector<int> vec(unsorted_array);
        insertionSortAlgorithm(&vec[0], vec.size());
        printArray(&vec[0], vec.size());
    }



    {
        std::cout<<"**************** Merging Two Sorted List **************** "<<std::endl;
        std::vector<int> first, second, final;

        first = {2,8,15,18};
        second = {5,9,12,17 };

        std::cout<<"first list: "<<std::endl;
        printArray(&first[0], first.size());

        std::cout<<"second list: "<<std::endl;
        printArray(&second[0], second.size());

        std::cout<<"merged list: "<<std::endl;
        final.resize(first.size() + second.size());
        merging(&first[0], first.size(), &second[0], second.size(), &final[0]);
        printArray(&final[0], final.size());


        std::cout<<"**************** Merging a Sorted List **************** "<<std::endl;


        std::vector<int> array = {2,8,15,18, 5,9,12,17};
        std::cout<<"list: "<<std::endl;
        printArray(&final[0], array.size());

        size_t low, mid, high;

        low= 0;
        mid = (array.size() - 1)/2;
        high = array.size()-1;

        merging(&array[0], low , mid, high );
        std::cout<<"sorted merged list: "<<std::endl;
        printArray(&array[0], array.size());

    }


    {
        std::cout<<"**************** Merge Sort (Iterative) Algorithm **************** "<<std::endl;

        std::vector<int> vec(unsorted_array);
        mergeSortIterativeltAlgorithm(&vec[0], vec.size());
        printArray(&vec[0], vec.size());

        std::cout<<"**************** Merge Sort (Recursive) Algorithm **************** "<<std::endl;
        std::vector<int> vec2(unsorted_array);
        mergeSortRecursiveAlgorithm(&vec2[0],  0, vec2.size()-1);
        printArray(&vec2[0], vec2.size());

    }



    {
        std::cout<<"**************** Heap Sort Algorithm **************** "<<std::endl;
        std::vector<int> vec(unsorted_array);
        heapSortAlgorithm(vec);
        printArray(&vec[0], vec.size());
    }

    {
        std::cout<<"**************** Count Sort Algorithm **************** "<<std::endl;
        std::vector<int> vec={4, 0, 0, 1, 0, 2, 4, 5, 1};
        printArray(&vec[0], vec.size());
        countSortAlgorithm(vec);
        printArray(&vec[0], vec.size());

        vec={20,23, 26, 23, 6, 21, 14, 22, 28, 21, 3, 10, 3, 6, 27, 0, 13, 21, 3, 0, 25,11, 28, 24, 13, 28, 23, 21, 29, 4};
        printArray(&vec[0], vec.size());
        countSortAlgorithm(vec);
        printArray(&vec[0], vec.size());

    }

    {
        std::cout<<"**************** Radix Sort Algorithm **************** "<<std::endl;
        std::vector<int> vec = {0,33,100,2,17,27,101,104,8};
        printArray(&vec[0], vec.size());
        radixSortAlgorithm(vec );
        printArray(&vec[0], vec.size());

    }




    {
        std::cout<<"**************** Bucket/Bin Sort Algorithm **************** "<<std::endl;
        std::vector<int> array = {6, 8, 3, 10, 15, 6, 9, 12, 6, 3};

    }

    {
        std::cout<<"**************** Shell Sort Algorithm **************** "<<std::endl;
        std::vector<int> vec={9, 5, 16, 8, 13, 6, 12, 10, 4, 2, 3 };
        printArray(&vec[0], vec.size());
        shellSort(&vec[0], vec.size());
        //shellSortAlgoritm(&vec[0], vec.size());
    }


    {
        std::cout<<"**************** C++ STD Sort Algorithm **************** "<<std::endl;
        std::vector<int> vec(unsorted_array);
        //std::sort(vec.begin(),vec.end());
        stdSort(&vec[0], vec.size());
        printArray(&vec[0], vec.size());
    }

    {
        std::cout<<"**************** C++ STD Stable Sort Algorithm **************** "<<std::endl;
        std::vector<Employee> vec =
           {
               {25, "John"},
               {24, "Nancy"},
               {21, "Alice"},
               {28, "Nancy"},
           };
        stdStableSortAlgorithm(vec);
        for (const Employee & e : vec)
                std::cout << e.age << ", " << e.name << '\n';
    }





    return 0;
}
