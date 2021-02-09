// Copyright 2021 Shirokov Alexander

#pragma once

#include <vector>
#include <string>
#include <iostream>

class Group;
class Student {
  friend class Group;
  friend class Deanary;
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;
 public:
  explicit Student(int ID, const std::string& FIO);
  void addToGroup(Group* gr);
  void addmark(int mark);
  float getAveragemark();
  bool isHeadOfGroup();
  int getId();
  std::string getName();
};
