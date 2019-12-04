#include "fmt/format.h"

int main()
{
	fmt::print("Hello {}.", "world");
	return 0;
}

// However, some very useful functionality didn't
// make the C++20 cut, even as basic as fmt::print().
