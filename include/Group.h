// Copyright 2020 GHA Test Team
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <vector>
#include <string>
#include "Student.h"


class Student;

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector <Student*> students;
  Student* head;
  void addStudent(Student*);
  void chooseHead(bool random = false);
  void removeStudentById(int);
  void removeStudentByFio(std::string);

 public:
  Group();
  explicit Group(std::string);
  explicit Group(std::string, std::string);
  std::string getTitle() const;
  Student* getHead() const;
  int getAvarageMark() const;
  Student* getStudentById(int);
  Student* getStudentByFio(std::string);
  bool containsStudent(Student*) const;
  bool isEmpty() const;
  friend class Deanary;
};
#endif  // INCLUDE_GROUP_H_
