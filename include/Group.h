// Copyright 2021 ArinaMonicheva

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include "Student.h"

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;

 public:
  explicit Group(std::string newTitle);
  void addStudent(const Student& newStudent);
  void chooseHead(Student* candidate);
  Student& getStudent(unsigned id) const;
  Student& getStudent(std::string fio) const;
  int containsStudent(unsigned id);
  int containsStudent(std::string fio);
  double getAverageMark();
  void removeStudent(const Student& removalOne);

  friend class Deanery;
};

#endif  // INCLUDE_GROUP_H_
