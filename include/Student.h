// Copyright Nikita Demashow 2021
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include<string>
#include<iostream>
#include<sstream>
#include <stdlib.h>
#include<vector>

class Group;
class Deanary;

static unsigned int s_id{ 1 };

class Student {
 private:
  Group* group{NULL};
  unsigned int id;
  std::string fio;
  std::vector<int16_t> marks;
  int16_t iq{0};
  void addMark(const int16_t);
  void addToGroup(Group* newGroup);
 public:
  explicit Student(const std::string newFio, const unsigned int id = s_id++);
  double getAverageMark() const;
  bool isHeadOfGroup() const;
  ~Student(){};

  std::string getMarks() const;
  unsigned int getId() const;
  std::string getFio() const;
  friend Deanary;
};
#endif  // INCLUDE_STUDENT_H_
