#pragma once

#include <cstddef>
#include <cassert>
#include <compare>

struct Direction
{
	Direction operator+(const Direction& rhs) const;
	Direction operator-(const Direction& rhs) const;
	Direction operator*(float lhs) const;

	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

	auto operator<=>(const Direction& rhs) const = default;
	bool operator==(const Direction& rhs) const;

	float x{};
	float y{};
};

template<typename Self>
auto&& Direction::operator[](this Self&& self, size_t i)
{
	assert(i < 2);
	return i == 0 ? self.x : self.y;
}

// Add this non-member operator* to support float * Direction
Direction operator*(float lhs, const Direction& rhs);