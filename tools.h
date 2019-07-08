#ifndef TOOLS_H
#define TOOLS_H


#include <iostream>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include <unistd.h>

using std::cout;
using std::endl;


template<typename T>
void swap(T& lhs, T& rhs)
{
    T tmp = lhs;
    lhs = rhs;
    rhs = tmp;
}

template<typename T>
void arr_print(T* arr, size_t len)
{
    for(int i = 0; i < len; ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
}

template<typename T>
T max(const T& lhs, const T& rhs)
{
    return lhs > rhs ? lhs : rhs;
}

template<typename T>
T min(const T& lhs, const T& rhs)
{
    return lhs < rhs ? lhs : rhs;
}

void bezero(void* data, size_t len)
{
    memset(data, 0, len);
}

#endif