#include <iostream>

void tailRecursionFunc(int n)
{
	if (n > 0) 
	{
		std::cout << n << std::endl;
		tailRecursionFunc( n-1);
	}
}

void tailRecursionFuncIterative(int n) 
{
	while (n > 0) 
	{
		std::cout << n << std::endl;
		n--;
	}
}

void headRecursionFunc(int n)
{
	if (n > 0)
	{
		headRecursionFunc(n - 1);
		std::cout << n << std::endl;
	}
}

void headRecursionFuncIterative(int n)
{
	int i = 1;
	while (i<n )
	{
		std::cout << i << std::endl;
		i++;
	}
}

void treeRecursionFunc(int n)
{
	if (n > 0)
	{
		std::cout << n << std::endl;
		treeRecursionFunc(n - 1);
		treeRecursionFunc(n - 1);
	}
}

void indirectRecursionFuncB(int n);
void indirectRecursionFuncA(int n) 
{
	if (n > 0) 
	{
		std::cout << n << std::endl;
		indirectRecursionFuncB(n - 1);
	}
}

void indirectRecursionFuncB(int n)
{
	if (n > 1)
	{
		std::cout << n << std::endl;
		indirectRecursionFuncA(n/2);
	}
}

int nestedRecursionFunc(int n)
{

	if (n > 100)
		return n - 10;
	else
		return nestedRecursionFunc(nestedRecursionFunc(n + 11));
	
}


/*

e(x)=1+ x/1 + x^2/2! + x^3/3! + x^4/4! +... +x^n/n!
     1+ f(x,1)+f(x,2)+ f(x,3)+  f(x,4)  +     + f(x,n)

*/
double e(int n, int x)
{
    static double p=1,f=1;
    double r;
    if(n==0)
        return 1;
    r=e(x,n-1);
    p=p*x;
    f=f*n;
    return r+p/f;
}

/*
Combination
nCr=n!/(n-r)!r!

Permutation
nPr=n!/(n-r)!

Pascal's rule
nCr=(n-1)C(r-1) + (n-1)C(r) 

                  1
               1     1
            1     2     1
          1     3     3     1
       1     4     6     4     1
    1     5    10    10     5     1
 1     6    15    20    15     6     1
 

*/
int combinationRecursive()
{
	return 0;
}

int main() 
{
	int n = 95;
	//headRecursionFunc(n);
	//headRecursionFuncIterative(n);

	//treeRecursionFunc(n);

	//indirectRecursionFuncA( n);



	std::cout << nestedRecursionFunc(n) << std::endl;

}
