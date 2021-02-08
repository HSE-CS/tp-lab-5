// Copyright Nikita Demashow 2021
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include<string>
#include<vector>
#include<random>
#include<iostream>

class Student;
class Deanary;

class Group {
  const static unsigned int limit{5};
 private:
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head{NULL};

  void addStudent(Student* newSt);
  void choseHead();
  void removeStudent(std::string);

 public:
  Group() {}
  explicit Group(const std::string newTitle, const std::string newSpec):
  title(newTitle), spec(newSpec) {}
  Student* getHead() const;
  double getAverageMark();
  Student* getStudentById(const unsigned int id);
  Student* getStudentByFio(const std::string fio);
  // bool conteinsStudent(std::string);
  bool isEmpty();
  bool isFull();
  std::string getSpec() const;
  std::string getTitle() const;
  friend Deanary;
};

#endif  // INCLUDE_GROUP_H_
