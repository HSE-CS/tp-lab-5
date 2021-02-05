//  Copyright © 2021 Ksuvot. All rights reserved.

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <vector>
#include <string>
#include "Student.h"

class Student;
class Deanary;

class Group {
  friend class Student;
  friend class Deanary;

 private:
  Student * head;
  std::string spec;
  std::string title;
  std::vector<Student *> students;

 public:
  bool isEmpty();
  void chooseHeadmen();
  double getAverageMark();
  Student * getStudent(int id);
  void setStudent(Student *student);
  void removeStudent(Student *student);
  Student * getStudent(std::string fio);
  std::vector<Student *> includeStudents();
  Group(std::string title, std::string spec);
};

#endif // INCLUDE_GROUP_H_
