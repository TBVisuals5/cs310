#include <catch2/catch_test_macros.hpp>
#include "student.hpp"
#include "instructor.hpp"

TEST_CASE("Student JSON serialization") {
  Student s(10,"Alice","alice@uni.edu",2027, {"CS101","HIST110"});
  auto j = s.to_json();
  CHECK(j.at("role") == "Student");
  CHECK(j.at("name") == "Alice");
  CHECK(j.at("grad_year") == 2027);
}

TEST_CASE("Instructor YAML serialization") {
  Instructor i(11,"Bob","bob@uni.edu","C-210", {"CS101"});
  auto y = i.to_yaml();
  CHECK(y["role"].as<std::string>() == "Instructor");
  CHECK(y["office"].as<std::string>() == "C-210");
}

TEST_CASE("CSV escaping handles commas and quotes") {
  Student s(12,"Eve, \"The Great\"","eve@uni.edu",2028, {"CS,101","AI\"Lab"});
  auto row = s.csv_row();
  REQUIRE(row.find("\"Eve, \"\"The Great\"\"\"") != std::string::npos);
}

TEST_CASE("Validation throws on bad email") {
  REQUIRE_THROWS_AS(Student(13,"Zed","not-an-email",2026), ValidationError);
}

TEST_CASE("Round-trip Student JSON") {
  Student s(1,"Test","t@uni.edu",2025, {"CS101"});
  auto j = s.to_json();
  auto s2 = Student::from_json(j);
  CHECK(s2.to_json() == j);
}

TEST_CASE("Round-trip Instructor JSON") {
  Instructor i(2,"Prof","p@uni.edu","R-101", {"CS101"});
  auto j = i.to_json();
  auto i2 = Instructor::from_json(j);
  CHECK(i2.to_json() == j);
}

TEST_CASE("Bad Student JSON throws") {
  nlohmann::json j = {{"role","Student"}}; // missing required fields
  REQUIRE_THROWS_AS(Student::from_json(j), ValidationError);
}

TEST_CASE("Course serialization works") {
  Student s1(1,"Alice","alice@uni.edu",2026);
  Instructor instr(10,"Grace","grace@uni.edu","Room 101");
  Course c("CS101", instr, {s1});

  auto j = c.to_json();
  CHECK(j["title"] == "CS101");
  CHECK(j["instructor"]["name"] == "Grace");
  CHECK(j["roster"][0]["name"] == "Alice");
}
