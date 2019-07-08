#include "tools.h"

int func(int* arr, size_t len)
{
    int res = 0, sum = 0;
    size_t left = 0, right = 0;
    for(int i = 0; i < len; ++i)
    {
        sum += arr[i];
        if(sum > 0)
        {
            int tmp = max(sum, res);
            if(tmp > res)
            {
                right = i;
                res = tmp;
            }
        }else
        {
            left = i + 1;
            sum = 0;
        }
    }
    cout<<left << " " << right <<endl;
    return res;
}

int main(int argc, char const *argv[])
{
    int d3[] = {13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-4,7};
    cout<<func(d3, 16);
    return 0;
}
