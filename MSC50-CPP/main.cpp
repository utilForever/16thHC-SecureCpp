#include <cstdlib>
#include <iostream>
#include <string>

void f()
{
	std::string id("ID");
	id += std::to_string(std::rand() % 10000);
	std::cout << id.c_str() << std::endl;
}

int main()
{
	f();

	return 0;
}