<<<<<<< HEAD
#include <iostream>
#include <algorithm>
using namespace std;

void Permutation(char* str, char* begin)
{
	if (*begin == '\0')
		cout << str << endl;
	else
	{
		for (char* ch = begin; *ch != '\0'; ++ch)
		{
			swap(*ch, *begin);
			Permutation(str, begin + 1);
			swap(*ch, *begin);
		}
	}
}

void Permutation(char* str)
{
	if (str == nullptr)
		return;
	Permutation(str, str);
}

int main()
{
	char str[] = "abc";
	Permutation(str);

	while (next_permutation(str, str + 3))
	{
		cout << str << endl;
	}
	return 0;
=======
#include <iostream>
#include <algorithm>
using namespace std;

void Permutation(char* str, char* begin)
{
	if (*begin == '\0')
		cout << str << endl;
	else
	{
		for (char* ch = begin; *ch != '\0'; ++ch)
		{
			swap(*ch, *begin);
			Permutation(str, begin + 1);
			swap(*ch, *begin);
		}
	}
}

void Permutation(char* str)
{
	if (str == nullptr)
		return;
	Permutation(str, str);
}

int main()
{
	char str[] = "abc";
	Permutation(str);

	while (next_permutation(str, str + 3))
	{
		cout << str << endl;
	}
	return 0;
>>>>>>> 3e99c68677b82586cb02d34c1aeebd4f6d08331d
}