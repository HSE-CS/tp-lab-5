// Copyright Nikita Demashow 2021
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_
#include<vector>
#include<string>
#include<fstream>
class Group;
class Student;

class Deanary {
 private:
  std::vector<Group*> groups;
 public:
  void createGroups(const std::string& dir);
  void hireStudents(const std::string& dir);
  void addMarksToAll();
  void getStatistics();
  void initHeads();
  void moveStudets(const unsigned int id, const std::string title);
  void saveStaff(const std::string dir);
  void fireStudent(Student* st);

  int getCntGroups();
  void addGroup(Group*);
};

#endif  // INCLUDE_DEANARY_H_
