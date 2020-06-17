//
// Created by soft01 on 2019/10/9.
//
#include <set>
#include <iostream>
#include <vector>
using namespace std;
// top k
template<typename T>
struct smaller
{
    bool operator()(const T& lhs, const T& rhs)
    {
        return lhs < rhs;
    }
};

template<typename T>
struct bigger
{
    bool operator()(const T& lhs, const T& rhs)
    {
        return lhs > rhs;
    }
};

using intSet = set<int, greater<int> >;

void GetLeastNumber(const vector<int>& data, intSet& set, int k)
{
    set.clear();
    for(const auto& i : data)
    {
        if(set.size() < k)
            set.emplace(i);
        else
        {
            auto beg = set.begin();
            if(*beg > i)
            {
                set.erase(beg);
                set.emplace(i);
            }
        }
    }
}


int main()
{
    set<int, greater<int> > set;
    vector<int> data{1,2,3,4,5,6,7,8,9,10,11,22,343,5,6,7,8,563,534,23,54};
    GetLeastNumber(data, set, 5);
    for(const auto& i : set)
        cout<<i<<" ";
    return 0;
}


