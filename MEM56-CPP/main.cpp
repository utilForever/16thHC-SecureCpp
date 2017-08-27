#include <memory>

void f()
{
	int* i = new int;
	std::shared_ptr<int> p1(i);
	std::shared_ptr<int> p2(i);
}

struct B
{
	virtual ~B() = default;
};

struct D : B {};

void func(std::shared_ptr<D> derived)
{
	
}

void g()
{
	std::shared_ptr<B> poly(new D);

	func(std::shared_ptr<D>(dynamic_cast<D*>(poly.get())));
}

struct S
{
	std::shared_ptr<S> func() { return std::shared_ptr<S>(this); }
};

void h()
{
	std::shared_ptr<S> s1 = std::make_shared<S>();
	std::shared_ptr<S> s2 = s1->func();
}

int main()
{
	f();
	g();
	h();

	return 0;
}