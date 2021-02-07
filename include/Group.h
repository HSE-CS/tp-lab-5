// Copyright 2020 Polina Lukicheva
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Students.h"
#include <string>
#include <vector>

class Group {
  friend class Deanary;
private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;
  Group(std::string, std::string);
  ~Group();
  void addStudent(Student*);
  void chooseHead();
  void removeStudent(Student *);
public:
  bool isEmpty();
  Student* getStudent(int);
  Student* getHead();
  bool containsStudent(Student*);
  float getAverageMark();
};
#endif  // INCLUDE_GROUP_H_

