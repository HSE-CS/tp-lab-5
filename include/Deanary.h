//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <string>
#include <vector>

#include "Student.h"
#include "Group.h"


class Deanary {
 private:
  std::vector<Group*> groups_;
  std::vector<Student*> all_students_;
 public:
  Deanary() {}
  void hireStudents(std::string file_name);
  void createGroups(std::string file_name);
  void addMarksToAll(int marks_num=10, int bias=5);
  void getStatistics();
  void moveStudent(Student* student, Group* new_group);
  void saveStuff(std::string path);
  void initHeads();
  void fireStudent(float min_avg_mark);
  int getStudentsNum() const { return all_students_.size(); }
  int getGroupsNum() const { return groups_.size(); }
  Group getGroup(int index=-1, std::string title="") const;
};

#endif  // INCLUDE_DEANARY_H_
