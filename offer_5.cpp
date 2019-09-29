//
// Created by soft01 on 2019/9/24.
//

#include <iostream>
using namespace std;

#include <string.h>

void func(char* str, int length)
{
    if(str == nullptr)
        return;
    int len = strlen(str);
    int cnt = 0;
    char* ptr = str;
    while(*ptr != '\0')
    {
        if(*ptr == ' ')
            ++cnt;
        ++ptr;
    }
    int newlen = len + cnt * 2;
    if(newlen > length)
        return;
    char* ptr2 = str + newlen;
    char* ptr1 = str + len;
    while(ptr1 >= str)
    {
        if(*ptr1 == ' ')
        {
            ptr2 -= 2;
            strncpy(ptr2--, "%20", 3);
        }else
        {
            *ptr2-- = *ptr1;
        }
        --ptr1;
        //--ptr2;
    }
}

void func2(int* arr1, int* arr2, int len1, int len2)
{
    if(arr1 == nullptr || arr2 == nullptr || len1 <= 0 || len2 <= 0)
        return;
    int newlen = len1 + len2 - 1;
    int l1 = len1 - 1;
    int l2 = len2 - 1;
    while(l1 >= 0 || l2 >= 0)
    {
        if(arr1[l1] > arr1[l2])
            arr1[newlen--] = arr1[l1--];
        else
            arr1[newlen--] = arr2[l2--];
    }
    if(l2 >= 0)
    {
        while(l2 >= 0)
            arr1[newlen--] = arr2[l2--];
    }


}

int main()
{
    char str[32] = {0};
    strcpy(str, "we are happy.");
    cout<<str<<endl;
    func(str, 32);
    cout<<str<<endl;

    char str1[32] = {0};
    strcpy(str1, " we are fuck you.");
    cout<<str1<<endl;
    func(str1, 32);
    cout<<str1<<endl;

    char str2[32] = {0};
    strcpy(str2, "wearefuckyou.");
    cout<<str2<<endl;
    func(str2, 32);
    cout<<str2<<endl;

    func(nullptr, 0);


    //相关题目

    int arr[20] = {1, 3, 5, 7, 9, 11};
    int arr2[] = {2, 4, 6, 8, 10};

    func2(arr, arr2, 6, 5);

    return 0;
}

