// Copyright 2020 S. BOR

#include "Group.h"
#include <algorithm>
#include <iterator>
#include <random>
#include <ctime>

Group::Group(std::string title, std::string spec) {
  this->title = title;
  this->spec = spec;
  students.resize(0);
}

Student * Group::getStudent(int id) {
  for (auto student : students)
      if (student->id == id)
          return student;
  return new Student(0, "error");
}

Student * Group::getStudent(std::string fio) {
  for (auto student : students)
      if (student->fio == fio)
          return student;
  return new Student(0, "error");
}

std::vector<Student *> Group::containsStudents() {
  return students;
}

bool Group::isEmpty() {
  return students.size() ? true : false;
}
void Group::addStudent(Student *student) {
  students.push_back(student);
  student->addToGroup(this);
}

void Group::removeStudent(Student *student) {
  auto it = std::find(students.begin(), students.end(), student);
  if (it != students.end())
    students.erase(it);
}

void Group::chooseHead() {
  std::srand(time(0));
  head = students[std::rand() % students.size()];
}

double Group::getAverageMark() {
  double aver = 0;
  for (auto student : students)
    aver += student->getAvarageMark();
  return students.size() ? aver / students.size() : 0;
}
