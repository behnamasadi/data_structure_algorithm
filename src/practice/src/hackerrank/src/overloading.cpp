#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


// template
// <typename T>
class Matrix
{
public:
    
   std::vector<std::vector<int> > a;
   friend Matrix operator+(Matrix &x,Matrix &y);
};

Matrix operator+(Matrix &x,Matrix &y)
{
    Matrix result;
    std::vector<int> row, cols;
    row.resize(x.a.at(0).size());
    for(std::size_t i=0;i<x.a.size();i++)
    {

        for( std::size_t j=0;j<x.a.at(i).size();j++ )
        {
            row[j]=x.a[i][j]+y.a[i][j];
        }
        result.a.push_back(row);
    }
    
    return result;
}


int main () {
   int cases,k;
   cin >> cases;
   for(k=0;k<cases;k++) {
      Matrix x;
      Matrix y;
      Matrix result;
      int n,m,i,j;
      cin >> n >> m;
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         x.a.push_back(b);
      }
      for(i=0;i<n;i++) {
         vector<int> b;
         int num;
         for(j=0;j<m;j++) {
            cin >> num;
            b.push_back(num);
         }
         y.a.push_back(b);
      }
      result = x+y;
      for(i=0;i<n;i++) {
         for(j=0;j<m;j++) {
            cout << result.a[i][j] << " ";
         }
         cout << endl;
      }
   }  
   return 0;
}

