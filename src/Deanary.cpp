// Copyright 2021 

#include "Deanary.h"
#include "Student.h"

void Deanary::add_marks_to_all() {
  for (auto group: groups) {
    for (auto student: group->students) {
      student->add_mark(std::rand() % 11);
    }
  }
}

void Deanary::init_heads() {
  for (auto group: groups) {
      group->choose_head();
  }
}

void Deanary::hire_student(Student* student, std::string title) {
  for (auto group: groups) {
    if (group->title == title) 
      group->add_student(student);
  }
}

void Deanary::fire_student(Student* stud) {
  for (auto group: groups) {
    for (auto student: group->students) {
      if (student->get_id() == stud->get_id())
        group->remove_student(student);
    }
  }
}

void Deanary::create_group(std::string title, std::string spec) {
    groups.push_back(new Group(title, spec));
}

void Deanary::move_student(int id, std::string gr) {
  
}
