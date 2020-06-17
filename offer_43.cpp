//
// Created by soft01 on 2019/10/9.
//
#include <iostream>
#include <cmath>
using namespace std;

//m 为 权
//num 为0时为10^(m - 2) + 1;
//大于0时 计算方法为 num * (n - 1) * 10 ^ (m - 2) + 1;

int numberOf1(unsigned int n)
{
    int number = n;
    int count = 0;
    int m = 1;
    while(number)
    {
        int num = number % 10;
        if(num == 0)
            num = 1;
        number /= 10;
        count += num * (m - 1) * pow(10, m - 2) + 1;
        m += 1;
    }
    return count;
}

int main()
{
    cout<<numberOf1(21345);
    return 0;
}

