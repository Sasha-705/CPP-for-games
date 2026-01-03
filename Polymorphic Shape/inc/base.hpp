#pragma once
#include <string>

class Shape
{
public:
    virtual ~Shape() = default;
    virtual std::string getName() const = 0;
    virtual float getArea() const = 0;
    virtual float getPerimeter() const = 0;
};