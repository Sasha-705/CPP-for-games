#include <iostream>
#include <vector>

int main()
{
	std::vector<int> array{ 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

	auto numbers = std::remove_if(array.begin(), array.end(), [](int b) {
		return b & 2 != 0;
		});

	array.erase(numbers, array.end());

	for (int i = 0; i < array.size(); i++)
	{
		std::cout << "Array[" << i << "]: " << array[i] << std::endl;
	}
	return 0;
}