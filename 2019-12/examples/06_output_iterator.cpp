#include <array>
#include <iostream>
#include <iterator>
#include <string_view>
#include <thread>
#include "fmt/format.h"
using namespace std; using namespace fmt;

int main()
{
	ostream_iterator<char> cout_it{cout};
	for (int i = 1; i <= 5; i++)
	{
		// Unlike format(), format_to() never allocates a string
		format_to(cout_it, "int({}) ", i);
		cout.flush();
		std::this_thread::sleep_for(1s);
	}


	// clips off at 10 characters
	array<char, 11> buf;
	auto str_it = buf.begin();
	auto result = format_to_n(str_it, 10, "{}", "A kind of a long string");
	*result.out = '\0';

	cout << "\n" << std::string_view(buf.data());
	cout << fmt::format("\nClipped {} characters.\n", result.size - 10);

	return 0;
}
