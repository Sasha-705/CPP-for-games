#pragma once
#include <cstdint>
#include <compare>

class Byte
{
public:
	explicit Byte(std::uint64_t bytes = 0ull)
		: bytes{bytes}
	{ }

	auto operator<=>(const Byte& rhs) const = default;
	bool operator==(const Byte& rhs) const
	{
		return bytes == rhs.bytes;
	}

	std::uint64_t b() const
	{ 
		return bytes * 8ull;
	}

	std::uint64_t B() const
	{
		return bytes;
	}

	double Kb() const
	{
		return static_cast<double>(bytes) * 8.0 / 1000.0;
	}

	double KB() const
	{
		return static_cast<double>(bytes) / 1000.0;
	}

	double Mb() const
	{
		return static_cast<double>(bytes) * 8.0 / 1000000.0;
	}

	double MB() const
	{
		return static_cast<double>(bytes) / (1000.0 * 1000.0);
	}
private:
	std::uint64_t bytes = 0ull;
};

Byte operator""_b(unsigned long long bits)
{
	return Byte((bits + 7ull) / 8ull);
}

Byte operator""_B(unsigned long long bytes)
{
	return Byte(bytes);
}

Byte operator""_Kb(unsigned long long kilobits)
{
	std::uint64_t bits = kilobits * 1000ull;
	return Byte((bits + 7ull) / 8ull);
}

Byte operator""_KB(unsigned long long kilobytes)
{
	return Byte(kilobytes * 1000ull);
}

Byte operator""_Mb(unsigned long long megabits)
{
	std::uint64_t bits = megabits * 1000000ull;
	return Byte((bits + 7ull) / 8ull);
}

Byte operator""_MB(unsigned long long megabytes)
{
	return Byte(megabytes * ( 1000ull * 1000ull ));
}