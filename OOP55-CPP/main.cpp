struct B1
{
	virtual ~B1() = default;
};

struct D1 : B1
{
	virtual ~D1() = default;
	virtual void g() { }
};

void f1()
{
	B1* b = new B1;

	void (B1::*gptr)() = static_cast<void(B1::*)()>(&D1::g);
	(b->*gptr)();
	delete b;
}

struct B2
{
	virtual ~B2() = default;
};

struct D2 : B2
{
	virtual ~D2() = default;
	virtual void g() { }
};

static void (D2::*gptr)();

void call_memptr(D2* ptr)
{
	(ptr->*gptr)();
}

void f2()
{
	D2* d = new D2;
	call_memptr(d);
	delete d;
}

int main()
{
	f1();
	f2();

	return 0;
}