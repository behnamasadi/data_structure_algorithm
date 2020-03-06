#include <vector>
#include <iostream>
template <typename T> using Array = std::vector<T>;
template <typename T> using Matrix = Array <Array <T>>;

template <typename T>
void printArray(Array<T>& array,std::string delimiter="\n")
{
    for (typename std::vector<T>::iterator it = array.begin(); it != array.end(); it++)
	{
		std::cout << *it << delimiter;
	}
}

template <typename T>
void printMatrix(Matrix<T>& mat, std::string delimiter = "\n")
{
    for (typename Matrix<T>::iterator it = mat.begin(); it != mat.end(); it++)
	{
		printArray(*it, delimiter);
		std::cout << "\n" ;
	}
}
