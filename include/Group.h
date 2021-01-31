//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

#include "Student.h"

class Deanary;

class Group {
 private:
  std::string title_;
  std::string spec_;
  std::vector<Student*> students_;
  void addStudent(Student*);
  void removeStudent(Student*);
  Student* head_;
  void chooseHead(Student*);
  friend class Deanary;

 public:
  Group(std::string new_title, std::string new_spec):
  title_(new_title), spec_(new_spec), head_(nullptr) {}
  Group(const Group& another_group):
  title_(another_group.title_), spec_(another_group.spec_), students_(another_group.students_) {}
  std::string getTitle_() const { return title_; }
  std::string getSpec_() const { return spec_; }
  std::vector<Student*> getStudents() { return students_; };
  int containsStudent(int studentID=-1, std::string fio="");
  Student* getStudent(int index=-1, int studentID=-1, std::string fio="");
  Student* getHead();
  float getAverageMark();
  bool isEmpty();
};

#endif  // INCLUDE_GROUP_H_
