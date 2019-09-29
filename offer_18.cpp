#include <iostream>

using namespace std;

struct ListNode
{
	int m_value;
	ListNode* m_next;
};

void deleteNode(ListNode** head, ListNode* toDeleted)
{
	if (head == nullptr || toDeleted == nullptr)
		return;
	if (toDeleted->m_next != nullptr)//后面的值覆盖前面的值，省去了查找
	{
		ListNode* next = toDeleted->m_next;
		toDeleted->m_value = next->m_value;
		toDeleted->m_next = next->m_next;

		delete next;
		next = nullptr;
	}
	else if (*head == toDeleted)//只有一个节点
	{
		delete toDeleted;
		*head = nullptr;
		toDeleted = nullptr;
	}
	else//多个节点，同时在末尾 需要顺序查找 
	{
		ListNode* ptr = *head;
		while (ptr->m_next != toDeleted)
		{
			ptr = ptr->m_next;
		}
		ptr->m_next = nullptr;
		delete toDeleted;
		toDeleted = nullptr;
	}
}

//删除值连续的节点
void deleteDuplication(ListNode** head)
{
	if (*head == nullptr || head == nullptr)
		return;
	ListNode* preNode = nullptr;
	ListNode* Node = *head;
	while (Node != nullptr)
	{
		ListNode* pNext = Node->m_next;
		bool needDelete = false;
		if (pNext != nullptr && pNext->m_value == Node->m_value)//连续节点
			needDelete = true;

		if (!needDelete)
		{
			preNode = Node;
			Node = Node->m_next;
		}
		else
		{
			int value = Node->m_value;
			ListNode* toBeDelete = Node;
			while (toBeDelete != nullptr && toBeDelete->m_value == value)//一旦有相同的，全部删除
			{
				pNext = toBeDelete->m_next;
				delete toBeDelete;
				toBeDelete = nullptr;
				toBeDelete = pNext;
			}
			if (preNode == nullptr)//头结点重复
				*head = pNext;
			else
				preNode->m_next = pNext;
			Node = pNext;
		}
	}
}



/*int main()
{
	
	return 0;
}*/