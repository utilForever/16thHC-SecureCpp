#include <iostream>

void f()
{
	int i;
	std::cout << i << std::endl;
}

void g()
{
	int *i = new int;
	std::cout << i << ", " << *i << std::endl;
}


class S
{
	int c;

public:
	int h(int i) const { return i + c; }
};

void h()
{
	S s;
	int i = s.h(10);
	std::cout << i << std::endl;
}

int main()
{
	f();
	g();
	h();

	return 0;
}