//-std=c++2a -I/opt/compiler-explorer/libs/cmcstl2/include -fconcepts
#include <iostream>
#include <vector>
#include <experimental/ranges/ranges> // from cmcstl2
namespace ranges = std::experimental::ranges;

// array subscripts
int sum_c(int* xs, int count) {
  int sum = 0;
  for (int i = 0; i < count; ++i) {
    sum += xs[i];
  }
  return sum;
}

// iterators
int sum_stl(const std::vector<int>& v) {
  int sum = 0;
  for (std::vector<int>::const_iterator p = v.begin(); p != v.end(); ++p) {
    sum += *p;
  }
  return sum;
}

// range-based for
int sum_cpp11(const std::vector<int>& v) {
  int sum = 0;
  for (int x: v) {
    sum += x;
  }
  return sum;
}

//std::begin/std::end
//Implement member functions begin() and end() 
//or implement free begin()/end() functions in the same namespace

int main() {
  int x[] = {1, 1, 2, 3, 5};
  std::cout << sum_c(x, std::size(x)) << "\n";

  std::vector v = {1, 1, 2, 3, 5};
  std::cout << sum_stl(v) << "\n";
  std::cout << sum_cpp11(v) << "\n";
}
