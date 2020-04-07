#include <algorithm>
#include <vector>
#include <iostream>
#include <memory>
#include <string>
#include <sstream>
#include <iterator>

/*
    This type enum will allow us to distinguish between different types of customer
*/

enum  class Type: unsigned int
{Postpaid, Prepaid};

/*
    To save up time every ember variable is in public but in practice they
    should be in private section and we should access them via getter and setter functions.

    Since The time was running out I only tried to illustrate the main concept of polymorphism, virtual function and up/down casting

*/

class Customer
{
public:
    int id;
    std::string name;
    std::string phoneNumber;
    int balance;
    int totalCallDuration;
    Type customerType;

    void getBalance();
    virtual void credit(){}
    static int ID;

    Customer(std::string name,  std::string phoneNumber, int balance=0, int totalCallDuration=0)
    {
/*
    ID is static variable and will be increased every time we add a customer so the IDs will be unique
*/
        id=ID++;
        this->name=name;
        this->phoneNumber=phoneNumber;
        this->balance=balance;
        this->totalCallDuration=totalCallDuration;
    }

};

class PrepaidCustomer : public Customer
{

public:
    PrepaidCustomer(std::string name,  std::string phoneNumber, int balance=0, int totalCallDuration=0):Customer(name,phoneNumber,balance,totalCallDuration)
    {
        customerType=Type::Prepaid;
    }
    void credit()
    {
        std::cout<<"PrepaidCustomer, recharge" <<std::endl;
    }
};

class PostpaidCustomer : public Customer
{

public:
    PostpaidCustomer(std::string name,  std::string phoneNumber, int balance=0, int totalCallDuration=0):Customer(name,phoneNumber,balance,totalCallDuration)
    {
        customerType=Type::Postpaid;
    }


    void credit()
    {
        std::cout<<"PostpaidCustomer, billPay" <<std::endl;
    }


};

class MobileBilling
{
    public:
    std::vector<std::shared_ptr<Customer> > customers;
    bool addCustomer(std::shared_ptr<Customer> customer)
    {

        //before adding we should check if the number is already exist:

        if( searchByNumber(customer->phoneNumber)!=nullptr  )
        {
            customers.push_back(customer);
            std::cout<<"Customer added successfully" <<std::endl;
            return true;
        }else
        {
            std::cout<<"The given number is taken" <<std::endl;
            return false;
        }
}

    double getAveragePrePaidBalance()
    {
        double sum=0;
        int i=0;
        for(auto customer:customers)
        {
            if (customer->customerType==Type::Prepaid)
            {
                sum=sum+customer->balance;
                i++;
            }
        }
        return sum/(i*1.0);
    }

    std::shared_ptr<Customer> searchById(int id)
    {
        for(auto customer:customers)
        {
            if (customer->id==id)
            {
                return customer;
            }
        }
    }

    void deleteCustomer(int id)
    {
        for(std::size_t i=0;i<customers.size();i++)
        {
            if (customers[i]->id==id)
            {
                customers.erase(customers.begin()+i);
                return;
            }
        }
    }


    std::vector<std::shared_ptr<Customer>> searchByName(std::string name)
    {
        std::vector<std::shared_ptr<Customer>> customerWithSameName;

        for(auto customer:customers)
        {
            if (customer->name==name)
            {
                customerWithSameName.push_back(customer);
            }
        }


        return customerWithSameName;
    }


    std::shared_ptr<Customer> searchByNumber(std::string phoneNumber)
    {
        for(auto customer:customers)
        {
            if (customer->phoneNumber==phoneNumber)
            {
                return customer;
            }
        }
        return nullptr;
    }



    private:

};

int Customer::ID=0;

int main(int argc, char** argv)
{

/*
    Example of adding a PrepaidCustomer and a PostpaidCustomer which has been done via derived to base casting (Upcasting):
*/
    std::string name;
    std::string phoneNumber;
    int balance=0;
    int totalCallDuration=0;

    MobileBilling mobileBillingObject;
    name="prepaidCustomer1";
    phoneNumber="123";
    balance=0;
    totalCallDuration=0;

    std::shared_ptr<PrepaidCustomer>  prepaidCustomer1_ptr;
    prepaidCustomer1_ptr.reset( new PrepaidCustomer(name,phoneNumber,balance,totalCallDuration));
    mobileBillingObject.addCustomer(static_cast<std::shared_ptr<Customer> >(prepaidCustomer1_ptr));


    name="postpaidCustomer1";
    phoneNumber="124";
    balance=0;
    totalCallDuration=0;

    std::shared_ptr<PostpaidCustomer>  postpaidCustomer1_ptr(new PostpaidCustomer(name,phoneNumber,balance,totalCallDuration));

    mobileBillingObject.addCustomer(static_cast<std::shared_ptr<Customer> >(postpaidCustomer1_ptr));



/*
    Here is example of base to derived casting (Downcasting) which can be done based on the type of customer:
*/

    PrepaidCustomer * t1 = static_cast<PrepaidCustomer *> (mobileBillingObject.customers[0].get());
    t1->credit();

    if(t1->customerType==Type::Prepaid)
        std::cout<<"Type is Prepaid"<<std::endl;
    else
        std::cout<<"Type is Postpaid"<<std::endl;

    PostpaidCustomer * t2 = static_cast<PostpaidCustomer *> (mobileBillingObject.customers[1].get());
    t2->credit();

    if(t2->customerType==Type::Prepaid)
        std::cout<<"Type is Prepaid"<<std::endl;
    else
        std::cout<<"Type is Postpaid"<<std::endl;

}
