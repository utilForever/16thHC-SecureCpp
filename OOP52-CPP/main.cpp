struct Base
{
	virtual void f();
};

struct Derived : Base {};

void Base::f() { }

void f()
{
	Base *b = new Derived();
	delete b;
}

int main()
{
	f();

	return 0;
}