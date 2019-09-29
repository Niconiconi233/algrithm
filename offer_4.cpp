//
// Created by soft01 on 2019/9/24.
//

#include <iostream>
#include <vector>
using namespace std;

//在二维数组中判断是否存在某值

bool func(const vector<vector<int>>& arr, int res)
{
    if(arr.size() == 0 || arr.front().size() == 0 || res < 0)
        return false;
    int col = arr.size() - 1;
    int row = 0;
    int row_m = arr.front().size();
    while(col >= 0 && row < row_m)
    {
        if(res == arr[row][col])
            return true;
        if(arr[row][col] > res)
        {
            col -= 1;
        }else
        {
            row += 1;
        }
    }
    return false;
}

int main()
{
    vector<vector<int>> arr;
    arr.emplace_back(vector<int>{1,2,4,6});
    arr.emplace_back(vector<int>{2,4,7,8});
    arr.emplace_back(vector<int>{8,9,10,11});
    arr.emplace_back(vector<int>{9,12,13,15});
    vector<vector<int>> arr1;
    cout<<boolalpha<<func(arr1, 0)<<noboolalpha<<endl;
}