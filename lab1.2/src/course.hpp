#pragma once
#include "serializable.hpp"
#include "student.hpp"
#include "instructor.hpp"
#include "csv.hpp"

class Course : public Serializable {
  std::string title_;
  Instructor instructor_;
  std::vector<Student> roster_;

public:
  Course(std::string title, Instructor instructor, std::vector<Student> roster = {})
    : title_(std::move(title)), instructor_(std::move(instructor)), roster_(std::move(roster)) {
    if (title_.empty()) throw ValidationError("Course title required");
  }

  // Accessors
  const std::string& title() const { return title_; }
  const Instructor& instructor() const { return instructor_; }
  const std::vector<Student>& roster() const { return roster_; }

  // JSON
  nlohmann::json to_json() const override {
    nlohmann::json j;
    j["title"] = title_;
    j["instructor"] = instructor_.to_json();
    j["roster"] = nlohmann::json::array();
    for (const auto& s : roster_) j["roster"].push_back(s.to_json());
    return j;
  }

  // YAML
  YAML::Node to_yaml() const override {
    YAML::Node n;
    n["title"] = title_;
    n["instructor"] = instructor_.to_yaml();
    for (const auto& s : roster_) n["roster"].push_back(s.to_yaml());
    return n;
  }

  // CSV (flattened form)
  std::string csv_header() const override {
    return "course_title,instructor_name,instructor_email,student_names";
  }

  std::string csv_row() const override {
    std::string students;
    for (size_t i=0;i<roster_.size();++i) {
      if (i) students += ';';
      students += roster_[i].name();
    }
    return csv_escape(title_) + "," +
           csv_escape(instructor_.name()) + "," +
           csv_escape(instructor_.email()) + "," +
           csv_escape(students);
  }
};
