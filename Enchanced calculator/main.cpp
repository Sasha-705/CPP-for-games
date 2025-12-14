#include <iostream>
#include <string>

int main()
{
	float num1, num2;
	char operation;

	std::cout << "Enchanced Calculator\n";

	//Check for valid number input
	while (true) {
		std::cout << "Enter first number: ";
		std::cin >> num1;

		if (std::cin.fail()) {
			std::cin.clear(); // clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Error: Please enter a valid number.\n";
		}
		else {
			break; // valid number entered
		}
	}
	std::cout << "Choose an operation (+, -, *, /, %, ^): ";

	//Check for valid operation input
	std::cin >> operation;
	while (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%' && operation != '^')
	{
		std::cout << "Invalid operation. Please choose (+, -, *, /, %, ^): ";
		std::cin >> operation;
	}

	//Check for valid number input
	while (true) {
		std::cout << "Enter second number: ";
		std::cin >> num2;

		if (std::cin.fail()) {
			std::cin.clear(); // clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Error: Please enter a valid number.\n";
		}
		else {
			break; // valid number entered
		}
	}

	//Perform calculation based on operation
	switch (operation)
	{
	case '+':
		std::cout << "Result: " << num1 + num2 << std::endl;
		break;
	case '-':
		std::cout << "Result: " << num1 - num2 << std::endl;
		break;
	case '/':
		while (num2 == 0)
		{
			std::cout << "Error: Division by zero is not allowed. Please enter a non-zero second number: ";
			std::cin >> num2;
		}
		std::cout << "Result: " << num1 / num2 << std::endl;
		break;
	case '*':
		std::cout << "Result: " << num1 * num2 << std::endl;
		break;
	case '%':
		while (num2 == 0)
		{
			std::cout << "Error: please enter a non-zero second number: ";
			std::cin >> num2;
		}
		std::cout << "Result: " << std::fmod(num1, num2) << std::endl;
		break;
	case '^':
		std::cout << "Result: " << std::pow(num1, num2) << std::endl;
		break;
	}

	return 0;
}