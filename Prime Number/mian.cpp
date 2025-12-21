#include <iostream>
#include <limits>

void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	unsigned int prime;
	int count = 0;

	std::cout << "Write a natural number: ";
	std::cin >> prime;
	while (std::cin.fail())
	{
		clearInput();
		std::cout << "Write a valid input: ";
		std::cin >> prime;
	}
	for (int i = 1; i <= prime; ++i)
	{
		float check = prime % i;
		if (check == 0)
		{
			count++;
		}
	}

	if (count == 2)
	{
		std::cout << "The number " << prime << " is prime" << std::endl;
	}
	else
	{
		std::cout << "The number " << prime << " is not prime" << std::endl;
	}
	
	return 0;
}