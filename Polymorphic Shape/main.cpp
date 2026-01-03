#include <iostream>
#include <limits>
#include <vector>

#include <base.hpp>
#include <Triangle.hpp>
#include <Rectangle.hpp>
#include <Square.hpp>
#include <Circle.hpp>


void clearInput()
{
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

float getPositiveDouble(const std::string& prompt)
{
	float value;

	while (true)
	{
		std::cout << prompt;
		std::cin >> value;

		if (!std::cin.fail() && value > 0)
		{
			return value;
		}

		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input. Please enter a positive number.\n";
	}
}

int main()
{
	std::vector<Shape*> shapes;
	char shape;
	

    while (true)
    {
        do
        {
            std::cout << "Choose a shape from: C(Circle), S(Scuare), R(Rectangle), T(Triangle), Q(Quit): ";
            std::cin >> shape;
            shape = static_cast<char>(std::toupper(shape));
            if (shape != 'C' && shape != 'S' && shape != 'R' && shape != 'T' && shape != 'Q' || std::cin.fail())
            {
                clearInput();
                std::cout << "Write C, S, R or T: ";
            }
        } while (shape != 'C' && shape != 'S' && shape != 'R' && shape != 'T' && shape != 'Q');

        if (shape == 'Q')
        {
            break;
        }

        switch (shape)
        {
        case 'C':
        {
            float r = getPositiveDouble("Enter radius: ");
            shapes.push_back(new Circle(r));
            break;
        }
        case 'S':
        {
            float s = getPositiveDouble("Enter side length: ");
            shapes.push_back(new Square(s));
            break;
        }
        case 'R':
        {
            float w = getPositiveDouble("Enter width: ");
            float h = getPositiveDouble("Enter height: ");
            shapes.push_back(new Rectangle(w, h));
            break;
        }
        case 'T':
        {
            float b = getPositiveDouble("Enter base: ");
            float h = getPositiveDouble("Enter height: ");
            shapes.push_back(new Triangle(b, h));
            break;
        }
        default:
            std::cout << "Unknown shape type.\n";
        }
    }

    std::cout << "\n===== Shapes Summary =====\n";
    for (const Shape* shape : shapes)
    {
        std::cout << shape->getName() << " | Area: " << shape->getArea()<< " | Perimeter: " << shape->getPerimeter() << '\n';
    }

    for (Shape* shape : shapes)
    {
        delete shape;
    }

	return 0;
}