//
// Created by soft01 on 2019/9/29.
//
#include <iostream>

using namespace std;
//判断是否存在子树
struct BinaryTreeNode
{
    double valuel;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

bool equal(double num1,double num2)
{
    if((num1-num2>-0.000001)&&(num1-num2)<0.000001)
        return true;
    else
        return false;
}

bool DoesTree1HaveTree2(BinaryTreeNode*, BinaryTreeNode*);

bool hasSubTree(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    bool result = false;
    while(root1 != nullptr && root2 != nullptr)
    {
        if(equal(root1->valuel, root2->valuel))
        {
            return DoesTree1HaveTree2(root1, root2);
        }
        if(!result)
            result = hasSubTree(root1->left, root2);
        if(!result)
            result = hasSubTree(root1->right, root2);
    }
    return result;
}

bool DoesTree1HaveTree2(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if(root1 == nullptr)
        return false;
    if(root2 == nullptr)
        return false;
    if(!equal(root1->valuel, root2->valuel))
        return false;
    return DoesTree1HaveTree2(root1->left, root2->left) && DoesTree1HaveTree2(root1->right, root2->right);
}
