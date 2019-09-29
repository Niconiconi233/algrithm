//
// Created by soft01 on 19-7-15.
//
#include "tools.h"

/*
 * 欧几里得算法 求最大公约数
 */
int EUCLID(int a, int b)
{
    if(b == 0)
        return a;
    else return EUCLID(b, a % b);
}


int main()
{
    cout<<EUCLID(99, 78);
}

