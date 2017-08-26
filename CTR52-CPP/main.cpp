#include <vector>

void f(const std::vector<int>& src)
{
	std::vector<int> dest;
	std::copy(src.begin(), src.end(), dest.begin());
}

int main()
{
	std::vector<int> v = { 10, 20, 30, 40, 50 };

	f(v);
	
	return 0;
}