//
// Created by soft01 on 2019/9/27.
//
#include <iostream>

using namespace std;
//i的个数
int numberOf1_sulotion1(int number)
{
    int count = 0;
    unsigned int flag = 1;
    while(flag)
    {
        if(flag & number)
            ++count;
        flag <<= 1;
    }
    return count;
}

int numberOf1_solution2(int number)
{
    int count = 0;
    while(number)
    {
        ++count;
        number = (number - 1) & number;
    }
    return count;
}

//相关题目
//判断2的倍数
bool sulotion(int number)
{
    if(number == 0)
        return false;
    //return (number &= (number - 1)) == 0;
    return (number & (number - 1)) == 0;
}

//输入两个整数计算需要改变m的二进制位多少位才能得到n
int sulotion2(int m, int n)
{
    auto i = m ^ n;
    return numberOf1_solution2(i);
}



int main()
{
    cout<<numberOf1_sulotion1(0x80000000)<<endl;
    cout<<numberOf1_solution2(0x80000000)<<endl;
    cout<<sulotion(3)<<endl;
    cout<<sulotion2(10, 13)<<endl;
    return 0;
}

