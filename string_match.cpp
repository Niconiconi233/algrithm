//
// Created by soft01 on 19-7-15.
//

#include "tools.h"
#include <vector>

std::vector<size_t> naive_string_matcher(const std::string& t, const std::string& p)
{
    std::vector<size_t> res;
    size_t n = t.length();
    size_t m = p.length();
    for(size_t i = 0; i <= n - m; ++i)
    {
        if(p[0] == t[i])
        {
            size_t idx = i + 1;
            size_t j = 1;
            for(j = 1; j < m; ++j, ++idx)
            {
                if(p[j] != t[idx])
                    break;
                if(j + 1 == m)
                {
                    res.emplace_back(i);
                    i += m - 1;
                    break;
                }

            }
        }
    }
    return res;
}

int main()
{
    auto ve = naive_string_matcher("000010001010001", "0001");
    for(auto i : ve)
        cout<<i<<" ";
    cout<<endl;
}
