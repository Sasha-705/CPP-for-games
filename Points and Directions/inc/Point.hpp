#pragma once

#include <Direction.hpp>
#include <cstddef>
#include <cassert>
#include <compare>

struct Point
{
	float x{};
	float y{};

	Direction operator-(const Point& rhs) const;
	Point operator+(const Direction& rhs) const;
	Point operator-(const Direction& rhs) const;

	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

	auto operator<=>(const Point& rhs) const = default;
	bool operator==(const Point& rhs) const;
};

template<typename Self>
auto&& Point::operator[](this Self&& self, size_t i)
{
	assert(i < 2);
	return i == 0 ? self.x : self.y;
}