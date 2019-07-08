#include "tools.h"
#include "list.hpp"

int main(int argc, char const *argv[])
{
    {
    List<int> list;
    for(int i = 0; i < 10000000; ++i)
    {
        list.push_back(i);
    }
    list.pr();
    }
//    list.erase(5);
//    list.insert(233, 5);
//    cout<<list[list.find(2333)]<<endl;
//    for(int i = 0; i < list.size(); ++i)
//       cout<<list[i]<<" ";
//   cout<<endl;
    return 0;
}
