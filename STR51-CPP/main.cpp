#include <cstdlib>
#include <iostream>
#include <string>

void f()
{
	std::string tmp(std::getenv("TMP"));
	if (!tmp.empty())
	{
		std::cout << tmp.c_str() << std::endl;
	}
}

int main()
{
	f();

	return 0;
}