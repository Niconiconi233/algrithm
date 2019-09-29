//
// Created by soft01 on 2019/9/25.
//

#include <iostream>
using namespace std;

//斐波那锲数列

template<int N>
class a
{
public:
    enum {res = a<N-1>::res + a<N-2>::res};
};

template<>
class a<1>
{
public:
    enum {res = 1};
};

template<>
class a<2>
{
public:
    enum {res = 1};
};

int arr[50] = {0};

int func(int n)
{
    if(n <= 0)
        return 0;
    if(n == 1)
        return 1;
    if(arr[n] != 0)
        return arr[n];
    else
    {
        arr[n] = func(n - 1) + func(n - 2);
        return arr[n];
        //return func(n - 1) + func(n - 2);
    }
}

int main()
{
    auto i = a<46>::res;
    cout<<i<<endl;
    cout<<func(46)<<endl;


    return 0;
}

