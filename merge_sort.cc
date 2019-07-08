#include "tools.h"

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

int main(int argc, char const *argv[])
{
    int d3[] = {10,25,68,985,22,452,656,84,12,45,78,5,78,12,45,78,45,12,455};
    merge_sort(d3, 0, 18);
    for(int i = 0; i < 19; ++i)
        cout<<d3[i]<<" ";
    cout<<endl;
    return 0;
}
