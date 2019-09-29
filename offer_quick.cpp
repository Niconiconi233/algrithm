//
// Created by soft01 on 2019/9/25.
//

#include <vector>
#include <iostream>

using namespace std;

void quick_sort(vector<int>& arr, int low, int high)
{
    if(low >= high || arr.size() == 0 || high > arr.size() || low < 0)
        return;
    int idx = arr[low];
    int l = low, h = high;
    while(l != h)
    {
        while(arr[h] >= idx && h > l)
            --h;
        while(arr[l] <= idx && l < h)
            ++l;
        if(l < h)
            swap(arr[l], arr[h]);
    }
    swap(arr[l], arr[low]);

    quick_sort(arr, low, l);
    quick_sort(arr, l + 1, high);
}

int main()
{
    vector<int> arr{1,22,33,5,6,77,8,99,200,2,34};
    quick_sort(arr, 0, arr.size() - 1);
    for(auto& i : arr)
        cout<<i<<" ";

    return 0;
}

