#include "instructor.hpp"

// Nothing to implement out-of-line for this lab; present to create object file.

static Instructor from_json(const nlohmann::json& j) {
  if (!j.contains("id") || !j.contains("name") || !j.contains("email") || !j.contains("office"))
    throw ValidationError("Missing required Instructor field");

  return Instructor(
    j.at("id").get<int>(),
    j.at("name").get<std::string>(),
    j.at("email").get<std::string>(),
    j.at("office").get<std::string>(),
    j.value("teaches", std::vector<std::string>{})
  );
}
