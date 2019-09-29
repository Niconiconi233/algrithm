//
// Created by soft01 on 19-7-14.
//

#ifndef TEST_MERGE_SORT_THREAD_H
#define TEST_MERGE_SORT_THREAD_H

#include "tools.h"
#include <future>

/*
 * 多线程版归并排序
 */

template<typename T>
void merge_thread(T* arr, size_t low, size_t mid, size_t hight)
{
    assert(low < hight);
    T* tmp = static_cast<T*>(malloc(sizeof(T) * (hight - low + 1)));
    assert(tmp != NULL);
    size_t l = low, m = mid + 1, i = 0;
    while(l <= mid && m <= hight)
    {
        if(arr[l] < arr[m])
            tmp[i++] = arr[l++];
        else
            tmp[i++] = arr[m++];
    }
    while(l <= mid)
    {
        tmp[i++] = arr[l++];
    }
    while(m <= hight)
    {
        tmp[i++] = arr[m++];
    }
    for(size_t j = 0; j < i; ++j)
        arr[low + j] = tmp[j];
    delete tmp;
}


template<typename T>
void merge_sort_with_thread(T* arr, size_t low, size_t hight)
{

    if(low < hight)
    {
        size_t mid = (hight + low) / 2;
        //std::thread th(merge_sort_with_thread<T>, arr, low, mid);
        auto f = std::async(std::launch::deferred, merge_sort_with_thread<T>, arr, low, mid);
        //cout<<th.get_id()<<endl;
        //merge_sort_with_thread(arr, low, mid);
        merge_sort_with_thread(arr, mid + 1, hight);
        //std::thread th1(merge_sort_with_thread<T>, arr, mid + 1, hight);
        //th1.join();
        f.get();
        merge_thread(arr, low, mid, hight);
    }
}



#endif //TEST_MERGE_SORT_THREAD_H
