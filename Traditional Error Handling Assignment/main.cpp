#include <iostream>
#include <cerrno>

bool isSpace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int parseInt(const char* str, int* result)
{
	if (str == nullptr || result == nullptr)
	{
		errno = EINVAL;
		return -1;
	}

	errno = 0; 

	const char* p = str;

	while (*p != '\0' && isSpace(*p))
		++p;

	bool negative = false;
	if (*p == '+' || *p == '-')
	{
		if (*p == '-') negative = true;
		++p;
	}

	if (!isDigit(*p))
	{
		errno = EINVAL;
		return -1;
	}

	unsigned long long value = 0;

	while (*p != '\0' && isDigit(*p))
	{
		int digit = *p - '0';

		if (value > static_cast<unsigned long long>(INT_MAX - digit) / 10)
		{
			errno = ERANGE;
			return -2;
		}
		else
		{
			const unsigned long long limit =
				static_cast<unsigned long long>(INT_MAX) + 1ull;

			if (value > (limit - static_cast<unsigned long long>(digit)) / 10ull)
			{
				errno = ERANGE;
				return -2;
			}
		}

		value = value * 10ull + static_cast<unsigned long long>(digit);
		++p;
	}

	if (!negative)
	{
		*result = (int)value;
	}
	else
	{
		if (value == (unsigned long long)INT_MAX + 1ULL)
			*result = INT_MIN;
		else
			*result = -(int)value;
	}

	return 0;
}

bool tryParseInt(const char* str, int& result)
{
	int temp = 0;
	if (parseInt(str, &temp) == 0)
	{
		result = temp;
		return true;
	}
	return false;
}

int main()
{
	int x;

	parseInt("42", &x);
	std::cout << x << "\n";

	parseInt("+42", &x);
	std::cout << x << "\n";

	parseInt(" -42", &x);
	std::cout << x << "\n";

	parseInt("3.14159", &x);
	std::cout << x << "\n";

	parseInt("10 thousand", &x);
	std::cout << x << "\n";

	if (parseInt("Ten thousand", &x) != 0)
		std::cout << "Parse error\n";

	parseInt("2147483647", &x);
	std::cout << x << "\n";

	parseInt("-2147483648", &x);
	std::cout << x << "\n";

	if (parseInt("2147483648", &x) != 0)
		std::cout << "Overflow\n";

	if (parseInt("-2147483649", &x) != 0)
		std::cout << "Underflow\n";

	return 0;
}