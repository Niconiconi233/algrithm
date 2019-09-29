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
	A[.B][e|EC] �� .B[e|EC]
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
		//ʹ��||ԭ�� .��ǰ����û������ 0.233 == .233
		//.�ź����û������233.
		//.��ǰ�󶼿���������
		numeric = scanUnsignedInteger(&str) || numeric;
	}

	if (*str == 'e' || *str == 'E')
	{
		++str;
		//ʹ��&&��ԭ�� eǰ����Ҫ������ e123���ܱ�ʾ����
		//e��û�����ֲ��ܱ�ʾ���� 123.e ��123.e2.5
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