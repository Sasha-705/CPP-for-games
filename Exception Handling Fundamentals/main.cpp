#include <iostream>
#include <cerrno>
#include <string>
#include <stdexcept>

class ParseError : public std::exception
{
public:
	ParseError(std::string msg) : msg{ std::move(msg) }
	{
	}

	const char* what() const noexcept override
	{
		return msg.c_str();
	}

	const char* getErrorCode() const noexcept
	{
		return "PARSE ERROR";
	}

private:
	std::string msg;
};

class OverflowError : public std::exception
{
public:
	OverflowError(std::string msg) : msg{ std::move(msg) }
	{
	}

	const char* what() const noexcept override
	{
		return msg.c_str();
	}

	const char* getErrorCode() const noexcept
	{
		return "OVERFLOW ERROR";
	}

private:
	std::string msg;
};

class UnderflowError : public std::exception
{
public:
	UnderflowError(std::string msg) : msg{ std::move(msg) }
	{
	}

	const char* what() const noexcept override
	{
		return msg.c_str();
	}

	const char* getErrorCode() const noexcept
	{
		return "UNDERFLOW ERROR";
	}

private:
	std::string msg;
};





bool isSpace(char c)
{
	return c == ' ' || c == '\t' || c == '\n' || c == '\r';
}

bool isDigit(char c)
{
	return c >= '0' && c <= '9';
}

int parseInt(const char* str)
{
	if (str == nullptr)
	{
		errno = EINVAL;
		throw ParseError("Parse error");
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
		throw ParseError("Parse error");
	}

	unsigned long long value = 0;

	const unsigned long long maxAbs =
		negative ? (unsigned long long)INT_MAX + 1ull
		: (unsigned long long)INT_MAX;

	while (*p != '\0' && isDigit(*p))
	{
		int digit = *p - '0';

		if (value > (maxAbs - (unsigned long long)digit) / 10ull)
		{
			errno = ERANGE;
			if (negative) throw UnderflowError("Underflow error");
			else          throw OverflowError("Overflow error");
		}

		value = value * 10ull + (unsigned long long)digit;
		++p;
	}

	if (!negative)
	{
		return (int)value;
	}
	else
	{
		if (value == (unsigned long long)INT_MAX + 1ULL)
			return INT_MIN;
		else
			return -(int)value;
	}

	return 0;
}

int main()
{
	const char* testValues[10] = {
		"42", "+42", " -42", "3.14159", "10 thousand", "Ten thousand",
		"2147483647", "-2147483648", "2147483648", "-2147483649"
	};

	for (int i = 0; i != 10; i++)
	{
		try
		{
			std::cout << "parseInt(\"" << testValues[i] << "\"):" << parseInt(testValues[i]) << std::endl;
		}
		catch (const ParseError& e)
		{
			std::cout << "parseInt(\"" << testValues[i] << "\"):" << ("{} Parse error: {}\n", e.getErrorCode(), e.what()) << std::endl;
		}
		catch (const OverflowError& e)
		{
			std::cout << "parseInt(\"" << testValues[i] << "\"):" << ("{} Overflow error: {}\n", e.getErrorCode(), e.what()) << std::endl;
		}
		catch (const UnderflowError& e)
		{
			std::cout << "parseInt(\"" << testValues[i] << "\"):" << ("{} Underflow error: {}\n", e.getErrorCode(), e.what()) << std::endl;
		}
	}
	


	return 0;
}