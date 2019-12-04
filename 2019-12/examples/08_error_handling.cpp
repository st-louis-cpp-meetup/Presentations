#include <iostream>
#include "fmt/format.h"
using namespace std; using namespace fmt;

int main()
{
	auto format_with_error = [] (const char* format_str, auto data) {
		try
		{
			cout << format(format_str, data);
		}
		catch (format_error& e)
		{
			cout << "Error: " << e.what() << "\n";
		}
	};

	format_with_error("{:d}", "not a number");
	format_with_error("{:d}", 2.34);
	format_with_error("{:g}", 2);
	format_with_error("{1}", 1); // bad position
	format_with_error("{} {}", 1); // bad position
auto msg = fmt::format("{key2}: {key1}", fmt::arg("key1", 1), fmt::arg("key2", "abc"));
	cout << msg;
	return 0;
}
