#include <exception>
#include <iostream>
#include <vector>

class Exception1 : public std::exception {};
class Exception2 : public std::exception {};

void foo()
{
	throw Exception2{};
}

void bar() throw (Exception1)
{
	foo();
}

void f(std::vector<int>& v, size_t s) noexcept(true)
{
	v.resize(s);
}

int main()
{
	bar();

	std::vector<int> v;

	try
	{
		f(v, 1'000'000'000);
	}
	catch (std::exception& e)
	{
		std::cout << "Exception is occurred!" << std::endl;
	}

	return 0;
}