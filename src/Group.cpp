//  Copyright © 2021 Ksuvot. All rights reserved.

#include "Group.h"
#include <ctime>
#include <random>
#include <iterator>

bool Group::isEmpty() {
  return students.size() ? true : false;
}

void Group::chooseHeadmen() {
  std::srand(time(0));
  head = students[std::rand() % students.size()];
}

double Group::getAverageMark() {
  double sum = 0;
  for (auto student : students)
    sum += student->getAverageMark();
  return students.size() ? sum / students.size() : 0;
}

Student * Group::getStudent(int id) {
  for (auto student : students)
    if (student->id == id)
      return student;
  return new Student(0, "WRONG!");
}

void Group::setStudent(Student *student) {
  students.push_back(student);
  student->setGroup(this);
}

void Group::removeStudent(Student *student) {
  auto it = std::find(students.begin(), students.end(), student);
  if (it != students.end())
    students.erase(it);
}

Student * Group::getStudent(std::string fio) {
  for (auto student : students)
    if (student->fio == fio)
      return student;
  return new Student(0, "WRONG!");
}

std::vector<Student *> Group::includeStudents() {
  return students;
}

Group::Group(std::string title, std::string spec) {
  this->title = title;
  this->spec = spec;
}
