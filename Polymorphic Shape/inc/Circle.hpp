#pragma once

#include <base.hpp>

class Circle : public Shape
{
public:
	explicit Circle(float r);

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
private:
	const float PI = 3.141592653f;
	float radius;
};