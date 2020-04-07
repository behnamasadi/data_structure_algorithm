#include <iostream>
#include <stdexcept>

using namespace std;

int largest_proper_divisor(int n) {
    if (n == 0) {
        throw invalid_argument("largest proper divisor is not defined for n=0");
    }
    if (n == 1) {
        throw invalid_argument("largest proper divisor is not defined for n=1");
    }
    for (int i = n/2; i >= 1; --i) {
        if (n % i == 0) {
            return i;
        }
    }
    return -1; // will never happen
}

void process_input(int n) 
{
    int d ;
    try
    {
        d = largest_proper_divisor(n);
    }
    catch (invalid_argument &e)
    {
        std::cout<<e.what() <<std::endl;
        std::cout<<"returning control flow to caller"<<std::endl;
        return;
    }
        
    cout << "result=" << d << endl;
    std::cout<<"returning control flow to caller"<<std::endl;

}


int main() {
    int n;
    cin >> n;
    process_input(n);
    return 0;
}
