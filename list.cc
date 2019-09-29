#include "tools.h"
#include "list.hpp"


int main(int argc, char const *argv[])
{
    {
    List<int> list;
    for(int i = 0; i < 10; ++i)
    {
        list.push_back(i);
    }
    list.pr();
    list.reverse();
    list.pr();

    }
    return 0;
}
