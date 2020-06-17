#include <iostream>

using namespace std;

int partition(int* arr, int length, int low, int high)
{
	if (arr == nullptr || high < low)
		return -1;
	int value = arr[0];
	int low_ = low + 1;
	int high_ = high;

	while (low < high)
	{
		while (arr[high_] > value&& high_ > low_)
			--high_;
		while (arr[low_] < value && low_ < high_)
			++low_;
		swap(arr[low_], arr[high_]);
	}
	swap(arr[0], arr[low_]);
	return low_;
}

bool checkMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; ++i)
		if (numbers[i] == number)
			++times;
	if (times * 2 <= length)
		return false;
	return true;
}

int MoreThenHalfNum(int* numbers, int length)
{
	if (numbers == nullptr)
		return -1;
	int half = length >> 1;
	int start = 0;
	int end = length - 1;
	int idx = partition(numbers, length, start, end);
	while (idx != half)
	{
		if (idx > half)
		{
			end = idx - 1;
			idx = partition(numbers, length, start, end);
		}
		else
		{
			start = idx + 1;
			idx = partition(numbers, length, start, end);
		}
	}
	int result = numbers[idx];
	if (!checkMoreThanHalf(numbers, length, result))
		return 0;
	return result;
}

int moreThanHalfNum(int* numbers, int length)
{
	if (numbers == nullptr)
		return -1;
	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; ++i)
	{
		if (times == 0)
		{
			result = numbers[i];
			times = 1;
		}
		if (numbers[i] == result)
			++times;
		else
			--times;
	}
	return result;
}