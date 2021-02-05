// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 29.01.2021.
//

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <fstream>

class Group;
class Student;

class Deanary {
 public:
  Deanary() = default;
  Group* create_group(const std::string&str);
  Student* hire_student(uint64_t, const std::string&, const std::string&);
  void add_marks_to_all(int);
  std::string get_statistics() const;
  void move_student(uint64_t, const std::string&);
  void save_staff(const std::string&) const;
  void init_heads();
  void fire_student(uint64_t);
  void from_file(const std::string&);

 private:
  Group* find_group(const std::string&);
  Student* find_student(uint64_t);
  std::vector<Group*> groups;
};

#endif  // INCLUDE_DEANARY_H_
