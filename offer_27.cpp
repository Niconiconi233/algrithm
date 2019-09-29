//
// Created by soft01 on 2019/9/29.
//
//二叉树的镜像
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

void mirrowRecursively(BinaryTreeNode* root)
{
    if(root == nullptr)
        return;
    if(root->left == nullptr || root->right == nullptr)
        return;
    swap(root->left->value, root->right->value);
    if(root->left)
        mirrowRecursively(root->left);
    if(root->right)
        mirrowRecursively(root->right);
}

