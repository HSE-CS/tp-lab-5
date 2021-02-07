// Copyright 2021 TimurZaytsev

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;

class Student {
 public:
  double get_average_mark() const;
  bool is_head() const;
  friend class Group;
  friend class Deanary;

 private:
  Student(uint64_t, const std::string&, Group* = nullptr);
  void add_mark(int);
  std::string name;
  uint64_t id;
  Group* group;
  std::vector<int> marks;
};

#endif  // INCLUDE_STUDENT_H_
