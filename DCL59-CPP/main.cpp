#include "unnamed_namespace.h"

int main()
{
	extern void f();
	extern void g();

	f();
	g();
	f();
	g();

	return 0;
}