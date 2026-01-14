#include <iostream>

#include <Array.hpp>
#include <cassert>
#include <numeric>

int main()
{
	//default constructor
	Array<float> a;
	assert(a.size() == 0);
	assert(a.capacity() == 8);

	//parametized constructor
	Array<int> b(5, 42);

	assert(b.size() == 5);

	for (size_t i = 0; i < b.size(); ++i)
	{
		assert(b[i] == 42);
	}

	//copy constructor
	Array<int> c(3, 7);
	Array<int> d(c);   

	assert(c.size() == d.size());

	for (size_t i = 0; i < a.size(); ++i)
	{
		assert(c[i] == c[i]);
	}

	//move constructor
	Array<int> e(4, 9);
	Array<int> f(std::move(e));   

	assert(f.size() == 4);

	for (size_t i = 0; i < f.size(); ++i)
	{
		assert(f[i] == 9);
	}

	assert(e.size() == 0);

	//copy assignment operator
	Array<int> g(3, 5);
	Array<int> h(1, 0);

	h = g;   // copy assignment

	assert(h.size() == g.size());

	for (size_t i = 0; i < g.size(); ++i)
	{
		assert(g[i] == h[i]);
	}

	//move assignment operator
	Array<int> k(2, 8);
	Array<int> l(1, 0);

	l = std::move(k);   

	assert(l.size() == 2);

	for (size_t i = 0; i < l.size(); ++i)
	{
		assert(l[i] == 8);
	}

	assert(k.size() == 0);

	//begin() and end()
	{
		Array<int> arr;
		arr.add(10);
		arr.add(20);

		auto it = arr.begin();

		assert(*it == 10);
	}
	{
		Array<int> arr;
		arr.add(1);
		arr.add(2);
		arr.add(3);

		auto it = arr.begin();
		auto end = arr.end();

		int count = 0;
		for (; it != end; ++it)
		{
			++count;
		}

		assert(count == 3);
	}
	{
		Array<int> arr;
		arr.add(5);
		arr.add(10);
		arr.add(15);

		int sum = 0;
		for (int value : arr)
		{
			sum += value;
		}

		assert(sum == 30);
	}
	{
		Array<int> arr;
		arr.add(1);
		arr.add(2);
		arr.add(3);
		arr.add(4);

		int sum = std::accumulate(arr.begin(), arr.end(), 0);

		assert(sum == 10);
	}
	return 0;
}