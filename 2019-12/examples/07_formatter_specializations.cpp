#include <iostream>
#include "fmt/format.h"
using namespace std; using namespace fmt;

// Add a formatter specialization to enum class color
enum class color { red, green, blue};
const char* color_names[] = { "red", "green", "blue" };

template<> struct formatter<color> : formatter<const char*> {
    auto format(color c, format_context& ctx) {
      return formatter<const char*>::format(color_names[static_cast<int>(c)], ctx);
    }
  };

int main()
{
	cout << format("Colors: {}, {}, {}\n", color::green, color::red, color::blue);
	return 0;
}
