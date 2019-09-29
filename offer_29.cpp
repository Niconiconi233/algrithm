//
// Created by soft01 on 2019/9/29.
//
#include <iostream>
using namespace std;

void printMatrixInCircle(int**, int, int, int);

void printMatrixClockwisely(int **numbers, int col, int row)
{
    if(numbers == nullptr || clo <= 0 || row <= 0)
        return;
    int start = 0;
    while(clo > start * 2 && row > start * 2)
    {
        printMatrixInCircle(numbers, col, row, start);
        ++start;
    }
}

void printMatrixInCircle(int** numbers, int col, int row, int start)
{
    int endx = col - 1 - start;
    int endy = row - 1 - start;

    for(int i = start, i < endx; ++i)
    {
        cout<<numbers[start][i] << " ";
    }
    //向下打印必要条件
    if(start < endy)
    {
        for(int i = start + 1; i < endy; ++i)
        {
            cout<<numbers[i][endy] << " ";
        }
    }
    //向右打印必要条件
    if(start < endx && start < endy)
    {
        for(int i = endx - 1; i >= start; --i)
        {
            cout<<numbers[endy][i] << " ";
        }
    }
    //向上打印必要条件
    if(start < endx && start < endy - 1)
    {
        for(int i = endy - 1; i >= start; --i)
        {
            cout<<numbers[i][start]<<" ";
        }
    }
}

