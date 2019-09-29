#include "tools.h"
#include "merge_sort.h"
#include "merge_sort_thread.h"
#include <chrono>

int main(int argc, char const *argv[])
{
    int d3[] = {2,3,1,6,8,10,20,4,7, 200, 300, 102, 233, 523, 562, 145, 82, 10, 23, 150, 523, 222};
    int d4[] = {2,3,1,6,8,10,20,4,7, 200, 300, 102, 233, 523, 562, 145, 82, 10, 23, 150, 523, 222};
    auto beg = std::chrono::high_resolution_clock::now();
    merge_sort(d3, 0, 21);
    auto end = std::chrono::high_resolution_clock::now();
    for(int i = 0; i < 22; ++i)
        cout<<d3[i]<<" ";
    std::chrono::duration<double, std::micro> diff(end - beg);
    std::cout<<std::endl;
    std::cout<<diff.count()<<std::endl;
    beg = std::chrono::high_resolution_clock::now();
    merge_sort_with_thread(d4, 0, 21);
    //sleep(5);
    for(int i = 0; i < 22; ++i)
        cout<<d4[i]<<" ";
    end = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::micro> diff2(end - beg);
    std::cout<<std::endl;
    std::cout<<diff2.count()<<std::endl;
    return 0;
}
