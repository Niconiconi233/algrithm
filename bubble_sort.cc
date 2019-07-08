#include "tools.h"

template<typename T>
void bubble_sort(T* arr, size_t len)
{
    for(int i = 0; i < len; ++i)
        for(int j = len - 1; j > 0; --j)
            if(arr[j - 1] > arr[j])
                swap(arr[j - 1], arr[j]);
}

int main(int argc, char const *argv[])
{
    int d3[] = {10,25,68,985,22,452,656,84,102,45,78,5,708,12,405,781,504,12,455};
    size_t len = sizeof(d3)/sizeof(d3[0]);
    bubble_sort(d3, len);
    arr_print(d3, len);
    return 0;
}
