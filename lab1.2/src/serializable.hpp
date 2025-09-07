#pragma once
#include <string>
#include <nlohmann/json.hpp>
#include <yaml-cpp/yaml.h>

struct Serializable {
  virtual ~Serializable() = default;
  virtual nlohmann::json to_json() const = 0;
  virtual YAML::Node     to_yaml() const = 0;
  virtual std::string    csv_header() const = 0;
  virtual std::string    csv_row() const = 0;
};

std::vector<std::unique_ptr<Serializable>> objects;
objects.push_back(std::make_unique<Student>(...));
objects.push_back(std::make_unique<Instructor>(...));
objects.push_back(std::make_unique<Course>("CS101", instr, roster));

for (const auto& obj : objects) {
    auto j = obj->to_json();   // works for Course/Student/Instructor
}
