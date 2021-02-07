// Copyright 2021 Galex

#ifndef TP_LAB_5_INCLUDE_STUDENT_H_
#define TP_LAB_5_INCLUDE_STUDENT_H_

#include <vector>
#include <string>

class Group;
class Student {
 private:
  unsigned int id;
  std::string fio;
  Group *group;
  std::vector<int> marks;
  bool head;

 public:
  Student(unsigned int id, std::string fio);
  void add2group(Group *group);
  void remove();
  void addMark(int mark);
  double getAverage();
  void setHead(bool isTrue);
  bool isHead();
  unsigned int getId();
  bool isAnyMarks();
  std::string getName();
  std::string getMarks2String();
};
#endif  // TP_LAB_5_INCLUDE_STUDENT_H_
