#include <iostream>
#include <string>
#include "fmt/format.h"
using namespace std; using namespace fmt;

int main()
{
	cout << format("Reals: {}, {}, {}, {}\n", 1./3., 0.5F, 2.345e40, numeric_limits<long double>::infinity());
	cout << format("Integers: {}, {}, {}\n", 32, 9223372036854775808ULL, (short) -32768);
	cout << format("Strings: {}, {}\n", "char*", string{"string"});
	wcout << format(L"Wide strings: {}, {}\n", L"wchar*", wstring{L"wstring"});
	cout << format("Booleans: {}, {}\n", true, false);
	cout << format("void *: {}, {}\n", (void*)"abc", nullptr);

	return 0;
}
