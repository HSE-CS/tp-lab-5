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
  Student *GetHead() const;
  Student * getStudent(int id);
  void setStudent(Student *student);
  const std::string &GetSpec() const;
  const std::string &GetTitle() const;
  void removeStudent(Student *student);
  Student * getStudent(std::string fio);
  std::vector<Student *> includeStudents();
  Group(std::string title, std::string spec);
  const std::vector<Student *> &GetStudents() const;
};

#endif  // INCLUDE_GROUP_H_
