#include <stack>
#include <iostream>
#include <vector>
/*

********************* How to push/ pop into/from stack *********************

We represent our histogram as input_array


1) If stack is empty or input_array[i] is higher or equal than top of stack, then push ‘i’ to stack, and i++

2) If the current bar (input_array[i=3]) is smaller than the top of stack (input_array[stack.top()]=6),
then top=store.top() , pop stack and calculate the area.
The area if stack is not empty would be:

before stack.pop()

   stack.top
         ↓  i
6       ┌-┐ ↓
5       | |
4    ┌-┐| |   ┌-┐
3    | || |┌-┐| |
2 ┌-┐|L|| ||R|| |┌-┐
1 | || || ||✓|| || |
   0  1  2  3  4  5

i=3
top=2


after stack.pop()

 stack.top
      ↓     i
6       ┌-┐ ↓
5       | |
4    ┌-┐| |   ┌-┐
3    | || |┌-┐| |
2 ┌-┐|L|| ||R|| |┌-┐
1 | || || ||✓|| || |
   0  1  2  3  4  5

i=3
top=2


Area=(R-L-1)*array[top]
Area=(i-stack.top()-1)*array[top]
Area=(3-1-1)*6

We continue, since height of current bar (input_array[i=3]=3 ) is smaller than input_array[stack.top()=1]=4


before stack.pop()

 stack.top
      ↓     i
6       ┌-┐ ↓
5       | |
4    ┌-┐| |   ┌-┐
3    | || |┌-┐| |
2 ┌-┐|L|| ||R|| |┌-┐
1 | || || ||✓|| || |
   0  1  2  3  4  5

i=3
top=1


after stack.pop()
stack.top
   ↓        i
6       ┌-┐ ↓
5       | |
4    ┌-┐| |   ┌-┐
3    | || |┌-┐| |
2 ┌-┐| || ||R|| |┌-┐
1 |L|| || ||✓|| || |
   0  1  2  3  4  5

i=3
top=1


Area=(R-L-1)*array[top]
Area=(i-stack.top()-1)*array[top]
Area=(3-0-1)*4


We continue, since height of current bar (input_array[i=3]=3 ) is bigger than input_array[stack.top()=0]=2
we push i into stack and then i++.


          stack.top
            ↓
6       ┌-┐    i
5       | |    ↓
4    ┌-┐| |   ┌-┐
3    | || |┌-┐| |
2 ┌-┐| || || ||R|┌-┐
1 |L|| || || ||✓|| |
   0  1  2  3  4  5

i=4


At the end, might have some bars in our histogram which are not processes so we compute the area for them as well.

*/
template
<typename T>
T MaximumRectangularAreaHistogram(T *input_array,size_t size)
{
    std::stack<int> stack;
    size_t i=0;
    int top;
    int max_area=0;
    int width;
    int height;
    int area;
    int left, right;
    while(i<size)
    {
        if ( stack.empty()|| input_array[stack.top()]<= input_array[i])
        {
            stack.push(i++);

        }
        else
        {
            top=stack.top();
            stack.pop();

            right=i;
            height=input_array[top];
            if(stack.empty())
                width= i;
            else
            {
                left=stack.top();
                width= right - left - 1;
            }



            area=height*width;
            if(area>max_area)
                max_area=area;
        }
    }

    while (stack.empty() == false)
    {
        top=stack.top();
        stack.pop();
        left=top;
        right=i;
        height=input_array[top];

        if(stack.empty())
            width= i;
        else
        {
            left=stack.top();
            width= right - left - 1;
        }



        area=height*width;
        if(area>max_area)
            max_area=area;
    }

    return max_area;
}

int main()
{
    std::vector<int> input_array={6, 2, 5, 4, 5, 1, 6};
    int max_area=MaximumRectangularAreaHistogram(&input_array[0], input_array.size());
    std::cout<<max_area <<std::endl;
}
