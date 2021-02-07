  //  Copyright 2021 Nikita Naumov
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <iostream>
#include <fstream>
#include <typeinfo>
#include <cstdlib>
#include <ctime>
#include "Student.h"
#include "Group.h"

class Student;
class Group;

class Deanary {
 public:
  Deanary();
  ~Deanary();
  void initialiseStudents();
  void createGroups();
  void addRandomMarks(Student*, int);
  double getStudentStatistic(Student*);
  double getGroupStatistic(Group*);
  void moveStudent(Student*, Group*);
  void fireForAcademicFailure();
  void initialiseElection();
  void printAllInfo();
  void saveChanges();
  double getCurrentAmountOfStudents();
  double getCurrentAmoutOfGroups();
  Student* getStudentAddress(unsigned);
  Group* getGroupAddress(unsigned);
  void addStudentToGroup(Student*, Group*);
  void addStudent(Student*);
  void addGroup(Group*);

 private:
  std::vector<Student*> allStudents;
  std::vector<Group*> groups;
  unsigned numberOfStudents;
  void addStudentToRandomGroup(Student*);
};



#endif  // INCLUDE_DEANARY_H_
