//
// Created by soft01 on 2019/9/29.
//
struct BinaryTreeNode
{
    int value;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
};

bool isSymmetrical(BinaryTreeNode*, BinaryTreeNode*);

bool isSymmetrical(BinaryTreeNode* root)
{
    return isSymmetrical(root, root);
}

bool isSymmetrical(BinaryTreeNode* root1, BinaryTreeNode* root2)
{
    if(root1 == nullptr && root2 == nullptr)
        return true;
    if(root == nullptr || root2 == nullptr)
        return false;
    if(root1->value != root2->value)
        return false;
    return isSymmetrical(root1->left, root2->right) && isSymmetrical(root1->right, root2->left);
}

