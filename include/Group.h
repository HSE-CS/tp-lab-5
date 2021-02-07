// Copyright Nikita Demashow 2021
#ifndef GROUP_H_
#define GROUP_H_
#include<string>
#include<vector>
#include<iostream>

class Student;
class Deanary;

class Group {
 private:
  const static unsigned int limit{5};
  std::string title;
  std::string spec;
  std::vector<Student*> students;
  Student* head{NULL};

  void addStudent(Student* newSt);
  void choseHead();
  void removeStudent(std::string);

 public:
  explicit Group(){};
  explicit Group(const std::string newTitle, const std::string newSpec):
	  title(newTitle), spec(newSpec) {};
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

#endif // GROUP_H_
