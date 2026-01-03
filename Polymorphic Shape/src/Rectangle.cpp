#include <iostream>
#include <Rectangle.hpp>

Rectangle::Rectangle(float c, float d)
{
	side1 = c;
	side2 = d;
}

std::string Rectangle::getName() const
{
	return "Rectangle";
}

float Rectangle::getArea() const
{
	return side1 * side2;
}

float Rectangle::getPerimeter() const
{
	return side1 * 2 + side2 * 2;
}