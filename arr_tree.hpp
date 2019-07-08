//
// Created by soft01 on 19-7-6.
//

#ifndef TEST_ARR_TREE_HPP
#define TEST_ARR_TREE_HPP

#include "tools.h"

#include <vector>
#include <stack>
#include <map>

template<typename T>
class Arr_tree
{
public:

    void insert(const T& val)
    {
        tree_.push_back(val);
    }

    void first(size_t pos = 0)
    {
        if(pos < tree_.size())
        {
            cout<<tree_[pos]<<" ";
            first(getLeftChild(pos));
            first(getRightChild(pos));
        }
    }

    void first1()
    {
        size_t pos = 0;
        while(pos < tree_.size() || !stack_.empty())
        {
            while(pos < tree_.size())
            {
                stack_.push(pos);
                cout<<tree_[pos] << " ";
                pos = getLeftChild(pos);
            }
            if(!stack_.empty())
            {
                pos = stack_.top();
                stack_.pop();
                pos = getRightChild(pos);
            }
        }

    }

    void mid(size_t pos = 0)
    {
        if(pos < tree_.size())
        {
            mid(getLeftChild(pos));
            cout<<tree_[pos]<<" ";
            mid(getRightChild(pos));
        }
    }

    void mid1()
    {
        size_t pos = 0;
        while(pos < tree_.size() || ! stack_.empty())
        {
            while(pos < tree_.size())
            {
                stack_.push(pos);
                pos = getLeftChild(pos);
            }
            if(!stack_.empty())
            {
                pos = stack_.top();
                stack_.pop();
                cout<<tree_[pos]<<" ";
                pos = getRightChild(pos);
            }
        }
    }

    void last(size_t pos = 0)
    {
        if(pos < tree_.size())
        {
            last(getLeftChild(pos));
            last(getRightChild(pos));
            cout<<tree_[pos]<<" ";
        }
    }

    void last1()
    {
        int pos = 0;
        std::stack<size_t> stack2;
        while(pos < tree_.size() || !stack_.empty())
        {
            if(pos < tree_.size())
            {
                stack_.push(pos);
                stack2.push(pos);
                pos = getRightChild(pos);
            }else
            {
                pos = stack_.top();
                stack_.pop();
                pos = getLeftChild(pos);
            }
        }
        while(stack2.size() > 0)
        {
            pos = stack2.top();
            stack2.pop();
            cout<<tree_[pos]<<" ";
        }
    }

private:
    std::vector<T> tree_;
    std::stack<size_t> stack_;

private:
    size_t getLeftChild(size_t pos)
    {
        return (pos << 1) + 1;
    }

    size_t getRightChild(size_t pos)
    {
        return (pos << 1) + 2;
    }

    size_t getParent(size_t pos)
    {
        return (pos - 1) >> 1;
    }
};

#endif //TEST_ARR_TREE_HPP
