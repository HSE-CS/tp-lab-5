// Copyright 2021 Lab_5 TiNa
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include <string>
#include <vector>
#include "Student.h"
#include "Group.h"

class Student;
class Group;
class Deanery {
 private:
     std::vector<Group*> groups;

 public:
     void hireStudents();
     void distribStud(std::vector<Student*> new_students);
     void createGroups();
     void addMarksToAll();
     void getStatistics();
     void moveStudents(int id, std::string title_from, std::string title_to);
     void fireStudent();
     void saveStaff();
     void initHeads();
};

#endif  // INCLUDE_DEANARY_H_
