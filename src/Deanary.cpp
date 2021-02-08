// Copyright 2021

#include "Deanary.h"
#include "Student.h"
#include "Group.h"
#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>

void Deanary::create_group_from_file(std::string file_name) {
  std::ifstream input_file(file_name);
  if (input_file.is_open()) {
    std::string spec;
    std::string title;
    std::string fio;
    std::string id;
    getline(input_file, spec);
    getline(input_file, title);
    create_group(title, spec);
    while (getline(input_file, fio, ' ')) {
      getline(input_file, id);
      groups[groups.size() - 1]->
             add_student(new Student(atoi(id.c_str()), fio));
    }
  }
}

void Deanary::add_marks_to_all() {
  for (auto group : groups) {
    for (auto student : group->students) {
      student->add_mark(std::rand() % 11);
    }
  }
}

void Deanary::init_heads() {
  for (auto group : groups) {
      group->choose_head();
  }
}

void Deanary::hire_student(Student* student, std::string title) {
  for (auto group : groups) {
    if (group->title == title)
      group->add_student(student);
  }
}

void Deanary::fire_student(Student* stud) {
  for (auto group : groups) {
    for (auto student : group->students) {
      if (student->get_id() == stud->get_id())
        group->remove_student(student);
    }
  }
}

void Deanary::create_group(std::string title, std::string spec) {
    groups.push_back(new Group(title, spec));
}

void Deanary::move_student(int id, std::string title) {
  auto group = get_group(title);
  auto student = group->get_student(id);
  if (group && student) {
    student->group->remove_student(student);
    group->add_student(student);
  }
}

Group* Deanary::get_group(std::string title) {
  for (auto group : groups) {
    if (group->get_title() == title)
      return group;
  }
  return nullptr;
}

bool comp(Student* st1, Student* st2) {
  return st1->get_average_mark() > st2->get_average_mark();
}

void Deanary::get_statistics() {
  for (auto group : groups) {
    sort(group->students.begin(), group->students.end(), comp);
    for (auto student: group->students) {
      std::cout << student->fio << '\t' <<
      student->get_average_mark() << std::endl;
    }
    std::cout << std::endl;
  }
}
