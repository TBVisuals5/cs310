#include "student.hpp"

static Student from_json(const nlohmann::json& j) {
  if (!j.contains("id") || !j.contains("name") || !j.contains("email") || !j.contains("grad_year"))
    throw ValidationError("Missing required Student field");

  return Student(
    j.at("id").get<int>(),
    j.at("name").get<std::string>(),
    j.at("email").get<std::string>(),
    j.at("grad_year").get<int>(),
    j.value("courses", std::vector<std::string>{})
  );
}


// Nothing to implement out-of-line for this lab; provided so core library has an object file.