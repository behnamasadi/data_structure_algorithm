#include <memory>
#include <vector>
#include <list>

/*
template
<typename T>
class Node
{
public:
    T value;
    std::shared_ptr<Node<T>> next;
};


template
<typename T>
class polynominalNode: public Node<T>
{
public:
	int exp;
	T coef;
};
*/




/*
template
<typename T>
class SparseMatrixNode :public Node<T>
{
public:

    size_t columnIndex;
};
*/


template
<typename T>
class Matrix 
{

public:
    std::vector<T> data;
    std::size_t n;
    virtual T get(std::size_t i, std::size_t j)=0;
    Matrix(std::size_t n):n(n){}
    virtual void display();
    virtual void create();
    virtual void set();
};

template
<typename T>
class Tridiagonal :public Matrix<T> 
{

/*

┌                    ┐
|a00 a01 0   0   0   |
|a10 a11 a12 0   0   |
|0   a21 a22 a23 0   |
|0   0   a32 a33 a34 |
|0   0   0   a43 a44 |
└                    ┘
┌------------------------------------------┐
|lower diagonal | diagonal | upper diagonal|
└------------------------------------------┘
┌-------------------------------------------------------┐
|a10 a21 a32 a43 | a00 a11 a22 a33 a44 | a01 a12 a23 a34|
└-------------------------------------------------------┘

*/




public:
    Tridiagonal() 
    {
        this->data.resize(3*this->n-2);
    }

    T get(std::size_t i, std::size_t j)
    {
        // lower diagonal
        if(i-j==1)
        {
            return this->data[i - 1];
        }
        // diagonal
        else if(i==j)
        {
            return this->data[this->n-1+i - 1];
        }
        // upper diagonal
        else if(i-j==-1)
        {
            return this->data[2*this->n-1+i-1];
        }
        else
        {
            return T(0);
        }
    }

};


template
<typename T>
class  Diagonal :public Matrix<T>
{

/*

┌                    ┐
|a00 0   0   0   0   |
|0   a11 0   0   0   |
|0   0   a22 0   0   |
|0   0   0   a33 0   |
|0   0   0   0   a44 |
└                    ┘

┌-------------------┐
|a00 a11 a22 a33 a44|
└-------------------┘

*/




public:
    Diagonal()
    {
        this->data.resize(this->n);
    }

    T get(std::size_t i, std::size_t j)
    {
        //  diagonal
        if(i==j)
        {
            return this->data[i];
        }
        // non diagonal
        else
        {
            return T(0);
        }
    }

};



template
<typename T>
class  Uppertriangle :public Matrix<T>
{

/*

┌                    ┐
|a00 a01 a02 a03 a04 |
|0   a11 a12 a13 a14 |
|0   0   a22 a23 a24 |
|0   0   0   a33 a34 |
|0   0   0   0   a44 |
└                    ┘
Row majoring
  0   1   2   3   4     5   6   7   8     9   10  11   12  13    14
┌--------------------------------------------------------------------┐
|a00 a01 a02 a03 a04 | a11 a12 a13 a14 | a22 a23 a24 | a33 a34 | a44 |
└--------------------------------------------------------------------┘
└       Row 0        ┘└      Row 1     ┘└    Row 2   ┘└  Row 3 ┘└Row4┘

A mxn

Address(A[i][j])=Base_Address + n + n-1 + n-2 + ... + n-(i-1) + (j-i)
                =Base_Address + i*n - (i-1)(i)/2 +(j-i)

Explenation:
(j-i), because the abount of columns that we have to go forward is dependent on the
row number, for instnce compare the location of a03 with a13 and a23.

*/




public:
    Uppertriangle()
    {
        this->data.resize(this->n*(this->n+1)/2);
    }

    T get(std::size_t i, std::size_t j)
    {
        //  upper diagonal
        if(i<=j)
        {
            return this->data[ i*this->n - (i-1)*(i)/2 +(j-i) ];
        }
        // lower diagonal
        else
        {
            return T(0);
        }
    }
};



