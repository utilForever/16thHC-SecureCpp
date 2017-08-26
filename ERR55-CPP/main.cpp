#include <exception>

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

int main()
{
	bar();

	return 0;
}