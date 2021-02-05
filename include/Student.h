// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_
#include <vector>
#include <string>

class Group;

class Student {
 private:
  unsigned int id;
  std::string spec;
  std::string fio;
  std::vector <unsigned int> marks;
  Group* group;
  bool isHead;
 public:
  Student(unsigned int id, std::string fio,
          std::vector <unsigned int> marks, std::string spec);
  void addMark(unsigned int mark);
  double getAverage();
  bool isHeadOfGroup() const;
  void addToGroup(Group* group);
  std::string getFio() const;
  unsigned int getId() const;
  std::string getSpec() const;
  void initHead();
  std::vector<unsigned int> getMarks() const;
};


#endif  // INCLUDE_STUDENT_H_

