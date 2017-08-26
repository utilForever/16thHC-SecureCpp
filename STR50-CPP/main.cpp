#include <iostream>

void f()
{
	char buf[12];
	std::cin >> buf;
}

void g()
{
	char bufOne[12];
	char bufTwo[12];
	std::cin.width(12);
	std::cin >> bufOne;
	std::cin >> bufTwo;
}

void h(std::istream& in)
{
	char buffer[32];
	try
	{
		in.read(buffer, sizeof(buffer));
	}
	catch (std::ios_base::failure &e)
	{
		// Handle error
	}

	std::string str(buffer);
	std::cout << str.c_str() << std::endl;
}

int main()
{
	f();
	g();
	h(std::cin);

	return 0;
}