#include <iostream>

int main()
{
	int size;
	while (true) {
		std::cout << "Enter the size of the dynamic array (more than 0 and no more than 10 (only integer)): ";
		std::cin >> size;

		if (std::cin.fail() || size <= 0 || size > 10) {
			std::cin.clear(); // clear error flag
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
			std::cout << "Error: Please enter an integer.\n";
		}
		/*if (size <= 0 || size > 10)
		{
			std::cout << "Error: Size must be more than 0 and no more than 10.\n";
		}*/
		else {
			break; // valid number entered
		}
	}
	int* array = new int[size];

	for (int i = 0; i < size; ++i)
	{
		std::cout << "Enter the size of the line " << i + 1 << ": ";
		std::cin >> array[i];

		if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Error: Please enter an integer.\n";
			i--;
		}
	}
	int min = array[0];
	int max = array[0];
	int sum = 0;

	for (int i = 0; i < size; ++i)
	{
		if (array[i] < min)
		{
			min = array[i];
		}
		if (array[i] > max)
		{
			max = array[i];
		}
		sum += array[i];
	}
	std::cout << "Min: " << min << std::endl;
	std::cout << "Max: " << max << std::endl;
	std::cout << "Avarage number: " << static_cast<double>(sum)/size << std::endl;

	delete[] array;

	return 0;
}