#include <iostream>

using namespace std;

//获取链表环的入口节点
struct ListNode
{
	int value;
	ListNode* next;
};

ListNode* head = nullptr;

void createList()
{
	ListNode* end = nullptr;
	ListNode* circle = nullptr;
	for (int i = 0; i < 10; ++i)
	{
		ListNode* node = new ListNode;
		node->value = i;
		node->next = nullptr;
		if (i == 3)
			circle = node;
		if (head == nullptr)
		{
			head = node;
			end = node;
		}
		else
		{
			end->next = node;
			end = node;
		}
	}
	end->next = circle;
}

void deleteList()
{
	if (head == nullptr)
		return;
	ListNode* node = head;
	ListNode* pre = node;
	node = node->next;
	int i = 0;
	while (node != nullptr)
	{
		++i;
		pre->next = nullptr;
		delete pre;
		pre = node;
		node = node->next;
	}
	cout << i << endl;
}

//获取相遇节点
ListNode* meetingNode()
{
	if (head == nullptr)
		return nullptr;
	ListNode* ptr1 = head;
	ListNode* ptr2 = head;
	ptr2 = ptr2->next;

	while (ptr2 != nullptr && ptr1 != nullptr)
	{
		if (ptr1 == ptr2)
			return ptr1;
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
		if (ptr2 != nullptr)
			ptr2 = ptr2->next;
	}
	return nullptr;
}

ListNode* entryNode()
{
	ListNode* node = meetingNode();
	if (node == nullptr)
		return nullptr;
	ListNode* ptr = node;
	int count = 1;
	//计算环节点数量
	while (ptr->next != node)
	{
		++count;
		ptr = ptr->next;
	}
	ListNode* ptr1 = head;
	ListNode* ptr2 = head;
	//快慢指针 相遇在头节点
	for (int i = 0; i < count; ++i)
		ptr1 = ptr1->next;
	while (ptr1 != ptr2)
	{
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}
	return ptr1;
}


/*int main()
{
	createList();
	//deleteList();
	cout << meetingNode()->value << endl;
	cout << entryNode()->value << endl;
	return 0;
}*/