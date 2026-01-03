#include <iostream>
#include <Square.hpp>

Square::Square(float a)
{
	side = a;
}

std::string Square::getName() const
{
	return "Square";
}

float Square::getArea() const
{
	return side * side;
}

float Square::getPerimeter() const
{
	return 4 * side;
}