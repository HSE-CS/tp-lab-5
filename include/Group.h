// Copyright 2021 Schenikova
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <vector>
#include <string>
#include "Student.h"

class Student;

class Group {
private:
  std::string title;
  std::string spec;
  std::vector <Student*> students;
  Student* head;
public:
  void chooseHead();
  void addStudent(Student*);  
  void removeStudent(Student*);
  Group(std::string title, std::string spec);
  std::string getTitle();
  std::string getSpec();
  Student* getStudentById(int);
  Student* getStudentByFio(std::string);
  float getAveragemark();
  std:: vector <Student *> containsStudent();
  bool isEmpty();
  friend class Student;
  
};

#endif // INCLUDE_GROUP_H_