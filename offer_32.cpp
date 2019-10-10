#include <iostream>
#include <queue>
#include <deque>
using namespace std;

#include "binaryTree.h"

//层序打印
void printFromTopToBottom(BinaryTree<int>::BinaryNode* head)
{
	if (head == nullptr)
		return;
	queue<BinaryNode<int>*> queue_;
	queue_.emplace(head);
	//int flag = 1;
	//int flag1 = flag;
	while (!queue_.empty())
	{
		auto ptr = queue_.front();
		queue_.pop();
		cout << ptr->value << " ";
		//if (--flag1 == 0)
		//{
		//	cout << endl;
		//	flag *= 2;
		//	flag1 = flag;
		//}
		if (ptr->left != nullptr)
			queue_.emplace(ptr->left);
		if (ptr->right != nullptr)
			queue_.emplace(ptr->right);
	}
}

//之字形打印
void printFromTopToBottom2(BinaryTree<int>::BinaryNode* head)
{
	if (head == nullptr)
		return;
	deque<BinaryNode<int>*> deque_;
	bool toright = true;
	deque_.emplace_back(head);
	while (!deque_.empty())
	{
		if (toright)
		{
			deque<BinaryNode<int>*> tmp;
			for (auto& i : deque_)
			{
				cout << i->value << " ";
				if (i->left != nullptr)
					tmp.emplace_front(i->left);
				if (i->right != nullptr)
					tmp.emplace_front(i->right);
			}
			toright = false;
			deque_.swap(tmp);
		}
		else
		{
			deque<BinaryNode<int>*> tmp;
			for (auto& i : deque_)
			{
				cout << i->value << " ";
				if (i->right != nullptr)
					tmp.emplace_front(i->right);
				if (i->left != nullptr)
					tmp.emplace_front(i->left);
			}
			toright = true;
			deque_.swap(tmp);
		}
	}

}




/*int main()
{
	BinaryTree<int> tree{ 8,6,10,5,7,9,11 };

	auto head = tree.getHead();
	printFromTopToBottom(head);
	cout << endl;
	BinaryTree<int> tree1{ 8, 9, 10, 11, 12, 13 };
	auto head1 = tree1.getHead();
	printFromTopToBottom(head1);
	cout << endl;
	printFromTopToBottom(nullptr);
	cout << "\r之字形打印\r" << endl;
	printFromTopToBottom2(head);
	cout << endl;
	printFromTopToBottom2(head1);
	cout << endl;
	return 0;
}*/