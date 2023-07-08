#include <iostream>

class A {
private:
	int m_value;
public:
	A()
	{
		std::cout << "Default constructor "  << std::endl;

	}
	A(int a) :m_value(a)
	{
		std::cout << "Parametrized constructor " << std::endl;
	}
	A(const A& obj) :m_value(obj.m_value)
	{
		std::cout << "Copy constructor "  << std::endl;
	}
	~A()
	{
		std::cout << "Destructor " << std::endl;
	}
public:
	int add;
	A operator ++(int)
	{
		A temp = *this;
		add++;
		return temp;
	}

public:

	void print()
	{
		std::cout << "Peaseful world (Lvalue ) " << std::endl;
	}
	void print(A& obj)
	{
		std::cout << "Peaseful world (Lvalue reference) " << std::endl;
	}
	void print(const A& obj)
	{
		std::cout << "Peaseful world (Const lvalue reference) " << std::endl;
	}
	void print(A&& obj)
	{
		std::cout << "Peaseful world (Rvalue reference) " << std::endl;
	}
	void print(const int&& obj)
	{
		std::cout << "Peaseful world (Const rvalue reference) " << std::endl;
	}
};

int main(int argc, char** argv)
{
	A myObj;
	A myObj2(15);
	const A myObj3(20);
	myObj.print();
	myObj.print(myObj2);
	myObj.print(myObj3);
	myObj.print(A(33));
	myObj.print(myObj.add++);//in my operator ++ overloading i have int argument, that's why it works
	myObj.print(8);
	return 0;
}