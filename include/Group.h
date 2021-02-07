// Copyright 2021 Pavlova D.

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include "Student.h"
#include <string>
#include <vector>

class Student;
class Group {
  friend class Student;

private:
  std::string spec;
  std::string title;
  Student *head;

public:
  std::vector<Student *> students;
  Group(std::string title_, std::string spec_) : title(title_), spec(spec_){};
  void addStudents(Student *student);
  void chooseHead();
  double getAverageMark();
  int containsStudent(Student student);
  void removeStudent(int _id);
  bool isEmpty();
  Student &getHead() { return *this->head; }
  std::string getTitle() { return this->title; }
  std::string getSpec() { return this->spec; }
};
#endif // INCLUDE_GROUP_H_
