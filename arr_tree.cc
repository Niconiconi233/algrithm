#include "arr_tree.hpp"

int main(int argc, char const *argv[])
{
    Arr_tree<int> tree;
    for(int i = 0; i < 25; ++i)
        tree.insert(i);
    tree.first();
    cout<<endl;
    tree.first1();
    cout<<endl;

    tree.mid();
    cout<<endl;
    tree.mid1();
    cout<<endl;
    tree.last();
    cout<<endl;
    tree.last1();
    cout<<endl;

    return 0;
}
