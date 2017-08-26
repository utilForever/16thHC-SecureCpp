#include <iostream>
#include <vector>

void f(const std::vector<int>& c)
{
	for (auto i = c.begin(), e = i + 20; i != e; ++i)
	{
		std::cout << *i << std::endl;
	}
}

int main()
{
	std::vector<int> v = { 10, 20, 30, 40, 50 };

	f(v);

	return 0;
}