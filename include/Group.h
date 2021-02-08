// Copyright 2021 Ryzhova
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

class Student;

class Group {
  friend class Student;
  friend class Deanary;

 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;
  void add_student(Student*);
  void choose_head();
  void remove_student(Student*);

 public:
  Group(std::string title, std::string spec);
  bool is_empty();
  std::string get_title();
  std::string get_spec();
  Student* get_student(int);
  double get_avarage_mark();
  bool contains_student(int);
};

#endif  // INCLUDE_GROUP_H_
