// Copyright 2021 LongaBonga
#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include "Group.h"
#include <random>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <vector>



class Student;
class Group;

class Deanery {
 private:
  int id;
  std::vector<Group*>* groups;

 public:
  Deanery();                                                       // Done
  void createGroups();                                             // Done
  void hireStudents();                                             // Done
  void addMarksToAll(int value);                                   // Done
  void getStatistics();                                            // Done
  void moveStudent(int _id, const std::string& title);            // Done
  void moveStudent(const std::string&
                  name, const std::string& title);  // Done
  // void saveStaff();
  void initHeads();
  void saveStuff();                              // Done
  void fireStudents(int student_id);               // Doen
  void fireStudents(const std::string& student_fio);     // Done
  Group& getGroup(const std::string& title);       // Done
  Group& groupByStudent(int _id);                  // Done
  Group& groupByStudent(const std::string& name);
  std::vector<Group *> *getGroups() const;  // Done
};

#endif  // INCLUDE_DEANERY_H_
