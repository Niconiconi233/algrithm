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


int main(int argc, char const *argv[])
{
    int d3[] = {150,25,68,985,22,452,656,84,102,45,78,5,708,12,405,781,504,12,455};
    size_t len = sizeof(d3)/sizeof(d3[0]) - 1;
    quick_sort(d3, 0, len);
    //partition(d3, 0, len);
    //quicksort(d3, 0, len);
    arr_print(d3, len);
    return 0;
}


