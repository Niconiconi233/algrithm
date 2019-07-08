//
// Created by soft01 on 19-7-8.
//

#ifndef TEST_STACK_HPP
#define TEST_STACK_HPP

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

#endif //TEST_STACK_HPP
