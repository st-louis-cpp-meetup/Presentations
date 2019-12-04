#include <iostream>
#include <format>

int main()
{
	std::cout << std::format("Hello {}.", "world");
	return 0;
}

// <format> is a subset of "fmt/format.h", but with everything in std.
