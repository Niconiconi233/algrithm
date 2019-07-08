#include "tools.h"
#include "stack.hpp"

int main(int argc, char const *argv[])
{
    Stack<int> stack;
    for(int i = 0; i < 20; ++i)
        stack.push(i);
    while(stack.size())
        cout<<stack.pop()<<" ";
    cout<<endl;
    return 0;
}
