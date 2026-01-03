#include <iostream>
#include <Circle.hpp>

Circle::Circle(float r)
{
	radius = r;
}

std::string Circle::getName() const
{
	return "Circle";
}

float Circle::getArea() const
{
	return PI * radius * radius;
}

float Circle::getPerimeter() const
{
	return PI * radius * 2;
}