//
// Created by soft01 on 19-7-8.
//
/*
 * 插入排序
 */

#ifndef TEST_INSERTION_SORT_H
#define TEST_INSERTION_SORT_H

using size_t = unsigned long;


template<typename T>
void insertion_sort(T* arr, size_t len)
{
    for(int i = 1; i < len; ++i)
    {
        for(int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
        {
            swap(arr[j], arr[j - 1]);
        }
    }
}

#endif //TEST_INSERTION_SORT_H
