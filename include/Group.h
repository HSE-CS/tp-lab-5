//  Copyright 2020 GHA created by Klykov Anton

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>

class Student;
class Group {
 private:
  std::string title;
  std::string special_on;
  std::vector<Student*> students;
  Student* header;
  void addStudent(Student *st);
  void chooseHeader();
  Student* removeStudent(Student *st);
  void delStudent(Student *st);

 public:
  std::vector<Student*> getStudentsInGroup();
  std::string getTitle();
  explicit Group(const std::string& _title);
  double getAverageMark();
  Student* getStudent(int _id);
  bool containsStudent(Student *st);
  [[nodiscard]] bool isEmpty() const;
  Student* getHeader();
  friend class Deanary;
};

#endif  // INCLUDE_GROUP_H_
