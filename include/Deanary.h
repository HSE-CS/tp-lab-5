//Copyright 2020 Uskova
#ifndef INCLUDE_DEANARY_H_
#define  INCLUDE_DEANARY_H_
 
#include <string>
#include <vector>
#include "Group.h"
#include "Student.h"

class Group;
class Student;

class Deanary {
 private:
     std::vector <Group*> groups;
 public:
     Deanary();
     std::vector<Student*> hireStudents(const char*);
     void createGroups(const char*, std::vector <Student*>);
     void addMarks(int);
     void getStatistic(const char*);
     void moveStudents(Student*, Group*);
     void fireStudents();
     bool saveChangesInFile(const char*);
     void initHeads();
     void showData();
     Student* findId(int);
     Group* findGr(std::string, std::string);
};


#endif  // INCLUDE_DEANARY_H_
