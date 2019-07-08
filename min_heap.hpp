//
// Created by soft01 on 19-7-8.
//

#ifndef TEST_MIN_HEAP_HPP
#define TEST_MIN_HEAP_HPP

#include "tools.h"
#include <vector>
#include <functional>

template<typename T>
bool defaultCompare(const T& lhs, const T& rhs)
{
    return lhs < rhs;
}

template<typename T>
class MinHeap
{
public:
    using compare = std::function<bool(const T& lhs, const T& rhs)>;
    MinHeap(compare cmp = std::bind(&defaultCompare<T>, std::placeholders::_1, std::placeholders::_2))
    :compare_(cmp)
    {}
    void insert(const T val)
    {
        arr_.emplace_back(val);
        insertFixUp(arr_.size() - 1);
    }
    size_t size(){return arr_.size();}
    T top()
    {
        return arr_[0];
    }

    void pop()
    {
        swap(arr_[0], arr_[arr_.size() - 1]);
        arr_.pop_back();
        removeFixUp(0);
    }

    void makeHeap(T* arr, size_t n)
    {
        for(int i = 0; i < n; ++i)
            insert(arr[i]);
    }

private:
    void insertFixUp(size_t pos)
    {
        while(pos != 0)
        {
            size_t parent = getParent(pos);
            if(compare_(arr_[pos], arr_[parent]))
            {
                std::swap(arr_[pos], arr_[parent]);
                pos = parent;
            }else
            {
                break;
            }
        }

    }

    void removeFixUp(size_t pos)
    {
        size_t left = getLeft(pos);
        while(left < arr_.size())
        {
            if(left + 1 < arr_.size() && compare_(arr_[left + 1], arr_[left]))
            {
                ++left;
            }
            if(compare_(arr_[pos], arr_[left]))
            {
                break;
            }else
            {
                std::swap(arr_[pos], arr_[left]);
                pos = left;
                left = getLeft(pos);
            }
        }

    }

    size_t getLeft(size_t pos)
    {
        return (pos << 1) + 1;
    }

    size_t getRight(size_t pos)
    {
        return (pos << 1) + 2;
    }

    size_t getParent(size_t pos)
    {
        return (pos - 1) >> 1;
    }



private:
    std::vector<T> arr_;
    compare compare_;
    //size_t size_;



};

#endif //TEST_MIN_HEAP_HPP
