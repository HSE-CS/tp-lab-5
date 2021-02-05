// Copyright 2020 Konina Tatiana
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include <map>

class Student;

class Group {
 private:
  std::map <unsigned int, Student*> students;
  Student* head;
  unsigned int title;
  std::string spec;
 public:
  Group(std::string spec, unsigned int groupNum);
  bool addStudent(Student* student);
  void chooseHead();
  bool isEmpty();
  bool removeStudent(unsigned int id);
  double getAverageMarks();
  Student* search(unsigned int id);
  int getHead();
  std::map <unsigned int, Student*> getStudents();
  std::string getSpec() const;
  unsigned int getTitle() const;
  int getGroupSize();
};

#endif  // INCLUDE_GROUP_H_

