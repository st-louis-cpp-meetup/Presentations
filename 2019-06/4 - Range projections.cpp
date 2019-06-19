//-std=c++2a -I/opt/compiler-explorer/libs/cmcstl2/include -fconcepts
#include <iostream>
#include <string>
#include <vector>
#include <experimental/ranges/algorithm> // from cmcstl2
namespace ranges = std::experimental::ranges;

//projections
//"transformation that an algorithm applies before inspecting the values of elements"

struct Employee {
  int id;
  std::string name;
  Employee(int id_, std::string name_): id(id_), name(name_) {}
};


void old_and_busted(std::vector<Employee>& v) {
  std::sort(v.begin(), v.end(), [](Employee a, Employee b) {
    return a.id < b.id;   
  });
}

void new_hotness(std::vector<Employee>& v) {
  ranges::sort(v, ranges::less{}, &Employee::id);
}
 
int main() {    
  std::vector<Employee> employees = {{5, "Kubrick"}, {2, "Burgess"}, {7, "Carlos"} };
  old_and_busted(employees);
  for (auto employee: employees) {
    std::cout << employee.id << " " << employee.name << "\n";
  }

  std::vector<Employee> employees2 = {{5, "Stanley"}, {2, "Anthony"}, {7, "Wendy"} };
  new_hotness(employees2);
  for (auto employee: employees2) {
    std::cout << employee.id << " " << employee.name << "\n";
  }
}

// other ranges versions of most algorithms also support projections: 
// find, for_each, replace_if, etc
