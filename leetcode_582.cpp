//
// Created by soft01 on 2019/9/10.
//

#include <vector>
#include <queue>
#include <list>
#include <map>
#include <iostream>

using namespace std;

map<int, list<int>> tree;

void makeTree(const vector<int>& pid, const vector<int>& ppid)
{
    auto pit = pid.begin();
    auto ppit = ppid.begin();
    for(; pit != pid.end(), ppit != ppid.end(); ++pit, ++ ppit)
    {
        if(tree.find(*ppit) == tree.end())
        {
            tree.insert(make_pair(*ppit, std::list<int>()));
        }
        tree[*ppit].emplace_back(*pit);
    }
}

std::vector<int> kill(int num)
{
    queue<int> l;
    vector<int> res;
    l.emplace(num);
    while(l.size() > 0)
    {
        int id = l.front();
        l.pop();
        auto it = tree.find(id);
        if(it == tree.end())
        {
            res.emplace_back(id);
        }
        else
        {
            res.emplace_back(id);
            for(auto i = it->second.begin(); i != it->second.end(); ++i)
            {

                l.emplace(*i);
            }
        }
    }
    return res;
}


int main()
{
    vector<int> pid{1, 3, 10, 5};
    vector<int> ppid{3, 0, 5, 3};
    makeTree(pid, ppid);
    auto i = kill(5);
    for(auto& j : i)
        cout<<j<<endl;

    return 0;
}

