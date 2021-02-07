// Copyright 2021 Bulatov D.
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <string>
#include <vector>
#include "Group.h"
#include "Student.h"

class Student;
class Group;
class Deanary {
 private:
  std::vector<Group> groups;
  std::vector<Student> students;

 public:
  void createGroups();
  void addGroup(const Group& group);
  std::vector<Group> getGroups(); 
  void addStudent(const Student& student);
  void hireStudents();
  void addMarks();
  std::string getStatisticsByStudent(std::string fio);
  std::string getStatisticsByGroup(std::string spec);
  void moveStudent(std::string fio, std::string spec);
  void fireStudent();
  void moveStudents();
  void initHead();
  void saveStuff();
  void printInfo();
};
#endif  // INCLUDE_DEANARY_H_
