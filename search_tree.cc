#include "tools.h"
#include "search_tree.hpp"

int main(int argc, char const *argv[])
{
    Search_tree<int> tree;
    tree.insert(50);
    tree.insert(38);
    tree.insert(70);
    tree.insert(30);
    tree.insert(45);
    tree.insert(40);
    tree.insert(48);
    tree.insert(60);
    tree.insert(75);
    tree.insert(80);
//    tree.first();
//    cout<<endl;
//    tree.first1();
//    cout<<endl;
//    tree.mid();
//    cout<<endl;
//    tree.mid1();
//    cout<<endl;
//    tree.last();
//    cout<<endl;
//    tree.last1();
//    cout<<endl;
//    tree.erase(50);

    cout<<tree.getMax()<<endl;
    cout<<tree.getMin()<<endl;


    return 0;
}