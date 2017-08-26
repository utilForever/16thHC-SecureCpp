#include <cstring>

class IntArray
{
public:
	~IntArray()
	{
		delete[] array;
	}

	IntArray(const IntArray& that) = delete;

	IntArray& operator=(const IntArray& rhs)
	{
		if (this != &rhs)
		{
			delete[] array;
			array = nullptr;

			nElems = rhs.nElems;
			
			if (nElems)
			{
				array = new int[nElems];
				std::memcpy(array, rhs.array, nElems * sizeof(*array));
			}
		}

		return *this;
	}

private:
	int* array;
	std::size_t nElems;
};