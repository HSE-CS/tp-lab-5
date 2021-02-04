//Copyright 2021 Nikita Naumov
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"

class Student;

class Group {
 public:
  Group();
  ~Group();

 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

};

#endif  // !INCLUDE_GROUP_H_
