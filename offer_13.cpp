//
// Created by soft01 on 2019/9/27.
//

#include <vector>
#include <iostream>

using namespace std;
//机器人的运动范围
//20 * 20
vector<char> arr(400, 0);
vector<bool> visited(400, 0);

int getDigitSum(int number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number % 10;
        number /= 10;
    }
    return sum;
}

bool check(int rows, int cols, int row, int col, int k)
{
    if(row >= 0 && row < rows && col >= 0 && col < cols && getDigitSum(row) + getDigitSum(col) <= k && !visited[row * cols + col])
        return true;
    return false;
}

int movingCountCore(int rows, int cols, int row, int col, int k)
{
    int count = 0;
    if(check(rows, cols, row, col, k))
    {
        visited[row * cols + col] = true;
        count = 1 + movingCountCore(rows, cols, row - 1, col, k) +
                movingCountCore(rows, cols, row + 1, col, k) +
                movingCountCore(rows, cols, row, col - 1, k) +
                movingCountCore(rows, cols, row, col + 1, k);
    }
    return count;
}

int movingCount(int row, int col, int k)
{
    if(k < 0 || row <= 0 || col <= 0)
        return 0;
    int count = movingCountCore(row, col, 0, 0, k);
    return count;
}

int main()
{
    cout<<movingCount(20, 20, 15);
    return 0;
}
