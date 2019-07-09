#include "tools.h"
#include "merge_sort.h"


int main(int argc, char const *argv[])
{
    int d3[] = {10,25,68,985,22,452,656,84,12,45,78,5,78,12,45,78,45,12,455};
    merge_sort(d3, 0, 18);
    for(int i = 0; i < 19; ++i)
        cout<<d3[i]<<" ";
    cout<<endl;
    return 0;
}
