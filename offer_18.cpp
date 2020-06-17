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
	if (toDeleted->m_next != nullptr)//�����ֵ����ǰ���ֵ��ʡȥ�˲���
	{
		ListNode* next = toDeleted->m_next;
		toDeleted->m_value = next->m_value;
		toDeleted->m_next = next->m_next;

		delete next;
		next = nullptr;
	}
	else if (*head == toDeleted)//ֻ��һ���ڵ�
	{
		delete toDeleted;
		*head = nullptr;
		toDeleted = nullptr;
	}
	else//����ڵ㣬ͬʱ��ĩβ ��Ҫ˳����� 
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

//ɾ��ֵ�����Ľڵ�
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
		if (pNext != nullptr && pNext->m_value == Node->m_value)//�����ڵ�
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
			while (toBeDelete != nullptr && toBeDelete->m_value == value)//һ������ͬ�ģ�ȫ��ɾ��
			{
				pNext = toBeDelete->m_next;
				delete toBeDelete;
				toBeDelete = nullptr;
				toBeDelete = pNext;
			}
			if (preNode == nullptr)//ͷ����ظ�
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