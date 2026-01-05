#pragma once

#include <cstring>
#include <cassert>

template<typename T>
struct Array
{
	Array();
	Array(size_t size, const T& value = T());

	~Array();

	//Copy constructor
	Array(const Array& copy);

	//Copy assignment operator
	Array& operator=(const Array& rhs);

	//Move constructor
	Array(Array&& other);

	//Move assignment operator
	Array& operator=(Array&& rhs);

	void reserve(size_t newCapacity);
	void add(const T& value);
	bool empty() const;
	size_t size() const;
	size_t capacity() const;

	template<typename Self>
	auto data(this Self&& self);

	template<typename Self>
	auto&& operator[](this Self&& self, size_t i);

private:
	T* m_data = nullptr;
	size_t m_size = 0;
	size_t m_capacity = 0;
};

template<typename T>
Array<T>::Array()
{
	m_capacity = 8;
	m_data = new T[m_capacity];
}

template<typename T>
Array<T>::Array(size_t size, const T& value)
{
	m_size = size;
	m_capacity = size;
	m_data = new T[m_capacity];

	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i] = value;
	}
}

template<typename T>
Array<T>::~Array()
{
	delete[] m_data;
}

template<typename T>
Array<T>::Array(const Array& copy)
	: m_size{ copy.m_size },
	  m_capacity{ copy.m_capacity }
{
	m_data = new T[m_capacity];
	std::memcpy(m_data, copy.m_data, m_size * sizeof(T));

	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i] = copy.m_data[i];
	}
}

template<typename T>
Array<T>& Array<T>::operator=(const Array<T>& rhs)
{
	if (this == &rhs) return *this;

	if (m_capacity != rhs.m_size)
	{
		delete[] m_data;
		m_data = new T[rhs.m_capacity];
		m_capacity = rhs.m_size;
	}

	std::memcpy(m_data, rhs.m_data, m_size * sizeof(T));

	m_size = rhs.m_size;

	for (size_t i = 0; i < m_size; ++i)
	{
		m_data[i] = rhs.m_data[i];
	}

	return *this;
}

template<typename T>
Array<T>::Array(Array&& other)
	:m_size(other.m_size),
	 m_capacity(other.m_capacity)
{
	m_data = other.m_data;

	other.m_data = nullptr;
	other.m_size = 0;
	other.m_capacity = 0;
}

template<typename T>
Array<T>& Array<T>::operator=(Array&& rhs)
{
	if (this == &rhs) return *this;

	m_data = rhs.m_data;
	m_size = rhs.m_size;
	m_capacity = rhs.m_capacity;

	rhs.m_data = nullptr;
	rhs.m_size = 0;
	rhs.m_capacity = 0;

	return *this;
}

template<typename T>
void Array<T>::reserve(size_t newCapacity)
{
	T* newData = new T[newCapacity];
	for (size_t i = 0; i < m_size; ++i)
	{
		newData[i] = m_data[i];
	}
	delete[] m_data;

	m_data = newData;
	m_capacity = newCapacity;

}

template<typename T>
void Array<T>::add(const T& value)
{
	if (m_size == m_capacity)
	{
		size_t newCapacity = (m_capacity == 0) ? 1 : m_capacity * 2;
		reserve(newCapacity);
	}

	m_data[m_size] = value;
	++m_size;
}

template<typename T>
bool Array<T>::empty() const
{
	if(m_size == 0) 
		return true;
	return false;
}

template<typename T>
size_t Array<T>::size() const
{
	return m_size;
}

template<typename T>
size_t Array<T>::capacity() const
{
	return m_capacity;
}

template<typename T>
template<typename Self>
inline auto Array<T>::data(this Self&& self)
{
	return m_data();
}

template <typename T>
template <typename Self>
auto&& Array<T>::operator[](this Self&& self, size_t i)
{
	assert(i < self.m_size);
	return self.m_data[i];
}
