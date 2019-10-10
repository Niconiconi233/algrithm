//
// Created by soft01 on 2019/10/9.
//

#include <iostream>
#include <vector>
using namespace std;

int findMaxSum(vector<int>& data)
{
    if(data.size() == 0)
        return 0;
    int max = 0;
    int sum = 0;
    for(auto& i :  data)
    {
        sum += i;
        if(sum <= 0)
            sum = 0;
        max = ::max(sum, max);
    }
    return max;
}

int main()
{
    vector<int> data{1,-2,3,10,-4,7,2,-5};
    cout<<findMaxSum(data);
    return 0;
}

