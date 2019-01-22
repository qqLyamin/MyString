#include <iostream>
#include "MyString.h"


int main()
{

	setlocale(LC_ALL, "Rus");

	MyString a("asdjahk");

	a = "asdasd";

	MyString b(a);

	b = "asdla";

	bool big = a > b;
	bool small = a < b;

	std::cout << a;

	__asm nop
}