// Copyright 2020 S. BOR
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"

class Student;
class Deanary;

class Group
{
 private:
  std::string title;
  std::string spec;
  std::vector<Student *> students;
  Student * head;
  void chooseHead();
  void addStudent(Student *student);
  void removeStudent(Student *student);
  friend class Student;
  friend class Deanary;

 public:
  Group(std::string title, std::string spec);
  Student * getStudent(int id);
  Student * getStudent(std::string fio);
  std::vector<Student *> containsStudents();
  bool isEmpty();
  double getAverageMark();
};

#endif  // INCLUDE_GROUP_H_
