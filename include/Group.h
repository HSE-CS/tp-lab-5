// Copyright 2021 Dev-will-work
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <string>
#include <vector>

class Student;

class Group {
 public:
  friend class Deanary;
  friend class DeanFactory;
  ~Group();
  Student* operator[](int);  // get by index
  float getAverageMark();
  Student* getStudent(std::string);
  Student* getStudent(uint64_t);
  std::string getName();
  std::string getSpec();
  bool containsStudent(Student*);
  bool containsStudent(std::string);
  bool containsStudent(uint64_t);
  Student* getHead();
  bool isEmpty();
  size_t size();

 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head = nullptr;

  explicit Group(std::string, std::string);
  int addStudent(Student*);
  void chooseHead();
  int removeStudent(Student*);
  int removeStudent(std::string);
  int removeStudent(uint64_t);
};
#endif  // INCLUDE_GROUP_H_
