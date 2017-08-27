#include <cstring>
#include <iostream>

class C1
{
	int scalingFactor;
	int otherData;

public:
	C1() : scalingFactor(1) {}

	void set_other_data(int i);
	
	int f(int i)
	{
		return i / scalingFactor;
	}
};

void f()
{
	C1 c;
	std::memset(&c, 0, sizeof(C1));

	std::cout << c.f(100) << std::endl;
}

class C2
{
	int *i;

public:
	C2() : i(nullptr) {}
	~C2() { delete i; }

	void set(int val)
	{
		if (i) { delete i; }
		i = new int{ val };
	}
};

void g(C2& c1)
{
	C2 c2;
	std::memcpy(&c2, &c1, sizeof(C2));
}

class C3
{
	int i;

public:
	virtual void f();

	// ...
};

void C3::f() { }

class C31 : public C3 { };

void h(C3 &c1, C3 &c2)
{
	if (!std::memcmp(&c1, &c2, sizeof(C3)))
	{
		std::cout << "Same!" << std::endl;
	}
	else
	{
		std::cout << "Not Same!" << std::endl;
	}
}

int main()
{
	f();

	C2 c;
	c.set(3);
	g(c);

	C3 c1;
	C31 c2;
	h(c1, c2);

	return 0;
}