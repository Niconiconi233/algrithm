<<<<<<< HEAD
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> g_stack;

bool isOrder(vector<int>& push, vector<int>& pop)
{
	if (push.size() == 0 || pop.size() == 0)
		return false;
	auto push_begin = push.begin();
	auto push_end = push.end();
	auto pop_begin = pop.begin();
	auto pop_end = pop.end();
	auto pop_end1 = --pop_end;

	while (pop_begin < pop_end)
	{
		if (g_stack.size() > 0)
		{
			if (g_stack.top() != *pop_begin)
			{
				if (push_begin == push_end)
					break;
				while (*push_begin != *pop_begin && push_begin != push_end)
				{
					g_stack.emplace(*push_begin);
					++push_begin;
				}
				g_stack.emplace(*push_begin);
				++push_begin;
			}
			else
			{
				g_stack.pop();
				++pop_begin;
			}
		}
		else
		{
			if (push_begin == push_end)
				break;
			while (*push_begin != *pop_begin && push_begin != push_end)
			{
				g_stack.emplace(*push_begin);
				++push_begin;
			}
			g_stack.emplace(*push_begin);
			++push_begin;
		}
		if (pop_begin == pop_end1)
			return true;
	}
	return false;
}

/*int main()
{
	vector<int> push{1, 2, 3, 4, 5};
	vector<int> pop1{ 4,5,3,2,1 };
	vector<int> pop2{ 4,3,5,1,2 };
	cout << isOrder(push, pop1) << endl;
	while (g_stack.size() > 0)
		g_stack.pop();
	cout << isOrder(push, pop2) << endl;

	return 0;
=======
#include <vector>
#include <stack>
#include <iostream>

using namespace std;

stack<int> g_stack;

bool isOrder(vector<int>& push, vector<int>& pop)
{
	if (push.size() == 0 || pop.size() == 0)
		return false;
	auto push_begin = push.begin();
	auto push_end = push.end();
	auto pop_begin = pop.begin();
	auto pop_end = pop.end();
	auto pop_end1 = --pop_end;

	while (pop_begin < pop_end)
	{
		if (g_stack.size() > 0)
		{
			if (g_stack.top() != *pop_begin)
			{
				if (push_begin == push_end)
					break;
				while (*push_begin != *pop_begin && push_begin != push_end)
				{
					g_stack.emplace(*push_begin);
					++push_begin;
				}
				g_stack.emplace(*push_begin);
				++push_begin;
			}
			else
			{
				g_stack.pop();
				++pop_begin;
			}
		}
		else
		{
			if (push_begin == push_end)
				break;
			while (*push_begin != *pop_begin && push_begin != push_end)
			{
				g_stack.emplace(*push_begin);
				++push_begin;
			}
			g_stack.emplace(*push_begin);
			++push_begin;
		}
		if (pop_begin == pop_end1)
			return true;
	}
	return false;
}

/*int main()
{
	vector<int> push{1, 2, 3, 4, 5};
	vector<int> pop1{ 4,5,3,2,1 };
	vector<int> pop2{ 4,3,5,1,2 };
	cout << isOrder(push, pop1) << endl;
	while (g_stack.size() > 0)
		g_stack.pop();
	cout << isOrder(push, pop2) << endl;

	return 0;
>>>>>>> 3e99c68677b82586cb02d34c1aeebd4f6d08331d
}*/