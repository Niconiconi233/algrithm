//
// Created by soft01 on 19-7-6.
//

/*
 * 动态规划
 * 1.带备忘的自顶向下法 任按自然的递归 但在过程中会保存子问题的解
 * 2.自底向上法 使任何子问题的求解都只依赖于更小的子问题的求解，结果已保存，每个子问题只需要求解一次
 *
 *
 */
#include "tools.h"

int arr[] = {0, 1, 5, 8, 9, 10, 17, 17, 20, 24, 30};


int cut_rod(int n)
{
    if(n <= 0)
        return 0;
    int res = 0;
    for(int i = 1; i <= n; ++i)
        res = max(res, arr[i] + cut_rod(n - i));
    return res;
}

//自顶向下
int memoized_cut_rod_aux(int len, int* arr);

int memoized_cut_rod(int len)
{
    //辅助数组
    int* arr_ = static_cast<int*>(malloc(sizeof(int) * len + 1));
    //bzero(arr, sizeof(int) * len + 1);
    for(int i = 0; i <= len; ++i)
        arr_[i] = -1;

    int res = memoized_cut_rod_aux(len, arr_);
    free(arr_);
    return res;
}

int memoized_cut_rod_aux(int n, int* arr_)
{
    if(arr_[n] >= 0)//判断是否已有记录
        return arr_[n];
    int q = 0;
    if(n == 0)
        q = 0;
    else
    {
        q = -1;
        for(int i = 1; i <= n; ++i)
            q = max(q, arr[i] + memoized_cut_rod_aux(n - i, arr_));//递归求解
    }
    arr_[n] = q;
    return q;
}

//自底向上
int bottom_cut_rod(int len)
{
    int* arr_ = static_cast<int*>(malloc(sizeof(int) * len + 1));
    arr_[0] = 0;
    for(int i = 1; i <= len; ++i)
    {
        int q = 0;
        for(int j = 1; j <= i; ++j)
        {
            q = max(q, arr[j] + arr_[i - j]);
        }
        arr_[i] = q;

    }
    return arr_[len];
}



int main()
{

    int len;
    std::cin>>len;
    //int res = cut_rod(len);
    //int res = memoized_cut_rod(len);
    int res = bottom_cut_rod(len);
    std::cout<<res<<std::endl;

}

