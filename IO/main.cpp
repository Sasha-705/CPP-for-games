#include <iostream>
#include <string>
#include <limits>

int main()
{
	std::string name;
	int age;

	std::cout << "Enter your name: ";
	std::cin >> name;

	std::cout << "Enter your age: ";
	std::cin >> age;

	while (std::cin.fail())
	{
		std::cout << "Error: Please enter a valid age: ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cin >> age;
	}

	std::cout << "Hey, " << name;
	std::cout << "! You are " << age << " years old." << std::endl;

	std::cout << "Press Enter to exit...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}