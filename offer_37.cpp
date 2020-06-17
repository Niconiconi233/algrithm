#include <iostream>
#include <string>
using namespace std;

#include "binaryTree.h"
//序列化和反序列化二叉树

void Serialize(BinaryNode<int>* root, string& str)
{
	if (root == nullptr)
	{
		str.append("$");
		return;
	}
	char ch = root->value + '0';
	str.push_back(ch);
	Serialize(root->left, str);
	Serialize(root->right, str);
}

bool ReadStream(string& str, int& number)
{
	const char ch = str.back();
	if (ch >= '0' && ch <= '9')
	{
		number = atoi(&ch);
		str.pop_back();
		return true;
	}
	else
	{
		str.pop_back();
		return false;
	}
}

void Desserialize(BinaryNode<int>** root, string& str)
{
	int number = 0;
	if (ReadStream(str, number))
	{
		*root = new BinaryNode<int>;
		(*root)->value = number;
		(*root)->left = nullptr;
		(*root)->right = nullptr;

		Desserialize(&((*root)->left), str);
		Desserialize(&((*root)->right), str);
	}
}

int main()
{
	BinaryTree<int> tree{ 6, 4, 3, 7, 8, 9 };
	string str;
	Serialize(tree.getHead(), str);
	reverse(str.begin(), str.end());
	cout << str;

	return 0;
}