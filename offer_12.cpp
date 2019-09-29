//
// Created by soft01 on 2019/9/27.
//

#include <iostream>
#include <vector>
using namespace std;
//矩阵中的路径
vector<char> arr{'a','b','t','g','c','f','c','s','j','d','e','h'};
vector<int> visited(12, 0);

bool hasPathCore(int row, int col, const char* str, int& pathLength)
{
    if(str == nullptr)
        return false;
    if(str[pathLength] == '\0')
        return true;
    bool haspath = false;
    auto i = str[pathLength];
    auto j = arr[row * 4 + col];
    auto k = visited[row * 4 + col];
    if(row >= 0 && row < 3 && col >= 0 & row < 4 && arr[row * 4 + col] == str[pathLength] && !visited[row * 4 + col])
    {
        ++pathLength;
        visited[row * 4 + col] = 1;
        haspath = hasPathCore(row , col - 1, str, pathLength) || hasPathCore(row, col + 1, str, pathLength) || hasPathCore(row - 1, col, str, pathLength) ||hasPathCore(row + 1, col, str, pathLength);
        if(!haspath)
        {
            --pathLength;
            visited[row * 4 + col] = 0;
        }
    }
    return haspath;
}

bool func(int row, int col, string& str)
{
    if(row <= 0 || col <= 0 || str.length() == 0)
        return false;
    const char *ptr = str.c_str();
    int pathLength = 0;
    for(int i = 0; i< row; ++i)
    {
        for(int j = 0; j < col; ++ j)
        {
            if(hasPathCore(i, j, ptr, pathLength))
                return true;
        }
    }
    return false;
}


int main()
{
    string str{"abfc"};
    cout<<func(3, 4, str);
    return 0;

}

