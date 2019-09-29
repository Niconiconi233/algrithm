//
// Created by soft01 on 2019/9/29.
//

#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> g_stack;

bool isPopOrder(vector<int>& push, vector<int>& pop)
{
    if(push.size() == 0 || pop.size() == 0)
        return false;
    auto push_begin = push.begin();
    auto push_end = push.end();
    auto pop_begin = pop.begin();
    auto pop_end = pop.end();

    while(pop_begin < pop_end)
    {
        while(*push_begin != *pop_begin)
        {
            g_stack.emplace(*push_begin);
            ++push_begin;
        }
        if(push_begin == push_end)
            break;
        if(*push_begin == *pop_begin)
        {
            g_stack.emplace(*push_begin);
            ++push_begin;
        }
        if(g_stack.top() != *pop_begin)
            break;
        else
        {
            g_stack.pop();
            ++pop_begin;
        }
        if(pop_begin == pop_end)
            return true;
    }
    return false;
}

int main()
{
    vector<int> push{1,2,3,4,5};
    vector<int> pop{4,3,5,1,2};
    cout<<isPopOrder(push, pop);
    return 0;
}
