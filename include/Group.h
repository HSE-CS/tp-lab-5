// Copyright 2021 shaidi
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <string>
#include <vector>
#include "Student.h"

class Student;
class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

 public:
  explicit Group(std::string title, std::string spec);
  std::string get_title() const;             
  std::string get_spec() const;            
  std::string get_name_of_head() const;     
  std::vector<Student*> get_students() const;
  void add_student(Student* student);
  void remove_student(Student* student);
  void head_choice();
  double average_group_mark() const;
  Student* search_by_fio(std::string fio) const;
  Student* search_by_id(int id) const;
};
#endif  // INCLUDE_GROUP_H_
