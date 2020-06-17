#include <iostream>
#include <list>
using namespace std;

list<int>::iterator sulotion(list<int>& list, unsigned int k)
{
	if (list.size() < k || k == 0)
		throw std::exception("invaild input");
	auto it1 = list.begin();
	auto it2 = list.begin();

	for (int i = 0; i < k - 1; ++i)
		++it1;
	while (++it1 != list.end())
	{
		++it2;
	}
	return it2;
}

//相关题目 获取链表的中间节点

list<int>::iterator sulotion_1(list<int>& list)
{
	auto it1 = list.begin();
	auto it2 = list.begin();

	while (++it2 != list.end())
	{
		if (++it2 == list.end())
			break;
		++it1;
	}
	return it1;
}




/*int main()
{
	list<int> list{1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
	try
	{
		auto iter = sulotion(list, 11);
		cout << *iter;
	}
	catch (const std::exception& e)
	{
		cerr << e.what() << endl;
	}
	cout << endl;
	cout << *sulotion_1(list);

	return 0;
}*/