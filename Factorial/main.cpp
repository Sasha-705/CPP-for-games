#include <iostream>

int factorial(unsigned int a)
{
	if (a < 1)
		return 1;
	return a * factorial(a - 1);
}

void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	unsigned int input;

	std::cout << "Write a number to see its factorial: ";
	std::cin >> input;

	while (std::cin.fail())
	{
		clearInput();
		std::cout << "Error: the input is invalid" << std::endl;
		std::cout << "Try one more time: ";
		std::cin >> input;
	}

	std::cout << "Factorial is " << factorial(input) << std::endl;
	return 0;
}