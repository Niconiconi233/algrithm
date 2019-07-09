//
// Created by soft01 on 19-7-8.
//
/*
 * 快排
 */

#ifndef TEST_QUICK_SORT_H
#define TEST_QUICK_SORT_H

#include "tools.h"

/*
    先从右边开始查找
 */
template<typename T>
void quick_sort(T* arr, size_t low, size_t high)
{
    if(high <= low)
        return;
    size_t l = low, h = high;
    T pat = arr[low];
    while(l != h)
    {
        while(arr[h] >= pat && h > l)//right first
            --h;

        while(arr[l] <= pat && l < h)
            ++l;

        if(l < h)
            swap(arr[l], arr[h]);
    }
    swap(arr[low], arr[l]);

    quick_sort(arr, low, l - 1);
    quick_sort(arr, l + 1, high);
}


#endif //TEST_QUICK_SORT_H
