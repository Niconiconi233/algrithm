#include <iostream>
using namespace std;

#include "list.h"
//合并两个有序链表

SimpleList list1{ 1,3,5,7,9 };
SimpleList list2{ 2,4,6,8,10 };

ListNode* mergeList()
{
	ListNode* list1Ptr = list1.getHead();
	ListNode* list2Ptr = list2.getHead();

	if (list1Ptr == nullptr)
		return list2Ptr;
	if (list2Ptr == nullptr)
		return list1Ptr;

	ListNode* ptr = nullptr;
	ListNode* newhead = nullptr;
	if (list1Ptr->value < list2Ptr->value)
	{
		ptr = list1Ptr;
		list1Ptr = list1Ptr->next;
	}
	else
	{
		ptr = list2Ptr;
		list2Ptr = list2Ptr->next;
	}
	newhead = ptr;
	while (list1Ptr != nullptr && list2Ptr != nullptr)
	{
		if (list1Ptr->value < list2Ptr->value)
		{
			ptr->next = list1Ptr;
			list1Ptr = list1Ptr->next;
			ptr = ptr->next;
		}
		else
		{
			ptr->next = list2Ptr;
			list2Ptr = list2Ptr->next;
			ptr = ptr->next;
		}
	}
	if (list1Ptr != nullptr)
	{
		ptr->next = list1Ptr;

	}
	if (list2Ptr != nullptr)
	{
		ptr->next = list2Ptr;
	}
	if (newhead == list1.getHead())
		list2.setHead(nullptr);
	else
		list1.setHead(nullptr);
	return newhead;
}


int main()
{
	ListNode* head = mergeList();

	while (head != nullptr)
	{
		cout << head->value << " ";
		head = head->next;
	}


	return 0;
}