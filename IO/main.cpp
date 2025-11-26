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
	if (age < 25)
	{
		std::cout << "Hello, " << name;
		std::cout << ", you are only " << age << " years old." << std::endl;
	}
	if (age >= 25 && age < 50)
	{
		std::cout << "Hello, " << name;
		std::cout << ", you are already " << age << " years old." << std::endl;
	}
	if (age >= 50)
	{
		std::cout << "Hello, " << name;
		std::cout << ". You are very wise for your age." << std::endl;
	}

	std::cout << "\nPress Enter to exit...";
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::cin.get();
	return 0;
}