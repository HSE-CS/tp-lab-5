// Copyright 2021 Kasyanov
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <algorithm>
#include <ctime>
#include <random>
#include <string>
#include <vector>

#include "ReadGroup.h"
#include "Deanary.h"
#include "Student.h"

class Student;

class Group {
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head;
  void AddStudent(Student*);
  void RemoveStudent(Student*);
  void ChooseHead();

 public:
  Group(std::string, std::string);
  double GetAverageMark() const;
  std::string GetTitle() const;
  Student& GetStudent(int) const;
  Student& GetStudent(std::string) const;
  bool ContainsStudent(int) const;
  bool ContainsStudent(std::string) const;
  bool isEmpty() const;
  Student& GetHead() const;
  std::vector<Student*> GetAllStudents() const;

  friend class Student;
  friend class ReadGroup;
  friend class Deanary;
};

#endif  // INCLUDE_GROUP_H_
