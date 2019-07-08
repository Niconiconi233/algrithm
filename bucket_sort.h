//
// Created by soft01 on 19-7-8.
//

#ifndef TEST_BUCKET_SORT_H
#define TEST_BUCKET_SORT_H

#include "tools.h"

#include <vector>

template<typename T>
void merge(T* arr, size_t low, size_t mid, size_t high)
{
    T* arr_ = static_cast<T*>(malloc(sizeof(T) * (high - low + 1)));//辅助数组
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
        arr[low + i] = arr_[i];//拷贝回原数组
    delete arr_;
}

/*
 * 归并排序
 */

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

/*
 *桶排序
 */
const int BUCKET_SIZE = 5;

template<typename T>
void bucket_sort(T* arr, size_t len)
{
    T max = 0, min = 99999999;
    for(int i = 0; i < len; ++i)
    {
        max = arr[i] > max ? arr[i] : max;
        min = arr[i] < min ? arr[i] : min;
    }
    /*
     * 将元素分散进不同范围的桶中
     */
    int range = (max - min) / BUCKET_SIZE;
    std::vector<std::vector<T> > bucket(BUCKET_SIZE + 1);

    for(int i = 0; i < len; ++i)
    {
        int idx = arr[i] / range;
        bucket[idx].push_back(arr[i]);
    }

    size_t idx = 0;
    for(int i = 0; i < bucket.size(); ++i)
    {
        auto& item = bucket[i];
        if(item.size() != 0)
        {
            if(item.size() == 1)
            {
                arr[idx++] = item[0];
                continue;
            }
            merge_sort(item.data(), 0, item.size() - 1);//对桶中元素进行排序
            for(auto t : item)
                arr[idx++] = t;
        }
    }
}


#endif //TEST_BUCKET_SORT_H
