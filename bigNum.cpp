//
// Created by soft01 on 19-7-15.
//
/*
 * 大数加法
 */

#include "tools.h"
#include <algorithm>

std::string bigNum(const std::string& num1, const std::string& num2)
{
    if(num1.length() == 0 || num2.length() == 0)
        return num1.length() == 0 ? num2 : num1;
    else if(num1.length() == 0 && num2.length() == 0)
        return std::string{};
    auto beg1 = num1.end() - 1;
    auto beg2 = num2.end() - 1;
    std::string res;
    bool flag = false;
    while(beg1 >= num1.begin() && beg2 >= num2.begin())
    {
        int tmp = 0;
        if(flag)
        {
            tmp = (*beg1 - '0') + (*beg2 - '0') + 1;
            flag = false;
        }
        else
            tmp =  (*beg1 - '0') + (*beg2 - '0');
        if(tmp >= 10)
        {
            flag = true;
            tmp -= 10;
        }
        char ch = tmp + '0';
        res.push_back(ch);
        --beg1;
        --beg2;
    }
    if(beg1 >= num1.begin())
    {
        for(; beg1 >= num1.begin(); --beg1)
        {
            if(flag)
            {
                int tmp = (*beg1 - '0') + 1;
                if(tmp >= 10)
                {
                    tmp -= 10;
                    res.push_back(tmp + '0');
                    flag = true;
                }else
                {
                    res.push_back(tmp + '0');
                    flag = false;
                }
            }else
            {
                res.push_back(*beg1);
            }
        }
    }
    if(beg2 >= num2.begin())
    {
        for(; beg2 >= num2.begin(); --beg2)
        {
            if(flag)
            {
                int tmp = (*beg2 - '0') + 1;
                if(tmp >= 10)
                {
                    tmp -= 10;
                    res.push_back(tmp + '0');
                    flag = true;
                }else
                {
                    res.push_back(tmp + '0');
                    flag = false;
                }
            }else
            {
                res.push_back(*beg2);
            }
        }
    }
    if(flag)
        res.push_back('1');
    std::reverse(res.begin(), res.end());
    res.append("\0");
    return res;

}

int main()
{
    std::string num1;
    std::string num2;
    std::cin >> num1;
    std::cin >> num2;
    cout<<bigNum(num1, num2);
    return 0;
}

