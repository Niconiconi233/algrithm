#include "tools.h"
#include "huffman.hpp"

int main()
{
    huffman<char> tree;
    std::vector<std::pair<char, int>> item;
    item.push_back(std::pair<char, int>('f', 5));
    item.push_back(std::pair<char, int>('e', 9));
    item.push_back(std::pair<char, int>('c', 12));
    item.push_back(std::pair<char, int>('b', 13));
    item.push_back(std::pair<char, int>('d', 16));
    item.push_back(std::pair<char, int>('a', 45));
    tree.makeHuffMan(item);
    tree.first();
    cout<<endl;
    tree.mid();
    cout<<endl;
    tree.last();
    cout<<endl;
    auto map = tree.getHuffManCode();
    for(auto i : map)
        cout<<i.first<<" "<<i.second<<endl;

    return 0;


}



