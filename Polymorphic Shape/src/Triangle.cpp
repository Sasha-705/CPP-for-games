#include <iostream>
#include <Triangle.hpp>
#include <cmath>

Triangle::Triangle(float b, float h)
{
	base = b;
	height = h;
}

std::string Triangle::getName() const
{
	return "Triangle";
}

float Triangle::getArea() const
{
	return base * height * 0.5;
}

float Triangle::getPerimeter() const
{
	return base + height + std::sqrt(base * base + height * height);
}