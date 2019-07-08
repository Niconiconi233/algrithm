#include "tools.h"
#include "queue.hpp"


int main(int argc, char const *argv[])
{
    Queue<int> queue;
    for(int i = 0; i < 1000; ++i)
        queue.enQueue(i);
    for(int i = 0; i < 600; ++i)
        cout<<queue.DeQueue()<<" ";
    cout<<endl;
    for(int i = 0; i < 1000; ++i)
        queue.enQueue(i);
    for(int i = 0; i < 1400; ++i)
        cout<<queue.DeQueue()<<" ";
    cout<<endl;
    return 0;
}

