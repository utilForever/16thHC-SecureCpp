#include <fstream>
#include <iostream>
#include <string>

void f(const std::string& fileName)
{
	std::fstream file(fileName);
	if (!file.is_open())
	{
		// Handle error
		return;
	}

	file << "Output some data";
	std::string str;
	file >> str;

	std::cout << str;

	file.close();
}

int main()
{
	f("test.txt");

	return 0;
}