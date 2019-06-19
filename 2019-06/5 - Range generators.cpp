//-std=c++2a -I/opt/compiler-explorer/libs/cmcstl2/include -fconcepts
#include <iostream>
#include <experimental/ranges/ranges> // from cmcstl2
namespace ranges = std::experimental::ranges;
namespace view = std::experimental::ranges::view;

//range generators (range adaptors)

int main() {
  auto count_to_10 = view::iota(1, 11);
  auto one_int = view::single(37);
  auto no_ints = view::empty<int>;
  auto infinite_count = view::iota(1);
  auto only1234 = view::counted(infinite_count.begin(), 4);

  for (int x: count_to_10) {
      std::cout << x << " ";
  }
}
