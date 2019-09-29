//
// Created by soft01 on 2019/9/27.
//
#include <iostream>

using namespace std;

bool g_InvaildInput = false;

bool equal(double num1,double num2)
{
    if((num1-num2>-0.000001)&&(num1-num2)<0.000001)
        return true;
    else
        return false;
}

double powerWithUnsignedExponent_sulotion1(double base, unsigned int exponent)
{
    double result = 1.0;
    for(size_t i = 1; i<= exponent; ++i)
        result *= base;
    return result;
}

double Power(double base, int exponent)
{
    g_InvaildInput = false;
    if(equal(base, 0.0) && exponent < 0)
    {
        g_InvaildInput = true;
        return 0.0;
    }
    unsigned int absExponent = (unsigned int)(exponent);
    if(exponent < 0)
        absExponent = (unsigned int)(-exponent);
    //处理无符号的 对于负数只需要用1除就行了
    double result = powerWithUnsignedExponent_sulotion1(base, absExponent);
    if(exponent < 0)
        result = 1.0 / result;
    return result;
}

double powerWithUnsignedExponent_sulotion2(double base, unsigned int exponent)
{
    if(exponent == 0)
        return 1;
    if(exponent == 1)
        return base;
    double result = powerWithUnsignedExponent_sulotion2(base, exponent >> 1);
    result *= result;
    if(exponent & 0x1 == 1)//?
        result *= base;

    return result;
}

int main()
{
    cout<<Power(2, 10)<<endl;
    cout<<powerWithUnsignedExponent_sulotion2(2, 10)<<endl;
    //cout<<Power(2, 10)<<endl;
    return 0;
}
