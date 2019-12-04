#include <iostream>
#include "fmt/format.h"
using namespace std; using namespace fmt;

int main()
{
	cout << format("Position: {0}{1}{0}\n\n", "abra", "cad");

	cout << format("Default padding: \"{:6}\"\n", 42);
	cout << format("Default padding: \"{:6}\"\n", "x");
	cout << format("Pad right: \"{:>6}\"\n", -42);
	cout << format("Pad left: \"{:<6}\"\n", -42);
	cout << format("Pad center: \"{:^6}\"\n", -42);
	cout << format("Pad with char: \"{:*>6}\"\n\n", -42);

	cout << format("Pad sign: \"{:=6}\"\n", -42);
	cout << format("Leading sign: ({:+},{:+})\n", 42, -42);
	cout << format("Leading sign or space: ({: },{: })\n\n", 42, -42);

	cout << format("Bases with padding 0s: {0:0>8b},{0:0>3o},{0:0>4x}\n", 42);
	cout << format("Ditto with prefixes: {0:0>#8b},{0:0>#3o},{0:0>#4x}\n\n", 42);
	
	cout << format("Float specs:\n\t{0:e}\n\t{0:E}\n\t{0:f}\n\t{0:g}\n\t{0:G}\n", 1.1234e56);
	cout << format("Precision specs: {:.4} {:.4}\n\n", 1.1234e56, 123.456);

	cout << format("Locale: {:n}\n", 12345678);

	return 0;
}
