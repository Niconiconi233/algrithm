#include <iostream>
#include <vector>
using namespace std;

#include "binaryTree.h"

//二叉树中和为某一值的路径
void findPath(BinaryNode<int>*, vector<int>&, int, int);

void findPath(int expectedSum)
{
	BinaryTree<int> tree{ 10,5,12,4,7 };
	auto root = tree.getHead();
	vector<int> path;
	int currSum = 0;
	findPath(root, path, expectedSum, currSum);
}

void findPath(BinaryNode<int>* root, vector<int>& path, int expectedSum, int currSum)
{
	if (expectedSum == 0 || root == nullptr)
		return;
	currSum += root->value;
	path.push_back(root->value);

	bool isLeaf = (root->left == nullptr && root->right == nullptr);
	if (currSum == expectedSum && isLeaf)
	{
		for (auto& i : path)
			cout << i << " ";
		cout << endl;
	}
	if (root->left != nullptr)
		findPath(root->left, path, expectedSum, currSum);
	if (root->right != nullptr)
		findPath(root->right, path, expectedSum, currSum);
	path.pop_back();
}


int main()
{
	findPath(15);
	return 0;
}
