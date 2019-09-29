//
// Created by soft01 on 2019/9/24.
//

#include <list>
#include <stack>
#include <iostream>

//从尾到头打印链表

using namespace std;

void func1(list<int>& list)
{
    stack<int> stack_;
    auto it = list.begin();
    while(it != list.end())
    {
        stack_.emplace(*it);
        ++it;
    }
    while(true)
    {
        if(stack_.size() > 0)
        {
            cout<<stack_.top()<<" ";
            stack_.pop();
        }else
            break;
    }
}

int main()
{
    list<int> list_{1,2,3,4,5,6,7,8,9,10};
    func1(list_);

    return 0;

}
