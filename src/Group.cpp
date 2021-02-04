// Copyright 2021 Kuznetsov Mikhail

#include "Group.h"

Group::Group(std::string _title) {
  title = _title;
}

Group::Group(std::string _title, std::string _spec) {
  title = _title;
  spec = _spec;
}

void Group::addStudent(Student* _student) {
  if (this->getStudent(_student->getId()) == nullptr) {
      students.push_back(_student);
     _student->addToGroup(this);
  }
}

void Group::chooseHead() {
  std::mt19937 gen(time(0));
  std::uniform_int_distribution<> uid(0, students.size() - 1);
  head = students[uid(gen)];
}

float Group::getAveragemark() {
  float sum = 0;
  for (auto s : students) {
    sum += s->getAveragemark();
  }
  return students.size() ? sum / students.size() : 0;
}

Student* Group::getStudent(unsigned int _id) {
    for (auto s : students) {
        if (s->getId() == _id) {
            return s;
        }
    }
    return nullptr;
}

Student* Group::getStudent(std::string _fio) {
    for (auto s : students) {
        if (s->getFio() == _fio) {
            return s;
        }
    }
    return nullptr;
}
Student* Group::getHead() {
  return head;
}
std::vector <Student*> Group::containsStudents() {
  return students;
}

std::string Group::getTitle() {
  return title;
}

std::string Group::getSpec() {
  return spec;
}

void Group::removeStudent(Student *_student) {
  _student->addToGroup(nullptr);
  students.erase(std::remove(students.begin(), students.end(), _student),
                  students.end());
}

bool Group::isEmpty() {
  return !students.size();
}
