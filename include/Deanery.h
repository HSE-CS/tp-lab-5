#pragma once

#include <fstream>
#include <string>

#include "Group.h"
#include "Student.h"

class Deanery {
 private:
  std::vector<Group> groups;

 public:
  Deanery();
  void addGroup(Group& group);
  static void addStudentToGroup(Group* group, const Student& student);
  static void addMarkToStudent(Student& student, int mark);
  void initFromFile(std::ifstream file);
  void printInfo() const;
  void removeFailingStudents();
  void moveStudent(int id, const std::string& from_title,
                   const std::string& to_title);
  void saveToFile(std::ofstream file) const;
  std::vector<Group>& getGroups() { return groups; };
  void reelectHeads();
};