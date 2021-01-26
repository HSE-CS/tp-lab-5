// Copyright 2020 Stanislav Stoianov

#ifndef TP_LAB_5_INCLUDE_GROUP_H_
#define TP_LAB_5_INCLUDE_GROUP_H_

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
  Group(std::string t);

  Group(std::string t, std::string s);

  void addStudent(Student* student);

  void chooseHead(Student * student);

  Student *containsStudent(int id);

  Student* containsStudent(const std::string &fio);

  double getAverageMark();

  void removeStudent(Student *student);

  const std::string &getTitle() const;

  const std::string &getSpec() const;

  const std::vector<Student *> &getStudents() const;

  Student *getHead() const;

};

#endif //TP_LAB_5_INCLUDE_GROUP_H_
