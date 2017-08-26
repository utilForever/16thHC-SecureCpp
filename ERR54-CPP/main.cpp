#include <iostream>

class B {};
class D : public B {};

void f()
{
	try
	{
		throw D();
	}
	catch (B& b)
	{
		std::cout << "Exception in B is occurred!" << std::endl;
	}
	catch (D& d)
	{
		std::cout << "Exception in D is occurred!" << std::endl;
	}
}

int main()
{
	f();

	return 0;
}