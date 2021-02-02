//  Copyright © 2020 Сапожников Андрей Михайлович. All rights reserved.

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

#include "Student.h"

class Deanary;

class Group {
 private:
  std::string title_ = "";
  std::string spec_ = "";
  std::vector<Student*> students_;
  void addStudent(Student*);
  void removeStudent(Student*);
  Student* head_ = nullptr;
  void chooseHead(Student*);
  friend class Deanary;
  friend class Student;

 public:
  Group() {}
  Group(std::string new_title, std::string new_spec):
  title_(new_title), spec_(new_spec), head_(nullptr) {}
  Group(const Group& another_group):
  title_(another_group.title_), spec_(another_group.spec_),
  students_(another_group.students_), head_(another_group.head_) {}
  std::string getTitle() const { return title_; }
  std::string getSpec() const { return spec_; }
  int getStudentsNum() const { return this->students_.size(); }
  int containsStudent(int studentID = -1, std::string fio = "") const;
  Student getStudent(int index = -1, int studentID = -1,
                     std::string fio = "") const;
  Student getHead();
  float getAverageMark() const;
  bool isEmpty() const;
};

#endif  // INCLUDE_GROUP_H_
