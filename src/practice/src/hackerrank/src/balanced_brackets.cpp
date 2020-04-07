#include <stack>
#include <string>
#include <iostream>

std::string isBalanced(std::string s) 
{
    //std::stack<char> pStack,bStack,cStack;
    std::stack<char> stack;
    for(char c:s)
    {
         switch(c)
        {
            case '{' :
            stack.push(c);
            break;
            case '}' :
            if(stack.size()>0 &&  stack.top()=='{')
                stack.pop();
            else
                return "NO";
            break;
            case '[' :
            stack.push(c);
            break;
            case ']' :
            if(stack.size()>0 && stack.top()=='[')
                stack.pop();
            else
                return "NO";
            break;
            case '(' :
            stack.push(c);
            break;
            case ')' :
            if(stack.size()>0 && stack.top()=='(')
                stack.pop();
            else
                return "NO";
            break;
        }
    }
     if(stack.size()==0 )
        return "YES";
     else
         return "NO";
}



//     switch (number)
//     {
//     case 2:
//         std::cout<<"number is two." <<std::endl;
// /*
//         If we remove this break, our program will continue from next block so we will have in output
//         number is two.
//         number is ten.
// */
//         break;
//     case 10:
//         std::cout<<"number is ten." <<std::endl;
//         break;
//     default:
//             std::cout<<"number is neither two or ten." <<std::endl;
//         break;
//     }



int main()
{
    std::string s="}][}}(}][))]";
    std::cout<<isBalanced(s); 
}
