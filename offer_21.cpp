#include <iostream>
#include <vector>
#include<functional>
using namespace std;

void sulotion_1(vector<int>& arr)
{
	auto it1 = arr.begin();
	auto it2 = arr.end() - 1;

	while (it1 != it2)
	{
		while ((*it2 & 1) == 0 && it2 > it1)
			--it2;
		while ((*it1 & 1) == 1 && it1 < it2)
			++it1;
		swap(*it1, *it2);
	}
}

//解耦 提高了代码的复用性
bool compare(int a)
{
	return (a & 1) == 0;
}

void Reorder(vector<int>&, function<bool(int)>&&);

void sulotion_2(vector<int>& arr)
{
	Reorder(arr, bind(&compare, placeholders::_1));
}

void Reorder(vector<int>& arr, function<bool(int)>&& fun)
{
	auto it1 = arr.begin();
	auto it2 = arr.end() - 1;

	while (it1 < it2)
	{
		while (fun(*it2) && it2 > it1)
			--it2;
		while (!fun(*it1) && it1 < it2)
			++it1;
		swap(*it1, *it2);
	}
}



/*int main()
{
	vector<int> arr{ 2, 4, 6, 8, 10, 1, 3, 5, 7, 9};
	sulotion_1(arr);
	for (auto& i : arr)
		cout << i << " ";
	cout << endl;
	vector<int> arr1{ 2, 4, 6, 8, 10, 1, 3, 5, 7, 9 };
	sulotion_2(arr1);
	for (auto& i : arr1)
		cout << i << " ";

	return 0;
}*/