template
<typename T>
class  Toeplitz :public Matrix<T>
{

/*

┌          ┐
|a b c d e |
|f a b c d |
|g f a b c |
|h g f a b |
|i h g f a |
└          ┘

  0   1   2   3   4    5   6   7   8
┌-------------------------------------┐
| a   b   c   d   e  | f   g   h   i  |
└-------------------------------------┘
└       Row         ┘└      Col      ┘

For elements in upper triangular:
A[i,j]=Base_Address + j-i

For elements in lower triangular:
A[i,j]=Base_Address + N+ i-j-1
*/




public:
    Toeplitz()
    {
        this->data.resize(this->n +this->n -1);
    }

    T get(std::size_t i, std::size_t j)
    {
        //  upper diagonal
        if(i<=j)
        {
            return this->data[ j-i];
        }
        // lower diagonal
        else
        {
            return this->data[this->n+ i-j-1];
        }
    }
};

namespace sparseMatrix
{

    template <typename T>
    struct Element
    {
        std::size_t i;
        std::size_t j;
        T value;
    };

    template <typename T>
    struct CoordinateList
    {
        std::size_t m;
        std::size_t n;
        std::vector<Element<T>> elements;
        CoordinateList Add(CoordinateList matrix)
        {
            return matrix;
        }

    };

    template <typename T>
    struct Node 
    {
        size_t columnNumber;
        T value;

    };

    template <typename T>
    struct LinkedList
    {
        /*
        Our matrix is MxN. The representation would be an array of linked list

         0 1 2 3 4 5 6 7 8 
        ┌                 ┐
        |0 0 0 0 0 0 0 3 0| 0
        |0 0 8 0 0 1 0 0 0| 1
        |0 0 0 0 0 0 0 0 0| 2
        |4 0 0 0 0 0 0 0 0| 3
        |0 0 0 0 0 0 0 0 0| 4
        |0 0 2 0 0 0 0 0 0| 5
        |0 0 0 6 0 0 0 0 0| 6
        |0 9 0 0 5 0 0 0 0| 7
        └                 ┘
            col_idx, value -> col_idx, value
        ┌ ┐
        |0|-> 7,3
        |1|-> 3,8 -> 5,1
        |2|-> 0,4
        |3|-> 2,2
        |4|->
        |5|-> 2,2
        |6|-> 3,6
        |7|-> 1,9 -> 4,5
        └ ┘
        */

        std::vector<std::list<Node<T>>> data;
        void display() {}
    };

}



/*

p(x)=5x^4 + 2x^2 + 5

┌           ┐
| 5 | 2 | 5 |
| 4 | 2 | 0 |
└           ┘


p(x)=6x^4 + 5x^3 + 9x^2 + 2x + 3

┌                  ┐
| 6 | 5 | 9 | 2 | 2|
| 4 | 3 | 2 | 1 | 0|
└                  ┘



*/

template
<typename T>
struct Term
{
	int exp;
	T coef;
};

template
<typename T>
struct Poly
{
	std::vector<Term <T>> terms;
    Poly add(Poly polynominal) 
    {
        return polynominal;
    }
};

int main()
{
/*
    
┌          ┐
|0 0 3 0 0 |
|4 0 0 0 7 |
|0 0 5 0 8 |
|0 6 0 0 8 |
└          ┘

┌                          ┐
|4 | 1 | 2 | 2 | 3 | 3 | 4 |
|5 | 3 | 1 | 5 | 3 | 5 | 2 |
|6 | 3 | 4 | 7 | 5 | 8 | 6 |
└                          ┘


┌          ┐
|0 0 0 0 2 |
|0 5 0 0 6 |
|4 0 8 0 0 |
|0 0 0 0 9 |
└          ┘

┌                          ┐
|4 | 1 | 2 | 2 | 3 | 3 | 4 |
|5 | 5 | 2 | 5 | 1 | 3 | 5 |
|6 | 2 | 5 | 6 | 4 | 8 | 9 |
└                          ┘

    
    
*/

    return 0;
}
