//-std=c++2a -I/opt/compiler-explorer/libs/cmcstl2/include -fconcepts
#include <vector>
#include <experimental/ranges/ranges> // from cmcstl2
namespace ranges = std::experimental::ranges;

//std::ranges::begin(), better than std::begin()

void old_and_busted() {
    extern std::vector<int> get_data();
    auto it = std::begin(get_data());
    int i = *it; // BOOM
}

#if 0
void new_hotness() {
    extern std::vector<int> get_data();
    auto it = ranges::begin(get_data());
    int i = *it; // BOOM
}
#endif


struct MyType1 {};
MyType1* begin(MyType1) {
    return nullptr;
}
MyType1* end(MyType1) {
    return nullptr;
}
struct MyType2 {
    MyType2* begin() { return nullptr; }
    MyType2* end() { return nullptr; }
};

void old_and_busted_again() {
    MyType1 x1;
    MyType2 x2;
#if 0
    auto it1 = std::begin(x1);
    auto it2 = std::begin(x2);
#endif
    for (auto y1: x1) {}
    for (auto y2: x2) {}
}

void more_new_hotness() {
    MyType1 x1;
    MyType2 x2;
    auto it1 = ranges::begin(x1);
    auto it2 = ranges::begin(x2);
}
