#include <iostream>

//class Base
//{
//public:
//	virtual ~Base() = default;
//};
//
//class Base2
//{
//public:
//	virtual ~Base2() = default;
//};
//
//class Derived : public Base
//{
//public:
//	virtual ~Derived() override = default;
//};
//
//class Derived2 : public Base
//{
//public:
//	~Derived2() override = default;
//};

int main()
{
	//unsigned char c = 'A';
	//int i = c; // Widering conversion from low to high

	//c = static_cast<unsigned char>(i); // Narrowing conversion from high to low

	//unsigned int ui = 3;
	//i = static_cast<int>(ui); // Narroing conversion

	//ui = static_cast<unsigned int>(i); // Result in unintentional behaviour

	//float f = 3.14f;
	//double d = f;
	//f = static_cast<float>(d); // Narrowing conversion

	//f = static_cast<float>(i);
	//d = i;

	//i = static_cast<int>(f);

	//f = (float)i; // better not to use C-style casts
	//i = (int)f;

	/*const float cf = 3.14f;
	float* pf = const_cast<float*>(&cf);
	*pf = 6.28f;*/

	/*Base* b = new Derived();
	Derived* d = new Derived();
	Derived2* d2 = dynamic_cast<Derived2*>(b);

	b = d;

	if (d != nullptr)
	{
		std::cout << "b is Derived" << std::endl;
	}

	if (d2 == nullptr)
	{
		std::cout << "b is not Derived2" << std::endl;
	}*/

	/*Base* b = new Base();
	Base2* b2 = reinterpret_cast<Base2*>(b);*/

	double d = 42.99;
	float f = static_cast<float>(d); // Explicit conversion from double to float(from wider to narrower)

	int i = static_cast<int>(f); // Explicit conversion from float to int(from wider to narrower)

	char c = static_cast<char>(i); // Explicit conversion from int to char(from wider to narrower)

	bool b = static_cast<bool>(c); // Explicit conversion from char to bool(from wider to narrower)

	std::cout << "Double: " << d << std::endl;
	std::cout << "Float: " << f << std::endl;
	std::cout << "Int: " << i << std::endl;
	std::cout << "Char: " << c << std::endl;
	std::cout << "Bool: " << b << std::endl;

	return 0;
}