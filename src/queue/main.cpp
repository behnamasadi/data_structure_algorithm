#include <algorithm>
#include <queue>
#include <iostream>

namespace array
{
struct QueueSinglePointerC
{
    int size;
    int front;
    int rare;
    int *Q;
};

struct QueueDoublePointerC
{
    int size;
    int front;
    int rare;
    int *Q;
};

class QueueDoublePointerCPP
{
    int size;
    int front;
    int rare;
    int *Q;
};

class QueueCircular
{
    int size;
    int front;
    int rare;
    int *Q;
};
}

namespace linkedlist {

struct Node
{
    int data;
    Node * next;
};

class Queue
{
    Node *front, *rare;
public:

    Queue()
    {
       front=nullptr;
       rare=nullptr;
    }

    void enqueu(int value)
    {
        Node *t=new Node;
        if(t!=nullptr)
        {
            std::cout<<"queue is full!" <<std::endl;
        }
        else
        {
            t->data=value;
            t->next=nullptr;
            if (front==nullptr)
            {
                front=t;
                rare=t;
            }else
            {
                rare->next=t;
                rare=t;
            }
        }

    }

    void dequeue()
    {

    }


};

}

namespace twoStacks {

}


template<typename T> void print_queue(T& q) {
    while(!q.empty()) {
        std::cout << q.top() << " ";
        q.pop();
    }
    std::cout << '\n';
}


void priority_queue()
{
    //use heap for finding max/min value,

    std::priority_queue<int> q;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q.push(n);

    print_queue(q);

    std::priority_queue<int, std::vector<int>, std::greater<int> > q2;

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q2.push(n);

    print_queue(q2);

    // Using lambda to compare elements.
    auto cmp = [](int left, int right) { return (left ^ 1) < (right ^ 1);};



    std::priority_queue<int, std::vector<int>, decltype(cmp)> q3(cmp);

    for(int n : {1,8,5,6,3,4,0,9,7,2})
        q3.push(n);

    print_queue(q3);

}


int main()
{
    std::queue<int> q;
    std::priority_queue<int> priority_q;
    std::deque<int> dq;



}
