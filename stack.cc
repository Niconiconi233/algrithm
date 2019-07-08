#include "tools.h"

#include <vector>

template<typename T>
class Stack
{
public: 
    void push(const T& val)
    {
        stack_.push_back(val);
    }

    T pop()
    {
        T val = stack_.back();
        stack_.pop_back();
        return val;
    }

    size_t size()
    {
        return stack_.size();
    }

private: 
    std::vector<T> stack_;

};


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
