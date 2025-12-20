#include <iostream>
#include <limits>
#include <cctype>
#include <cmath>

void circle(float &radius)
{
	const float PI = 3.141592653f;
	std::cout << "Circumference is " << 2 * PI * radius << std::endl;
	std::cout << "Area is " << PI * radius * radius << std::endl;
}

void square(float &side)
{
	std::cout << "Perimeter is " << 4*side << std::endl;
	std::cout << "Area is " << side*side << std::endl;
}

void rectangle(float &a, float &b)
{
	std::cout << "Perimeter is " << 2 * a + 2 * b << std::endl;
	std::cout << "Area is " << a * b << std::endl;
}

void triangle(float &c, float &d)
{
	std::cout << "Perimeter is " << c + c + sqrt(c * c + d * d) << std::endl;
	std::cout << "Area is " << c * d * 0.5 << std::endl;
}

void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int main()
{
	char shape;
	std::cout << "Choose a shape from: C(Circle), S(Scuare), R(Rectangle), T(Triangle): ";


	do
	{
		std::cin >> shape;
		shape = static_cast<char>(std::toupper(shape));
		if (shape != 'C' && shape != 'S' && shape != 'R' && shape != 'T' || std::cin.fail())
		{
			clearInput();
			std::cout << "Write C, S, R or T: ";
		}
	} while (shape != 'C' && shape != 'S' && shape != 'R' && shape != 'T');

	float rad; //radius for circle
	float sid; //side for square
	float recSid1; //side 1 for rectangle
	float recSid2; //side 2 for rectangle
	float baseTriangle;
	float heightTriangle;


	switch (shape)
	{
	//Circle
	case 'C':
		std::cout << "Write a radius of the circle: ";
		do
		{
			std::cin >> rad;
			if (std::cin.fail())
			{
				clearInput();
				std::cout << "Write a number: ";
			}
			else
			{
				circle(rad);
				break;
			}
		} while (true);
	//Square
	case 'S':
		std::cout << "Write a side of the square: ";
		do
		{
			std::cin >> sid;
			if (std::cin.fail())
			{
				clearInput();
				std::cout << "Write a number: ";
			}
			else
			{
				square(sid);
				break;
			}
		} while (true);

	//Rectangle
	case 'R':
		std::cout << "Write a number for the first side of the rectangle: ";
		do
		{
			std::cin >> recSid1;
			if (std::cin.fail())
			{
				clearInput();
				std::cout << "Write a number: ";
			}
			else
			{
				break;
			}
		} while (true);

		std::cout << "Write a number for the second side of the rectangle: ";
		do
		{
			std::cin >> recSid2;
			if (std::cin.fail())
			{
				clearInput();
				std::cout << "Write a number: ";
			}
			else
			{
				break;
			}
		} while (true);
		rectangle(recSid1, recSid2);

	//Triangle
	case 'T':
		std::cout << "Write a number for the base of the triangle: ";
		do
		{
			std::cin >> baseTriangle;
			if (std::cin.fail())
			{
				clearInput();
				std::cout << "Write a number: ";
			}
			else
			{
				break;
			}
		} while (true);

		std::cout << "Write a number for the height of the rectangle: ";
		do
		{
			std::cin >> heightTriangle;
			if (std::cin.fail())
			{
				clearInput();
				std::cout << "Write a number: ";
			}
			else
			{
				break;
			}
		} while (true);
		triangle(baseTriangle, heightTriangle);
	}

	return 0;
}