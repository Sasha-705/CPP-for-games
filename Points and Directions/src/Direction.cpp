#include <Direction.hpp>

#include <iostream>


Direction Direction::operator+(const Direction& rhs) const
{
	return { x + rhs.x, y + rhs.y };
}

Direction Direction::operator-(const Direction& rhs) const
{
	return { x - rhs.x, y - rhs.y };
}

// Member scalar multiplication
Direction Direction::operator*(float lhs) const
{
	return { x * lhs, y * lhs };
}

bool Direction::operator==(const Direction& rhs) const
{
	return x == rhs.x && y == rhs.y;
}

Direction operator*(float lhs, const Direction& rhs)
{
	return { lhs * rhs.x, lhs * rhs.y };
}
