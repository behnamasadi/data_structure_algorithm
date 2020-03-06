#include <memory>
#include <iostream>
#include <list>
#include <cmath>

template <typename T>
class Node 
{
	public:
		T value;
		Node() {}
		Node(T value) :value(value) {}
		std::shared_ptr<Node<T> > next, previous;

};

template <typename T>
class list
{
public:
    std::shared_ptr<Node<T>> nodes_head;
    size_t  length=0;

    size_t  size()
    {
        return length;
    }

    void append(std::shared_ptr<Node<T>> node)
    {

    }

    void push(T value)
    {
        length++;
        std::shared_ptr<Node<T>> pointer= nodes_head;
        if(pointer==nullptr)
        {
            std::shared_ptr<Node<T>> node_ptr(new Node<T>);
            node_ptr->value=value;
            nodes_head=node_ptr;
            return;
        }
        else
        {
            while(pointer->next!=nullptr)
            {
                pointer=pointer->next;
            }
            std::shared_ptr<Node<T>> node_ptr(new Node<T>);
            node_ptr->value=value;
            pointer->next=node_ptr;
        }

    }

    void print()
    {
        std::shared_ptr<Node<T>> pointer= nodes_head;
        while (pointer!=nullptr)
        {
            std::cout << pointer->value << "->";
            pointer=pointer->next;
        }
         std::cout <<"null"<<std::endl;
    }

    void insert(T value, size_t index)
    {

    }

    T sum()
    {
        T sum=0;
        return sum;
    }

    std::shared_ptr<Node<T>> max()
    {
        std::shared_ptr<Node<T>> node_ptr;
        return node_ptr;
    }

    std::shared_ptr<Node<T>> search(T value )
    {
        std::shared_ptr<Node<T>> node_ptr;
        return node_ptr;
    }

    void remove (size_t index)
    {

    }


};

template <typename T>
void printSTDList(std::list<T> &list)
{
    for(typename std::list<T>::iterator it=list.begin();it!=list.end();it++)
    {
        std::cout<<*it <<"->";
    }
    std::cout<<"null" <<std::endl;
}

//find middle node of a linked list
template <typename T>
void linkedListmiddleNode(std::list<T> &list)
{
    typename std::list<T>::iterator j=list.begin();

    //std::advance(it, 2)
    for(typename std::list<T>::iterator it=list.begin()  ;it!=list.end();it = std::next(it, 2))
    {
        std::cout<<*it <<std::endl;
        j++;
    }
    std::cout<<"The middle point is: " <<*j <<std::endl;
}

void findingIntersectingPointOfTwoLinkedList()
{

}


template <typename T, typename L>
struct polynominalNode 
{
    L exponent;
    T coefficient;
};

void polynominalRepresentationUsingLinkedList() 
{
    std::list<polynominalNode<double, int>> polynominalTerms;
    
    //4*x^3 + 9*x^2 +6*x + 7
    polynominalNode<double, int> t1,t2,t3,t4;
    t1.coefficient=4;
    t1.exponent=3;

	t2.coefficient =9 ;
	t2.exponent =2 ;


	t3.coefficient =6 ;
	t3.exponent =1 ;


	t4.coefficient =7 ;
	t4.exponent = 0;
    double x = 5;
    double sum=0;
    for (std::list<polynominalNode<double, int>>::iterator it = polynominalTerms.begin(); it != polynominalTerms.end(); it++) 
    {
        sum += it->coefficient * (pow(x, it->exponent));
    }

}

int main() 
{

    list<int> mylist;


    mylist.push(1);
    mylist.push(3);
    mylist.push(7);
    mylist.push(11);
    mylist.push(21);
    mylist.print();





    std::list<int> std_list;
    std_list.push_back(1);
    std_list.push_back(3);
    std_list.push_back(5);
    std_list.push_back(2);
    std_list.push_back(7);
    std_list.push_back(1);
    std_list.push_back(0);
    //std_list.size()
    //std_list.list
    printSTDList(std_list);

    //linkedListmiddleNode(std_list);


}
