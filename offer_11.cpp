//
// Created by soft01 on 2019/9/26.
//

#include <iostream>
#include <vector>
#include <exception>
using namespace std;

int minInOrder(vector<int>& arr, size_t idx1, size_t idx2)
{
    int res = arr[idx1];
    for(size_t i = idx1 + 1; i < idx2; ++i)
    {
        if(res > arr[i])
            res = arr[i];
    }
    return res;
}

//右两个有序的子数组
//二分法查找最小的元素
int func1(vector<int>& arr)
{
    if(arr.size() == 0)
        throw new exception();
    size_t idx1 = 0;
    size_t idx2 = arr.size() - 1;
    while (arr[idx1] >= arr[idx2])
    {
        if(idx2 - idx1 == 1)
        {
            break;
        }
        size_t mid = (idx1 + idx2) >> 1;
        if(arr[idx1] == arr[idx2] && arr[idx1] == arr[mid])//只能顺序查找
            return minInOrder(arr, idx1, idx2);
        if(arr[mid] >= arr[idx1])
            idx1 = mid;
        else if(arr[mid] <= arr[idx2])
            idx2 = mid;
    }
    return arr[idx2];
}



int main()
{
    vector<int> arr{3,4,5,1,2};
    vector<int> arr1{1,0,1,1,1};
    cout<<func1(arr1);
}