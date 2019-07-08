//
// Created by soft01 on 19-7-8.
//

#ifndef TEST_BUBBLE_SORT_H
#define TEST_BUBBLE_SORT_H

#include "tools.h"

template<typename T>
void bubble_sort(T* arr, size_t len)
{
    for(int i = 0; i < len; ++i)
        for(int j = len - 1; j > 0; --j)
            if(arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
}

#endif //TEST_BUBBLE_SORT_H
