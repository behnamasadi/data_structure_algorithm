#include <vector>
#include <iostream>
#include <memory>

enum class Q
{
    Q11,Q12,Q21,Q22
};

template
<typename T>
class Matrix
{
   public:
    size_t m,n;
    std::vector<std::vector<T>> data;
    Matrix(size_t m,size_t n)
    {
        data= std::vector( m , std::vector<T> (n, T(0)));
        this->m=m;
        this->n=n;
    }

    std::shared_ptr<Matrix<T>> subMat(Q quarter)
    {
        size_t row_begin,row_end,col_begin,col_end;
        std::shared_ptr<Matrix<T>> subMatrix(new Matrix(m/2,n/2));

        switch (quarter)
        {
            case Q::Q11:
            {
                row_begin=0;
                row_end=m/2-1;
                col_begin=0;
                col_end=n/2-1;
                break;
            }
            case Q::Q12:
            {
                row_begin=0;
                row_end=m/2-1;
                col_begin=n/2;
                col_end=n;
                break;
            }
            case Q::Q21:
            {
                row_begin=m/2;
                row_end=m;
                col_begin=0;
                col_end=n/2-1;
                break;
            }
            case Q::Q22:
            {
                row_begin=m/2;
                row_end=m;
                col_begin=n/2;
                col_end=n;
                break;
            }
        }
        for(size_t i=0;i<m/2;i++)
        {
            for(size_t j=0;j<n/2;j++)
            {
                subMatrix->data[i][j]=data[i+row_begin][j+col_begin];
            }
        }

        return subMatrix;
    }

    void print()
    {
        for (size_t i = 0; i < m; i++)
        {
            for (size_t j = 0; j < n; j++)
            {
                std::cout<< data[i][j]<< " ";
            }
            std::cout<< "\n";
        }
    }
};


template
<typename T>
void strassenMatrixMultiplication(Matrix<T> &A, Matrix<T> &B , size_t n)
{

    if(n<=2)
    {
        /*
        C[1,1]=A[1,1]*B[1,1] + A[1,2]*B[2,1];
        C[1,2]=A[1,1]*B[1,2] + A[1,2]*B[2,2];
        C[2,1]=A[2,1]*B[1,1] + A[2,2]*B[1,2];
        C[2,2]=A[2,1]*B[1,2] + A[2,2]*B[2,2];
        */
    }
    else
    {
        /*
        ┌                                      ┐
        |A11*B11 + A12*B21    A11*B12 + A12*B22|
        |A21*B11 + A22*B21    A21*B12 + A22*B22|
        └                                      ┘
        */

        strassenMatrixMultiplication(A.subMat(Q::Q11), B.subMat(Q::Q11),n/2);
        strassenMatrixMultiplication(A.subMat(Q::Q12), B.subMat(Q::Q21),n/2);


        strassenMatrixMultiplication(A.subMat(Q::Q11), B.subMat(Q::Q12),n/2);
        strassenMatrixMultiplication(A.subMat(Q::Q12), B.subMat(Q::Q22),n/2);


        strassenMatrixMultiplication(A.subMat(Q::Q21), B.subMat(Q::Q11),n/2);
        strassenMatrixMultiplication(A.subMat(Q::Q22), B.subMat(Q::Q21),n/2);

        strassenMatrixMultiplication(A.subMat(Q::Q21), B.subMat(Q::Q12),n/2);
        strassenMatrixMultiplication(A.subMat(Q::Q22), B.subMat(Q::Q22),n/2);
    }
}





int main()
{
    Matrix<double> mat(4,8);
    mat.data[0][0]=1;
    mat.data[0][4]=2;
    mat.data[2][0]=3;
    mat.data[3][4]=4;
    mat.print();
    std::cout<<"Q11" <<std::endl;
    mat.subMat(Q::Q11)->print();
    std::cout<<"Q12" <<std::endl;
    mat.subMat(Q::Q12)->print();
    std::cout<<"Q21" <<std::endl;
    mat.subMat(Q::Q21)->print();
    std::cout<<"Q22" <<std::endl;
    mat.subMat(Q::Q22)->print();
}
