//-std=c++2a -I/opt/compiler-explorer/libs/cmcstl2/include -fconcepts
#include <iostream>
#include <experimental/ranges/ranges> // from cmcstl2
namespace ranges = std::experimental::ranges;
namespace view = std::experimental::ranges::view;

//range adaptors

bool is_even(int x) { return x % 2 == 0; }
int times3(int x) { return x * 3; }

int main() {
  auto infinite_count = view::iota(1);
  auto count_to_10 = view::iota(1, 11);
  auto one_int = view::single(37);
  auto no_ints = view::empty<int>;
  auto only1234 = view::counted(infinite_count.begin(), 4);

  auto thing = infinite_count | view::filter(is_even) | view::transform(times3);

  for (int x: thing | view::take(10)) {
    std::cout << x << " ";
  }

  std::vector<std::string> ss = {"hello", " ", "world", "!\n"};
  auto greeting = ss | view::join;
  //auto greeting = view::join(ss);
  //ranges::join_view greeting{ss};
  for (char c: greeting) {
    std::cout << c;
  }
}

// filter
// transform
// take
// join
// split
// reverse
// all, common
