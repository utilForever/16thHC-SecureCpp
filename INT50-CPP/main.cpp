#include <iostream>

enum EnumType : unsigned int
{
	First,
	Second,
	Third
};

void f(int intVar)
{
	EnumType enumVar = static_cast<EnumType>(intVar);

	if (enumVar < First || enumVar > Third)
	{
		std::cout << enumVar << std::endl;
	}
}

int main()
{
	f(-1);
	
	return 0;
}