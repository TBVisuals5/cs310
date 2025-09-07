#include "course.hpp"

int main() {
  try {
    Student s1(1,"Alice","alice@uni.edu",2026, {"CS101"});
    Student s2(2,"Bob","bob@uni.edu",2027, {"CS101"});
    Instructor instr(10,"Grace","grace@uni.edu","Room 101", {"CS101"});

    Course c("CS101", instr, {s1, s2});

    std::cout << "Course JSON:\n" << c.to_json().dump(2) << "\n\n";
    std::cout << "Course YAML:\n" << YAML::Dump(c.to_yaml()) << "\n";
    std::cout << "Course CSV:\n" << c.csv_header() << "\n" << c.csv_row() << "\n";

  } catch (const ValidationError& e) {
    std::cerr << "ValidationError: " << e.what() << "\n";
  }
}
