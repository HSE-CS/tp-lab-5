// Copyright 2021 Smirnov Grigory
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <random>
#include <cmath>
#include "Student.h"

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

 public:
  Group(std::string title, std::string spec);
  ~Group();
  std::string getTitle();
  std::string getSpec();
  void addStudent(Student* newPerson);
  void chooseHead();
  double getAverageMark();
  Student* getStudent(int id);
  Student* getStudent(std::string fio);
  void removeStudent(int id);
  void removeStudent(std::string fio);
  bool isEmpty();
  Student* getHead();
  int getNumberOfStudents();
  std::string getGroupInfo();
  friend class Deanery;
};
#endif  // INCLUDE_GROUP_H_
