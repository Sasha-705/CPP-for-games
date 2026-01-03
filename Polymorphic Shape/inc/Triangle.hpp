#pragma once

#include <base.hpp>

class Triangle : public Shape
{
public:
	explicit Triangle(float b, float h);

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
private:
	float base;
	float height;
};