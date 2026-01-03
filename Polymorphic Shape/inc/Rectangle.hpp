#pragma once

#include <base.hpp>

class Rectangle : public Shape
{
public:
	explicit Rectangle(float c, float d);

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
private:
	float side1;
	float side2;
};