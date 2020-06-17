#include "binaryTree.h"

void ConvertNode(BinaryNode<int>* pNode, BinaryNode<int>** pLastNodeInList);

BinaryNode<int>* Convert(BinaryNode<int>* root)
{
	if (root == nullptr)
		return nullptr;
	BinaryNode<int>* pLastNodeList = nullptr;
	ConvertNode(root, &pLastNodeList);

	BinaryNode<int>* pHeadOfList = pLastNodeList;
	while (pHeadOfList != nullptr && pHeadOfList->left != nullptr)
		pHeadOfList = pHeadOfList->left;
	return pHeadOfList;
}

void ConvertNode(BinaryNode<int>* pNode, BinaryNode<int>** pLastNodeInList)
{
	if (pNode == nullptr)
		return;
	BinaryNode<int>* pCurrent = pNode;
	if (pCurrent->left != nullptr)
		ConvertNode(pCurrent->left, pLastNodeInList);//���������� pLastNodeInList�������������ҽڵ�

	pCurrent->left = *pLastNodeInList;//����˫������
	if (*pLastNodeInList != nullptr)
		(*pLastNodeInList)->right = pCurrent;
	*pLastNodeInList = pCurrent;//�������Ľڵ�
	if (pCurrent->right != nullptr)
		ConvertNode(pCurrent->right, pLastNodeInList);
}



/*void ConvertNode(BinaryNode<int>* pNode, BinaryNode<int>** pLastNode)
{
	if (pNode == nullptr)
		return;
	BinaryNode<int>* pCurrent = pNode;
	if (pCurrent->left != nullptr)
		ConvertNode(pCurrent->left, pLastNode);
	pCurrent->left = *pLastNode;
	if (*pLastNode != nullptr)
	{
		(*pLastNode)->right = pCurrent;
	}
	*pLastNode = pCurrent;
	if (pCurrent->right != nullptr)
		ConvertNode(pCurrent->right, pLastNode);
}*/


int main()
{
	BinaryTree<int> tree{ 10, 6, 4, 8, 14, 12, 16 };
	Convert(tree.getHead());

	return 0;
}