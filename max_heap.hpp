//
// Created by soft01 on 19-7-8.
//
/*
 * 最大堆
 */
#ifndef TEST_MAX_HEAP_HPP
#define TEST_MAX_HEAP_HPP

#include "tools.h"

#include <vector>
#include <cstddef>
#include <functional>

template<typename T>
bool defaultCompare(const T& lhs, const T& rhs)
{
    return lhs > rhs;
}

template<typename T>
class MaxHeap
{
public:
    using Compare = std::function<bool (const T&, const T&)>;
    MaxHeap(const Compare&& cmp):arr_(), compare_(cmp){}
    ~MaxHeap(){}

    void insert(const T value)
    {
        arr_.emplace_back(value);
        insertAdjust(arr_.size() - 1);
    }

    T getMax()
    {
        std::swap(arr_[0], arr_[arr_.size() - 1]);
        T tmp = arr_.back();
        arr_.pop_back();
        removeAdjust(0);
        return tmp;
    }

    T& getTop() const
    {
        return arr_[0];
    }

    bool isEmpty() const
    {
        return arr_.size() == 0;
    }

    int size() const
    {
        return arr_.size();
    }

    static MaxHeap makeHeap(T* arr, size_t len)
    {
        MaxHeap heap(std::bind(&defaultCompare<T>, std::placeholders::_1, std::placeholders::_2));
        for(int i = 0; i < len; ++i)
            heap.insert(arr[i]);
        return heap;
    }

    static std::vector<T> heap_sort(T* arr, size_t len)
    {
        auto tmp = makeHeap(arr, len);
        std::vector<T> res;
        while(tmp.size())
        {
            res.push_back(tmp.getMax());
        }
        return res;
    }

private:
    size_t getLeftChild(size_t i)
    {
        return (i << 1) + 1;
    }
    size_t getRightChild(size_t i)
    {
        return (i << 1) + 2;
    }
    size_t getParent(size_t i)
    {
        return (i - 1) >> 1;
    }
    void insertAdjust(size_t pos)
    {
        while(pos != 0)
        {
            size_t parent = getParent(pos);
            if(compare_(arr_[pos], arr_[parent]))
            {
                std::swap(arr_[parent], arr_[pos]);
                pos = parent;
            }else
            {
                break;
            }

        }
    }
    void removeAdjust(size_t pos)
    {
        size_t l = getLeftChild(pos);
        while(l < size())
        {
            if(l + 1 < arr_.size() && compare_(arr_[l + 1], arr_[l]))
                ++l;
            if(compare_(arr_[pos], arr_[l]))
                break;
            else
            {
                std::swap(arr_[l], arr_[pos]);
                pos = l;
                l = getLeftChild(pos);
            }
        }
    }


private:
    std::vector<T> arr_;
    Compare compare_;
};

#endif //TEST_MAX_HEAP_HPP
