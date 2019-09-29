#include <iostream>

using namespace std;

#include "list.h"


SimpleList g_list(10);

void reverseList()
{
	ListNode* list = g_list.getHead();
	if (list == nullptr)
		throw exception("invaild list");
	ListNode* pre = list;
	ListNode* cur = list;
	//ListNode* nxt = list;
	cur = pre->next;
	pre->next = nullptr;
	while (cur != nullptr)
	{
		ListNode* nxt = cur->next;
		cur->next = pre;
		pre = cur;
		cur = nxt;
	}
	g_list.setHead(pre);
}

int main()
{
	reverseList();
	auto i = g_list.getHead();
	while (i != nullptr)
	{
		cout << i->value << " ";
		i = i->next;
	}
}