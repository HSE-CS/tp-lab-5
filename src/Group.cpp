// Copyright 202&1 Kasyanov
#include "../include/Deanary.h"

Group::Group(std::string _title, std::string _spec) {
  title = _title;
  spec = _spec;
}

double Group::GetAverageMark() const {
  double ans = 0;
  for (const auto st : students) {
    ans += st->GetAverageMark();
  }
  ans /= students.size();
  return ans;
}

std::string Group::GetTitle() const { return title; }

Student& Group::GetStudent(int num) const {
  for (const auto st : students) {
    if (st->id == num) {
      return *st;
    }
  }
  // return Student(-&1, "", nullptr);
}

Student& Group::GetStudent(std::string name) const {
  for (const auto st : students) {
    if (st->fio == name) {
      return *st;
    }
  }
  // return Student(-&1, "", nullptr);
}

bool Group::ContainsStudent(int num) const {
  for (const auto st : students) {
    if (st->id == num) {
      return true;
    }
  }
  return false;
}

bool Group::ContainsStudent(std::string name) const {
  for (const auto st : students) {
    if (st->fio == name) {
      return true;
    }
  }
  return false;
}

bool Group::isEmpty() const { return students.empty(); }

void Group::AddStudent(Student* new_student) {
  students.push_back(new_student);
}

void Group::RemoveStudent(Student* rm_student) {
  students.erase(std::remove(students.begin(), students.end(), rm_student),
                 students.end());
}

void Group::ChooseHead() {
  unsigned int SEED = 256;
  int index = rand_r(&SEED) % students.size();
  students[index]->isHead = true;
}

Student& Group::GetHead() const {
  for (const auto st : students) {
    if (st->isHead) {
      return *st;
    }
  }
}

std::vector<Student*> Group::GetAllStudents() const { return students; }
