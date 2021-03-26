// Copyright 2021 Shaidi
#include "Group.h"
#include "Student.h"
#include <iostream>

Group::Group(std::string new_fio, std::string new_spec) {
  title = new_fio;
  spec = new_spec;
}

std::string Group::get_title() const {
    return title;
}

std::string Group::get_spec() const {
    return spec;
}

std::string Group::get_name_of_head() const {
    return head->get_fio();
}

std::vector<Student*> Group::get_students() const {
    return students;
}

void Group::add_student(Student* student) {
  students.push_back(student);
  student->add_to_group(this);
}

void Group::remove_student(Student* new_student) {
  for (int i = 0; i < students.size(); i++) {
    if (new_student == students[i]) {
      students.erase(students.begin() + i);
      break;
    }
  }
}

void Group::head_choice() {
  if (!students.empty()) {
    head = students[std::rand() % students.size()];
  }
}

double Group::average_group_mark() const {
  int res = 0, sum = 0;
  for (int i = 0; i < students.size(); i++) {
    sum += students[i]->get_average_mark();
  }
  res = sum / students.size();
  return res;
}


Student* Group::search_by_fio(std::string fio) const {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->get_fio() == fio) {
      return students[i];
      break;
    } else {
      std::cout << "This student is not in this group" << std::endl;
    }
  }
}

Student* Group::search_by_id(int id) const {
  for (int i = 0; i < students.size(); i++) {
    if (students[i]->get_id() == id) {
      return students[i];
    } else {
      std::cout << "This student is not in this group" << std::endl;
    }
  }
}
