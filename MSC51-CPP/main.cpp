#include <random>
#include <iostream>

void f()
{
	std::mt19937 engine;

	for (int i = 0; i < 10; ++i)
	{
		std::cout << engine() << std::endl;
	}
}

int main()
{
	f();

	return 0;
}