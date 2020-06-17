#include <iostream>
#include <vector>
using namespace std;

bool func(vector<int>&, size_t, size_t);

bool verifySquenceOfBST(vector<int>& arr)
{
	return func(arr, 0, arr.size());
}

bool func(vector<int>& arr, size_t begin, size_t end)
{
	if (arr.size() == 0 || end < begin)
		return false;
	int root = arr[end - 1];
	size_t i = 0;
	//分开左右节点
	while (arr[i] < root && i < end - 1)
		++i;
	size_t j = i;
	for (; j < end - 1; ++j)
		if (arr[j] < root)
			return false;
	bool left = true;
	if (i > 0)
		left = func(arr, 0, i);
	bool right = true;
	if (i < end - 1)
		right = func(arr, i, end - 1);
	return left && right;
}

int main()
{
	vector<int> arr{ 5,7,6,9,11,10,8 };
	cout << verifySquenceOfBST(arr);
	return 0;

}