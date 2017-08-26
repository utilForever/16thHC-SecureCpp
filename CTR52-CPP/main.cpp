#include <vector>

void f(const std::vector<int>& src)
{
	std::vector<int> dest;
	std::copy(src.begin(), src.end(), dest.begin());
}

void g()
{
	std::vector<int> v;
	std::fill_n(v.begin(), 10, 0x42);
}

int main()
{
	std::vector<int> v = { 10, 20, 30, 40, 50 };

	f(v);

	g();
	
	return 0;
}