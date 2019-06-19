//-std=c++2a -I/opt/compiler-explorer/libs/cmcstl2/include -fconcepts
#include <vector>
#include <experimental/ranges/algorithm> // from cmcstl2
namespace ranges = std::experimental::ranges;

//std::ranges::for_each(), better than std::for_each()

struct MyType {
    void method();
    MyType* begin();
    MyType* end();
};

void old_and_busted() {
    std::vector<MyType> v;
#if 0
    //LOLNOPE
    std::for_each(v.begin(), v.end(), &MyType::method);
#else
    std::for_each(v.begin(), v.end(), std::mem_fn(&MyType::method));
#endif
}

void new_hotness() {
    std::vector<MyType> v;
    //no problem, std::ranges::for_each uses std::invoke
    ranges::for_each(v, &MyType::method);
}
