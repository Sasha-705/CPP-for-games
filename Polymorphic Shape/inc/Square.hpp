#pragma once

#include <base.hpp>

class Square : public Shape
{
public:
	explicit Square(float a);

	std::string getName() const override;
	float getArea() const override;
	float getPerimeter() const override;
private:
	float side;
};