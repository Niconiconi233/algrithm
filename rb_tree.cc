#include "tools.h"
#include "rb_tree.hpp"

int main()
{
    rb_tree<int> tree;
    for(int i = 0; i < 10; ++i)
    {
        tree.insert(i);
    }

    tree.remove(5);

    //auto it = tree.find(5);

    return 0;
}

