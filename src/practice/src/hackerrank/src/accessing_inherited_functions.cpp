#include<iostream>

using namespace std;

class A
{
    public:
        A(){
            callA = 0;
        }
    private:
        int callA;
        void inc(){
            callA++;
        }

    protected:
        void func(int & a)
        {
            a = a * 2;
            inc();
        }
    public:
        int getA(){
            return callA;
        }
};

class B
{
    public:
        B(){
            callB = 0;
        }
    private:
        int callB;
        void inc(){
            callB++;
        }
    protected:
        void func(int & a)
        {
            a = a * 3;
            inc();
        }
    public:
        int getB(){
            return callB;
        }
};

class C
{
    public:
        C(){
            callC = 0;
        }
    private:
        int callC;
        void inc(){
            callC++;
        }
    protected:
        void func(int & a)
        {
            a = a * 5;
            inc();
        }
    public:
        int getC(){
            return callC;
        }
};
#include <vector>
#include <iterator>
#include<iostream>
class D:public A,public B,public C
{

    int val;
    int primeNumerSet[3];
    //std::vector<int> A,B,C;
    int Acounter,Bcounter,Ccounter;

    public:
        //Initially val is 1
         D()
         {
            val = 1;
            primeNumerSet[0]=2;
            primeNumerSet[1]=3;
            primeNumerSet[2]=5;
            Acounter=0;
            Bcounter=0;
            Ccounter=0;
         }


         void primeNumberFactorization(int number)
         {
             for (auto i:primeNumerSet)
             {
                 if(number%i==0)
                 {
                     switch (i)
                     {
                     case 2:
                         Acounter++;
                         break;
                     case 3:
                         Bcounter++;
                         break;
                     case 5:
                         Ccounter++;
                         break;
                     default:
                         break;
                     }
//                     std::cout<<i<<std::endl;
                     primeNumberFactorization(number/i);
                     break;
                 }
             }
             return;
         }


         //Implement this function
         void update_val(int new_val)
         {
            primeNumberFactorization(new_val);


            for(int i=0;i<Acounter;i++)
                this->A::func(val);
            for(int i=0;i<Bcounter;i++)
                this->B::func(val);
            for(int i=0;i<Ccounter;i++)
                this->C::func(val);

         }
         //For Checking Purpose
         void check(int); //Do not delete this line.
};





void D::check(int new_val)
{
    update_val(new_val);
    cout << "Value = " << val << endl << "A's func called " << getA() << " times " << endl << "B's func called " << getB() << " times" << endl << "C's func called " << getC() << " times" << endl;
}


int main()
{
    D d;
    int new_val;
    cin >> new_val;
    d.check(new_val);

}
