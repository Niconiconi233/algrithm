#include <iostream>
#include <map>

using namespace std;

struct ComplexListNode
{
	int value;
	ComplexListNode* next;
	ComplexListNode* sibling;
};

ComplexListNode* root{ nullptr };

void sulotion_1()
{
	if (root == nullptr)
		return;
	ComplexListNode* ptr = root;
	ComplexListNode* clone = nullptr;
	ComplexListNode* cloneHead = nullptr;
	//双向映射
	map<ComplexListNode*, ComplexListNode*> map_1;
	map<ComplexListNode*, ComplexListNode*> map_2;
	while (ptr != nullptr)
	{
		ComplexListNode* tmp = new ComplexListNode;
		tmp->value = ptr->value;
		tmp->next = nullptr;
		tmp->sibling = nullptr;
		if (cloneHead == nullptr)
		{
			cloneHead = tmp;
			clone = tmp;
			map_1[tmp] = ptr;//newnode->oldnode
			map_2[ptr] = tmp;//oldnode->newnode
		}
		else
		{
			clone->next = tmp;
			clone = tmp;
			map_1[tmp] = ptr;
			map_2[ptr] = tmp;
		}
		ptr = ptr->next;
	}
	clone = cloneHead;
	//遍历
	for (auto& i : map_1)
	{
		ComplexListNode* newNode = i.first;
		ComplexListNode* oldNode = i.second;
		if (oldNode->sibling != nullptr)//如果旧节点sibling存在
		{
			auto it = map_2.find(oldNode->sibling);
			newNode->sibling = it->second;//在新节点上建立连接
		}
	}
}

//sulotion_2
//创建节点 新节点在旧节点之后
void cloneNode(ComplexListNode* root)
{
	if (root == nullptr)
		return;
	ComplexListNode* ptr = root;
	while (ptr != nullptr)
	{
		ComplexListNode* tmp = new ComplexListNode;
		tmp->value = ptr->value;
		tmp->next = ptr->next;
		tmp->sibling = nullptr;
		ptr->next = tmp;

		ptr = tmp->next;
	}
}

//重建链表指针
void connectSiblingNode(ComplexListNode* root)
{
	ComplexListNode* ptr = root;
	while (ptr != nullptr)
	{
		if (ptr->sibling != nullptr)
		{
			ComplexListNode* si = ptr->sibling;
			ptr->next->sibling = si->next;
		}
		ptr = ptr->next->next;
	}
}

//切割链表
ComplexListNode* spliceList(ComplexListNode* root)
{
	if (root == nullptr)
		return nullptr;
	ComplexListNode* ptr = root;
	ComplexListNode* pclone = nullptr;
	ComplexListNode* pcloneHead = nullptr;

	pclone = root->next;
	pcloneHead = root->next;
	ptr->next = pclone->next;
	ptr = pclone->next;


	while (ptr != nullptr)
	{
		pclone->next = ptr->next;
		pclone = pclone->next;
		ptr->next = pclone->next;
		ptr = ptr->next;
	}
	return pcloneHead;
}

int main()
{
	return 0;
}