#include <iostream>

using namespace std;

void incrNumber(char* arr, int len)
{
	//char* ptr = arr + (len - 1);
	int idx = len - 1;
	bool overflow = false;
	int number = arr[idx] - '0';
	number += 1;
	if (number == 10)
	{
		overflow = true;
		number = 0;
	}
	arr[idx] = number + '0';
	while (overflow)
	{
		--idx;
		if (idx < 0)
			break;
		int number = arr[idx] - '0';
		number += 1;
		if (number <= 9)
		{
			overflow = false;
			arr[idx] = number + '0';
		}
		else
		{
			number = 0;
			arr[idx] = number + '0';
		}
	}
}

void pr(char* str)
{
	char* ptr = str;
	while (*ptr == '0')
		++ptr;
	cout << ptr << endl;;
}

void printNumber(int n)
{
	if (n == 0)
		return;
	char* arr = new char[n + 1];
	memset(arr, '0', n);
	arr[n] = '\0';
	//cout << arr;
	int len = 1;
	for (int i = 0; i < n; ++i)
		len *= 10;
	for (int i = 1; i < len; ++i)
	{
		incrNumber(arr, n);
		//cout << arr << endl;
		pr(arr);
	}
	delete[] arr;
}



/*int main()
{
	printNumber(9);
	return 0;
}*/