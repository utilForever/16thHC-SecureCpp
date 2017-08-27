#include <iostream>
#include <vector>

std::size_t f(std::vector<int> &v, std::size_t s)
{
	try
	{
		v.resize(s);
		return s;
	}
	catch (...)
	{

	}
}

int absolute_value(int a)
{
	if (a < 0)
	{
		return -a;
	}
}

int main()
{
	std::cout << absolute_value(3) << std::endl;
	
	std::vector<int> v = { 10, 20, 30, 40, 50 };
	std::cout << f(v, 1'000'000'000) << std::endl;
}