#include <mutex>

void manipulate_shared_data(std::mutex& pm)
{
	pm.lock();

	throw 0;

	pm.unlock();
}

int main()
{
	std::mutex m;
	manipulate_shared_data(m);

	return 0;
}