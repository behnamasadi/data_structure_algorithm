#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


class Person
{
protected:
    int age;
    std::string name; 
public:
    void virtual putdata(){}
    void virtual getdata(){}
};

class Professor: public Person
{
    
    int publications;
    int id;
    static int cur_id;
public:
    Professor()
    {
        id=cur_id;
        cur_id=cur_id+1;

    }
    void getdata() 
    {
        std::cin>>name;
        std::cin>>age;
        std::cin>>publications;
    }
    void putdata()
    {
        cout<<name<<" "<<age<<" "<<publications<<" "<<id <<endl;
    }
    
};
class Student: public  Person
{
    int marks[6];
    int id;
    static int cur_id;
 public:   
    Student()
    {
        id=cur_id;
        cur_id=cur_id+1;
    }
   
   void getdata( ) 
    {
        std::cin>>name;
        std::cin>>age;
        for(int i=0;i<6;i++)
        {
            std::cin>>marks[i];
        }

    }
    
    void putdata()
    {   
        int sum=0;
        for(int i=0;i<6;i++)
            {
            sum=sum+marks[i];
        }
        
//         cout<<name<<" "<<age<<" "<<std::accumulate(std::begin(marks),std::end(marks),0)<<" "    <<cur_id <<endl;
        cout<<name<<" "<<age<<" "<<sum<<" "    <<id <<endl;
        
    }    
};

int Professor::cur_id=1;
int Student::cur_id=1;

int main(){

    int n, val;
    cin>>n; //The number of objects that is going to be created.
    Person *per[n];

    for(int i = 0;i < n;i++){

        cin>>val;
        if(val == 1){
            // If val is 1 current object is of type Professor
            per[i] = new Professor;

        }
        else per[i] = new Student; // Else the current object is of type Student

        per[i]->getdata(); // Get the data from the user.

    }

    for(int i=0;i<n;i++)
        per[i]->putdata(); // Print the required output for each object.
//     delete [] per;
    return 0;
}

