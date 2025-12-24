#include <iostream>
#include <limits>
#include <vector>
#include <functional>
#include <cmath>

void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

float sum(const std::vector<float>& arr)
{
	float total = 0.0f;
	for (int i = 0; i < arr.size(); i++)
		total += arr[i];
	return total;
}

float max(const std::vector<float>& arr)
{
	float max = 0.0f;
	for (int i = 0; i < arr.size(); i++)
		if(max < arr[i]) max = arr[i];
	return max;
}

float min(const std::vector<float>& arr)
{
	float min = arr[0];
	for (int i = 0; i < arr.size(); i++)
		if (min > arr[i]) min = arr[i];
	return min;
}


float mean(const std::vector<float>& arr)
{
	float mean = sum(arr) / static_cast<float>(arr.size());
	return mean;
}

float var(const std::vector<float>& arr)
{
	float variance = 0.0f;
	for (int i = 0; i < arr.size(); i++)
	{
		variance += (arr[i] - mean(arr)) * (arr[i] - mean(arr));
	}
	variance = variance / (arr.size() - 1);
	return variance;
}

float stdDev(const std::vector<float>& arr)
{
	auto a = std::sqrt(var(arr));
	return a;
}

int main()
{
	unsigned int n = 0;
	int checkN;
	std::cout << "Write the number of elements of the array: ";
	std::cin >> checkN;
	while (std::cin.fail() || checkN < 1)
	{
		clearInput();
		std::cout << "Error: write the valid number: ";
		std::cin >> checkN;
	}
	n = static_cast<unsigned int>(checkN);
	
	std::vector<float> array(n);
	for (int i = 0; i < n; i++)
	{
		std::cout << "Write the number for the line " << i + 1 << " for the array: ";
		std::cin >> array[i];
		while (std::cin.fail())
		{
			clearInput();
			std::cout << "Error: write the valid number: ";
			std::cin >> array[i];
		}
	}

	
	std::cout << "Sum: " << sum(array) << std::endl;
	std::cout << "Max: " << max(array) << std::endl;
	std::cout << "Min: " << min(array) << std::endl;
	std::cout << "Mean: " << mean(array) << std::endl;
	std::cout << "Var: " << var(array) << std::endl;
	std::cout << "stdDev: " << stdDev(array) << std::endl;

	return 0;
}