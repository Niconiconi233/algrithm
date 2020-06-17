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
	//˫��ӳ��
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
	//����
	for (auto& i : map_1)
	{
		ComplexListNode* newNode = i.first;
		ComplexListNode* oldNode = i.second;
		if (oldNode->sibling != nullptr)//����ɽڵ�sibling����
		{
			auto it = map_2.find(oldNode->sibling);
			newNode->sibling = it->second;//���½ڵ��Ͻ�������
		}
	}
}

//sulotion_2
//�����ڵ� �½ڵ��ھɽڵ�֮��
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

//�ؽ�����ָ��
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

//�и�����
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