#include <iostream>

using namespace std;

bool scanUnsignedInteger(const char** str)
{
	const char* before = *str;
	while (**str != '\0' && **str >= '0' && **str <= '9')
		++*str;
	return *str > before;
}

bool scanInteger(const char** str)
{
	if (**str == '+' || **str == '-')
		++*str;
	return scanUnsignedInteger(str);
}


/*
	A[.B][e|EC] 或 .B[e|EC]
*/
bool isNumber(const std::string& number)
{
	if (number.size() == 0)
		return false;
	const char* str = number.c_str();

	bool numeric = scanInteger(&str);

	if (*str == '.')
	{
		++str;
		//使用||原因 .号前可以没有整数 0.233 == .233
		//.号后可以没有整数233.
		//.号前后都可以有整数
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	if (*str == 'e' || *str == 'E')
	{
		++str;
		//使用&&的原因 e前必须要有数字 e123不能表示数字
		//e后没有数字不能表示数字 123.e 或123.e2.5
		numeric = scanInteger(&str) && numeric;
	}
	return numeric && *str == '\0';
}


/*int main()
{
	cout << isNumber("+123") << endl;
	cout << isNumber("123e") << endl;
	return 0;
}*/