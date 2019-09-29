//
// Created by soft01 on 2019/9/25.
//

#include <iostream>

using namespace std;
//获取某节点中序遍历的下一节点
struct node
{
    int value;
    node* left;
    node* right;
    node* parent;
};

node* getNext(node* node)
{
    if(node == nullptr)
        return nullptr;
    node* res = nullptr;
    //有右子树，为右子树的最左子树
    if(node->right != nullptr)
    {
        res = node->right;
        while(res->left != nullptr)
            res = res->left;
        return res;
    }else if(node->parent != nullptr)
    //无右子树 -> 父节点
        //无右子树，且当前节点为父节点右子节点 一路向上找到一个是父节点的左子节点的节点
    {
        node* kid = node;
        node* parent = node->parent;
        while(parent != nullptr && kid == parent->right)
        {
            kid = parent;
            parent = parent->parent;
        }
        res = parent;
    }
    return res;
}