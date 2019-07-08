#include "tools.h"
#include "quick_sort.h"

int main(int argc, char const *argv[])
{
    int d3[] = {150,25,68,985,22,452,656,84,102,45,78,5,708,12,405,781,504,12,455};
    size_t len = sizeof(d3)/sizeof(d3[0]) - 1;
    quick_sort(d3, 0, len);
    //partition(d3, 0, len);
    //quicksort(d3, 0, len);
    arr_print(d3, len);
    return 0;
}


