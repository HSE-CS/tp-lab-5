// Copyright 2021
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <iostream>
#include <string>
#include <vector>
#include "Student.h"
#include "Group.h"
class Student;
class Group;

class Deanary {
 private:
 std::vector<Group> groups;
 std::vector<Student> students;
 public:
 void createGroups(std::string path);
 void hireStudents(std::string path);
 void addMarkToAll();
 std::string getStatisticsByStudent(std::string fio);
 std::string getStatisticsByGroup(std::string title);
 void moveStudent(std::string fio, std::string title);
 void moveStudents();
 void initHead();
 void saveStuff(std::string path);
 void printInfo();
 void fireStudent();
 void addGroup(Group& group);
 std::vector<Group> getGroups();
 void addStudent(Student& student);
};
#endif // INCLUDE_DEANARY_H_
