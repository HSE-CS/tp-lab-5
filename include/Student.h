// Copyright 2021 Shaidi
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_ 
#include <string>
#include <vector>

class Group;

class Student {
 private:
  int id;
  std::string fio;
  Group* group;
  std::vector<int> marks;

 public:
  explicit Student(std::string fio, unsigned int id);
  unsigned int get_id() const;
  std::string get_fio() const;
  void add_to_group(Group* group);
  double get_average_mark() const;
  void add_mark(int mark);
};
#endif  // INCLUDE_STUDENT_H_
