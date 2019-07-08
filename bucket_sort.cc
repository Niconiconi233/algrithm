#include "tools.h"

#include <vector>

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
            merge_sort(item.data(), 0, item.size() - 1);
            for(auto t : item)
                arr[idx++] = t;
        }
    }
}

int main(int argc, char const *argv[])
{
    int d3[] = {150,25,68,985,22,452,656,84,102,45,78,5,708,12,405,781,504,12,455};
    size_t len = sizeof(d3)/sizeof(d3[0]) - 1;
    bucket_sort(d3, len);
    arr_print(d3, len);
    return 0;
}
