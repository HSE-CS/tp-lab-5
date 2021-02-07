////// Copyright 2021 Ozhiganova Polina
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <vector>
#include <string>
#include "Student.h"

class Deanary;
class Group {
  friend class Deanary;
  friend class Student;

 public:
  explicit Group(std::string newTitle,
                 std::string newSpec,
                 const std::vector<Student *> &newStudents,
                 Student *newHead);
  ~Group();
  bool containStudent(int stId);
  Student *getStudent(int stId);
  float getAverageMark();
  bool isEmpty();
  std::vector<Student *> getStudents();
  std::string getSpec();
  std::string getTitle();

 private:
  std::string title;
  std::string spec;
  std::vector<Student *> students;
  Student *head = nullptr;
  void addStudent(Student *st, Group *gr);
  Student *chooseHead(const std::vector<Student *> &newStudents);
  void removeStudent(int stId);
};

#endif  // INCLUDE_GROUP_H_
