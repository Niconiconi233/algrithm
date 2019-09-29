//
// Created by soft01 on 2019/9/27.
//

#include <iostream>
#include <vector>
using namespace std;

#include <cmath>

//f(n) = max(f(i)*f(n-i))
int maxProductAfterCutting_solution1(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;

    //int* products = new int[length + 1];
    vector<int> products(length, 0);
    products[0] = 0;
    products[1] = 1;
    products[2] = 2;
    products[3] = 3;

    int max = 0;

    for(int i = 4; i <= length; ++i)
    {
        max = 0;
        for(int j = 1; j <= i / 2; ++j)
        {
            int production = products[j] * products[i - j];
            if(production > max)
                max = production;
            products[i] = max;
        }
    }
    max = products[length];
    //delete[] products;
    return max;
}

//n>=5时 2(n-2)>n 3(n-3)>n 3(n-3)>2(n-2)
int maxProductAfterCutting_solution2(int length)
{
    if(length < 2)
        return 0;
    if(length == 2)
        return 1;
    if(length == 3)
        return 2;
    //尽可能多减取长度为3的长度
    int timesOf3 = length / 3;

    //当剩余长度为4时，不在减去3 2*2 > 1*3
    if(length - timesOf3 * 3 == 1)
        --timesOf3;
    int timesOf2 = (length - timesOf3 * 3) / 2;
    return std::pow(3, timesOf3) * pow(2, timesOf2);
}

int main()
{
    cout<<maxProductAfterCutting_solution1(8)<<endl;
    cout<<maxProductAfterCutting_solution2(8)<<endl;
    return 0;
}

