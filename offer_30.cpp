//
// Created by soft01 on 2019/9/29.
//

#include <stack>
#include <iostream>
using namespace std;

//常数时间内获取栈最小值
template<typename T>
class StackWithMin
{
public:
    void push(const T& value)
    {
        if(mainStack_.size() == 0 && secStack_.size() == 0)
        {
            mainStack_.emplace(value);
            secStack_.emplace(value);
        }else
        {
            mainStack_.emplace(value);
            if(value < secStack_.top())
                secStack_.emplace(value);
            else
                secStack_.emplace(secStack_.top());
        }
    }

    void pop()
    {
        mainStack_.pop();
        secStack_.pop();
    }

    const T& min() const
    {
        return secStack_.top();
    }

private:
    stack<T> mainStack_;
    stack<T> secStack_;

};

int main()
{
    StackWithMin<int> stack;
    stack.push(3);
    stack.push(4);
    stack.push(2);
    stack.push(1);
    stack.push(55);
    stack.push(0);

    cout<<stack.min()<<endl;
    stack.pop();
    cout<<stack.min()<<endl;
    stack.pop();
    cout<<stack.min()<<endl;
    stack.pop();
    cout<<stack.min()<<endl;
    stack.pop();
    cout<<stack.min()<<endl;
    stack.pop();
    cout<<stack.min()<<endl;
}

