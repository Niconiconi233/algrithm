#include "tools.h"
#include "insertion_sort.h"


int main()
{
    int arr[] = {1,10,2,58,62,85,5,7,82,41};
    insertion_sort(arr, sizeof(arr)/sizeof(arr[0]));
    for(size_t i = 0; i < sizeof(arr)/sizeof(arr[0]); ++i)
        cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}