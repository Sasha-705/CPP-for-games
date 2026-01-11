#include <iostream>
#include <cassert>
#include <Direction.hpp>
#include <Point.hpp>

int main()
{
	Direction a{ 1.0f, 2.0f };
	Point b{ 2.0f, 2.0f };

	Point c = b - a;
	assert(c.x == 1.0f && c.y == 0.0f);

	Point d = b + a;
	assert(d.x == 3.0f && d.y == 4.0f);

	Direction e = d - b;
	assert(e[0] == 1.0f && e[1] == 2.0f);

	Direction f = e - a;
	assert(f.x == 0.0f && f.y == 0.0f);

	Direction g = f + a;
	assert(g[0] == 1.0f && g[1] == 2.0f);

	Direction t = 2.0f * a;
	assert(t.x == 2.0f && t.y == 4.0f);

	return 0;
}