//
// Created by soft01 on 2019/9/25.
//

#include <vector>
#include <iostream>

using namespace std;
//根据先序和中序重建树
void func1_(vector<int>& pre, vector<int>& mid, int, int, int, int);

void func1(vector<int>& pre, vector<int>& mid)
{
    if(pre.size() == 0 || mid.size() == 0)
        return;
    func1_(pre, mid, 0, pre.size() - 1, 0, mid.size() - 1);
}

void func1_(vector<int>& pre, vector<int>& mid, int ps, int pe, int ms, int me)
{
    int root = pre[0];
    //new node
    if(ms == me && pre[ps] == mid[ms])
        return node;
    else
        throw std::exception("invaild input");
    int rootinorder = ms;
    while(ms < me && mid[rootinorder] != root)
        ++rootinorder;
    if(rootinorder == me && mid[rootinorder] != root)
        throw std::exception("invaild input");
    int leftlength = rootinorder - ms;
    if(leftlength > 0)
    {
        node->left = func1_(pre, mid, ps + 1, ps + leftlength, ms, rootinorder - 1);
    }
    if(leftlength < pe - ps)//有右子树
    {
        node->right = func1_(pre, mid, ps + leftlength + 1, pe, rootinorder + 1, me);
    }
    return node;
}



int main()
{
    vector<int> preorder{1,2,4,7,3,5,6,8};
    vector<int> midorder{4,7,2,1,5,3,8,6};



    return 0;
}

