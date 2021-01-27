// Copyright 2020 Stanislav Stoianov

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
  Student *head{};

 public:
  explicit Group(std::string t);
  Group(std::string t, std::string s);
  void addStudent(Student* student);
  void chooseHead(Student * student);
  Student *containsStudent(int id);
  Student* containsStudent(const std::string &fio);
  double getAverageMark();
  void removeStudent(Student *student);
  const std::string &getTitle() const;
  const std::string &getSpec() const;
  std::vector<Student *> &getStudents();
  Student *getHead() const;

};

#endif  // INCLUDE_GROUP_H_
