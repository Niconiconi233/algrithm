//
// Created by soft01 on 2019/9/25.
//

#include <stack>
#include <queue>
#include <iostream>

using namespace std;

//栈实现队列
template<typename T>
class CQueue
{
public:
    CQueue(){}
    ~CQueue(){}

    void append(const T& value)
    {
        stack1_.emplace(value);
    }

    const T& front()
    {
        if(stack2_.size() > 0)
            return stack2_.top();
        else
        {
            while(stack1_.size() > 0)
            {
                stack2_.emplace(stack1_.top());
                stack1_.pop();
            }
            return stack2_.top();
        }
    }
    void pop_front()
    {
        if(stack2_.size() > 0)
            stack2_.pop();
        else
        {
            front();
            stack2_.pop();
        }
    }

    int size()
    {
        return stack2_.size() + stack1_.size();
    }


private:
    stack<T> stack1_;
    stack<T> stack2_;
};

//队列实现栈

template<typename T>
class CStack
{
public:
    CStack(){}
    ~CStack(){}

    void append(const T& value)
    {
        if(queue1_.size() == 0 && queue2_.size() == 0)
            queue1_.emplace(value);
        else if(queue1_.size() > 0)
            queue1_.emplace(value);
        else
            queue2_.emplace(value);
    }

    T getAndDelete()
    {
        if(queue1_.size() > 0)
        {
            while(queue1_.size() > 1)
            {
                queue2_.emplace(queue1_.front());
                queue1_.pop();
            }
            T tmp(std::move(queue1_.front()));
            queue1_.pop();
            return tmp;
        }else
        {
            while(queue2_.size() > 1)
            {
                queue1_.emplace(queue2_.front());
                queue2_.pop();
            }
            T tmp(std::move(queue2_.front()));
            queue2_.pop();
            return tmp;
        }
    }

    int size()
    {
        return queue1_.size() + queue2_.size();
    }

private:
    queue<T> queue1_;
    queue<T> queue2_;
};



int main()
{
    CQueue<int> queue;
    queue.append(5);
    queue.append(4);
    queue.append(3);
    queue.append(2);
    queue.append(1);

    while(queue.size() > 0)
    {
        cout<<queue.front()<<" ";
        queue.pop_front();
    }

    cout<<endl;
    CStack<int> stack;
    stack.append(1);
    stack.append(2);
    stack.append(3);
    stack.getAndDelete();
    stack.append(4);
    stack.append(5);


    while(stack.size() > 0)
        cout<<stack.getAndDelete()<<" ";

    return 0;
}

