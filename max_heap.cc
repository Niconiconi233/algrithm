#include "tools.h"
#include "max_heap.hpp"

int main(int argc, char const *argv[])
{
    int d3[] = {10,25,68,985,22,452,656,84,102,45,78,5,708,102,405,781,504,12,455};
    auto heap = MaxHeap<int>::makeHeap(d3, 19);
    cout<<heap.size()<<endl;
    while(heap.size())
    {
        cout<<heap.getMax()<<" ";
    }
    cout<<endl;



    return 0;
}
