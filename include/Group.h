// Copyright 2020 me
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include<string>
#include<vector>
#include "Student.h"
#include "Deanary.h"

class Student;
class Deanary;

class Group {
  friend class Deanary;
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> *students;
  Student* head;

 public:
  Group(std::string sp, std::string tit) {
    students = new std::vector<Student*>();
    spec = sp;
    title = tit;
  }
  ~Group() {
    students->clear();
  }
  void chooseHead();
  void removeStudent(unsigned st_id);
  void removeStudent(Student* st);
  void addStudent(Student *new_student);
  double getAveragemark();
  Student* getStudentById(unsigned id);
  std::vector<Student*> containsStudent();
  Student* getHead();
  bool isEmpty();
};

#endif  // INCLUDE_GROUP_H_
