#include "tools.h"

typedef unsigned long size_t;

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

int main()
{
    int arr[] = {1,10,2,58,62,85,5,7,82,41};
    insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
    for(int i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}