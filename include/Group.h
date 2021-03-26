#pragma once
#include <string>
#include <vector>

#include "Student.h"

class Deanery;

class Group {
  friend Deanery;

 private:
  std::string title;
  std::string speciality;
  std::vector<Student> students = std::vector<Student>();
  Student* head = nullptr;
  void addStudent(const Student& student);
  void removeStudent(int id);
  void selectHead();

 public:
  Group(std::string title, std::string speciality);
  std::vector<Student> getStudentByFio(const std::string& fio) const;
  Student* getStudentById(int id);
  const Student* getHead() const;
  const std::string& getTitle() const { return title; }
  const std::string& getSpeciality() const { return speciality; }
  double averageMark() const;
};
