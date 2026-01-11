#include <iostream>

#include <Point.hpp>



Direction Point::operator-(const Point& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

Point Point::operator-(const Direction& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

bool Point::operator==(const Point& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

Point Point::operator+(const Direction& rhs) const
{
	return { x + rhs.x, y + rhs.y };
}
