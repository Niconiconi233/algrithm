//
// Created by soft01 on 19-7-8.
//

#ifndef TEST_MERGE_SORT_H
#define TEST_MERGE_SORT_H

#include "tools.h"
/*
 * 归并排序
 */

template<typename T>
void merge(T* arr, size_t low, size_t mid, size_t high)
{
    T* arr_ = static_cast<T*>(malloc(sizeof(T) * (high - low + 1)));
    assert(arr_ != NULL);
    size_t i = low, j = mid + 1, k = 0;
    while(i <= mid && j <= high)
    {
        if(arr[i] < arr[j])
            arr_[k++] = arr[i++];
        else
            arr_[k++] = arr[j++];
    }
    while(i <= mid)
        arr_[k++] = arr[i++];

    while(j <= high)
        arr_[k++] = arr[j++];

    for(int i = 0; i < k; ++i)
        arr[low + i] = arr_[i];
    delete arr_;
}

template<typename T>
void merge_sort(T* arr, size_t low, size_t high)
{
    if(low < high)
    {
        size_t mid = (high + low) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}


#endif //TEST_MERGE_SORT_H
