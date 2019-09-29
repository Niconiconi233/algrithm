//
// Created by soft01 on 2019/9/24.
//

//找出重复的数字

#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void func1(const vector<int>& arr)
{
    if(arr.size() < 1)
        return;
    map<int, int> map_;
    for(auto& i : arr)
    {
        auto it = map_.find(i);
        if(it == map_.end())
            map_[i] = 1;
        else
            cout<<i<<" ";
    }
    cout<<endl;
}

void func2(vector<int>& arr)
{
    if(arr.size() < 1)
        return;
    sort(arr.begin(), arr.end());
    auto it = arr.begin();
    auto it1 = it + 1;
    for(; it1 != arr.end(); ++it, ++it1)
    {
        if(*it1 == *it)
            cout<<*it<<" ";
    }
    cout<<endl;
}

bool func3(vector<int>& arr)
{
    if(arr.size() < 1)
        return false;
    //size_t idx = 0;
    for(size_t i = 0; i < arr.size(); ++i)
    {
        while(arr[i] != i)
        {
            if(arr[i] == arr[arr[i]])
            {
                return true;
            }
            std::swap(arr[i], arr[arr[i]]);
        }
    }
    return false;
}


int main()
{
    vector<int> arr1{2,3,1,0,2,5,3};
    func1(arr1);
    vector<int> arr2{2,3,1,0,2,5,3};
    func2(arr2);
}
