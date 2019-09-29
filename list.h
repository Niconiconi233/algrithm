#pragma once
#include <initializer_list>

struct ListNode
{
	int value;
	ListNode* next;
};

class SimpleList
{
public:
	SimpleList(int size)
	{
		ListNode* end = nullptr;
		for (int i = 0; i < size; ++i)
		{
			ListNode* node = new ListNode;
			node->value = i;
			node->next = nullptr;
			if (head == nullptr)
			{
				head = node;
				end = head;
			}
			else
			{
				end->next = node;
				end = node;
			}
		}
	}

	SimpleList(std::initializer_list<int>&& list)
	{
		ListNode* end = nullptr;
		for (auto& i : list)
		{
			ListNode* node = new ListNode;
			node->value = i;
			node->next = nullptr;
			if (head == nullptr)
			{
				head = node;
				end = head;
			}
			else
			{
				end->next = node;
				end = node;
			}
		}
	}


	~SimpleList()
	{
		if (head != nullptr)
		{
			ListNode* pre = head;
			ListNode* node = head;
			node = node->next;
			while (node != nullptr)
			{
				delete pre;
				pre = node;
				node = node->next;
			}
			delete pre;
		}

	}

	ListNode* getHead()
	{
		return head;
	}

	void setHead(ListNode* newhead)
	{
		head = newhead;
	}


private:
	ListNode* head{ nullptr };
};
