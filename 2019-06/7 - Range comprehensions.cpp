// A sample standard C++20 program that prints
// the first N Pythagorean triples.
// modified from http://ericniebler.com/2018/12/05/standard-ranges/
//-std=c++2a -I/opt/compiler-explorer/libs/cmcstl2/include -fconcepts
#include <iostream>
#include <optional>
//#include <ranges>   // New header in C++20
#include <experimental/ranges/ranges> // from cmcstl2
 namespace std {
    namespace ranges = experimental::ranges;
    namespace view = experimental::ranges::view;
}

// maybe_view defines a view over zero or one
// objects.
template<std::ranges::Semiregular T>
struct maybe_view : std::ranges::view_interface<maybe_view<T>> {
  maybe_view() = default;
  maybe_view(T t) : data_(std::move(t)) {
  }
  T const *begin() const noexcept {
    return data_ ? &*data_ : nullptr;
  }
  T const *end() const noexcept {
    return data_ ? &*data_ + 1 : nullptr;
  }
private:
  std::optional<T> data_{};
};

// "yield_if" takes a bool and a value and
// returns a view of zero or one elements.
inline constexpr auto yield_if =
  []<std::ranges::Semiregular T>(bool b, T x) {
    return b ? maybe_view{std::move(x)}
             : maybe_view<T>{};
  };
 
// "for_each" creates a new view by applying a
// transformation to each element in an input
// range, and flattening the resulting range of
// ranges.
// (This uses one syntax for constrained lambdas
// in C++20.)
inline constexpr auto for_each =
  []<std::ranges::Range R,
     std::ranges::Iterator I = std::ranges::iterator_t<R>,
     std::ranges::IndirectUnaryInvocable<I> Fun>(R&& r, Fun fun)
        //requires Range<indirect_result_t<Fun, I>>
    {
      return std::forward<R>(r)
        | std::view::transform(std::move(fun))
        | std::view::join;
  };
 
void old_and_busted(int);

int main() {
  // Define an infinite range of all the
  // Pythagorean triples:
  using std::view::iota;
  auto triples =
    for_each(iota(1), [](int z) {
      return for_each(iota(1, z+1), [=](int x) {
        return for_each(iota(x, z+1), [=](int y) {
          return yield_if(x*x + y*y == z*z,
            std::make_tuple(x, y, z));
        });
      });
    });

    // Display the first 10 triples
    for(auto triple : triples | std::view::take(10)) {
      std::cout << '('
           << std::get<0>(triple) << ','
           << std::get<1>(triple) << ','
           << std::get<2>(triple) << ')' << '\n';
  }
}

void old_and_busted(int n) {
  int count = 0;
  for (int z = 1; ; ++z) {
    for (int x = 1; x < z; ++x) {
      for (int y = x; y < z; ++y) {
        if (x*x + y*y == z*z) {
          std::cout << '(' 
                    << x << ','
                    << y << ','
                    << z << ')' << '\n';
          ++count;
          if (count >= n)
            return;
        }
      }
    }
  }
}
