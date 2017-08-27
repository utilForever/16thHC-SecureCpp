#include <iostream>
#include <memory>

struct S
{
	S() { std::cout << "S::S()" << std::endl; }
	~S() { std::cout << "S::~S()" << std::endl; }
};

void f()
{
	S s1;
	S* s2 = new (&s1) S;

	delete s2;
}

void g()
{
	int* i1;
	int* i2;
	try
	{
		i1 = new int;
		i2 = new int;
	}
	catch (std::bad_alloc &)
	{
		delete i1;
		delete i2;
	}
}


struct P {};

class C
{
	P* p;

public:
	C(P* p) : p(p) {}
	~C() { delete p; }

	void f() {}
};

void h1(C c)
{
	c.f();
}

void h2()
{
	P* p = new P;
	C c(p);
	h1(c);
}

void a()
{
	int* array = new int[10];
	delete array;
}

void b()
{
	int* i = static_cast<int*>(std::malloc(sizeof(int)));
	delete i;
}

struct S1
{
	~S1();
};

void c()
{
	S1* s = new S1();
	std::free(s);
}

struct S2
{
	static void *operator new(std::size_t size) noexcept(true)
	{
		return std::malloc(size);
	}

	static void operator delete(void *ptr) noexcept(true)
	{
		std::free(ptr);
	}
};

void d()
{
	S2* s = new S2;
	::delete s;
}

struct S3 {};

void e1()
{
	std::unique_ptr<S3> s{ new S3[10] };
}

struct S4 {};

void e2()
{
	std::shared_ptr<S4> s{ new S4[10] };
}

int main()
{
	f();
	g();
	h2();
	a();
	b();
	c();
	d();
	e1();
	e2();

	return 0;
}