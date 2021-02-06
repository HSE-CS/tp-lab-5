// Copyright 2021 Dev-will-work
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <string>
#include <vector>
class Group;
class Student {
 public:
  friend class Deanary;
  friend class DeanFactory;
  int operator[](int);  // get by index
  bool operator==(const Student& arg);
  bool operator!=(const Student& arg);
  float getAveragemark();
  uint64_t getId();
  std::string getName();
  bool isHeadOfGroup();
  size_t size();

  friend std::ostream& operator<<(std::ostream&, Student&);  // output

 private:
  uint64_t id;  // constructor(create_id)
  std::string fio;  // constructor
  Group* group = nullptr;  // AddToGroup
  std::vector<int> marks;  // addmark

  Student(std::string&, uint64_t);
  int addToGroup(Group*);
  void addmark(int);
};
#endif  // INCLUDE_STUDENT_H_
