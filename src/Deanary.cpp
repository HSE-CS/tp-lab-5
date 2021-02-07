// Copyright 2021 alexgiving

#include "Deanary.h"

#include <string>
#include <iostream>
#include <fstream>

void Deanary::add_student(Student* _student, const std::string& _spec) {
  for (auto & group : groups) {
    if (group.get_spec() == _spec)
      group.add_student(_student);
  }
}

void Deanary::add_group(const Group& _group) {
  groups.push_back(_group);
}

void Deanary::distribution_of_students() {
  for (auto & student : Students)
    groups[std::rand() % groups.size()].add_student(& student);
}

void Deanary::add_marks() {
  for (auto & group : groups) {
    for (auto & student : group.students) {
      for (int i = 0; i < 15; i++)
        student->add_mark(std::rand() % 10 + 1);
    }
  }
}

double Deanary::get_statistic_students(const std::string& _name) {
  for (auto & group : groups) {
    for (auto & student : group.students) {
      if (student->get_name() == _name)
        return student->average_mark();
    }
  }
}

double Deanary::get_statistic_groups(const std::string& _spec) {
  for (auto & group : groups) {
    if (group.get_spec() == _spec)
      return group.average_mark();
  }
}

void Deanary::move_student(const std::string& _name, const std::string& _spec) {
  for (auto & prewGroup : groups) {
    for (auto & student: prewGroup.students) {
      if (student->get_name() == _name) {
        for (auto & newGroup : groups) {
          if (newGroup.get_spec() == _spec) {
            newGroup.add_student(student);
            prewGroup.remove_student(student);
          }
        }
      }
    }
  }
}

void Deanary::student_expulsion(const std::string& _name) {
  for (auto & group : groups) {
    for (auto & student : group.students) {
      if (student->get_name() == _name) {
        group.remove_student(student);
      }
    }
  }
}

void Deanary::choice_headman() {
  for (auto & group : groups)
    group.choose_headman();
}

void Deanary::print() {
  for (auto & group : groups) {
    std::cout << "=============================================" << std::endl;
    std::cout << "Специальность группы: " << group.get_spec() << std::endl;
    std::cout << "Название группы: " << group.get_title() << std::endl;
    std::cout << "Староста: " << group.headman->get_name() << std::endl;
    std::cout << "Список студентов: " << std::endl;
    for (auto & student : group.students) {
      std::cout << "  * " << student->get_name() << std::endl;
    }
    std::cout << "=============================================" << std::endl;
  }
}

void Deanary::save_to_file() {
  std::ofstream fout;
  fout.open("output.txt");

  for (auto & group : groups) {
    fout << group.get_title() << std::endl;
    fout << group.get_spec() << std::endl;
    fout << std::endl;
    for (auto & student : group.students)
      fout << student->get_name() << student->average_mark() << std::endl;
    fout << std::endl;
  }
  fout.close();
}

void Deanary::students_from_file() {
  std::string name;
  std::ifstream file("students.txt");
  int id = 0;
  while (getline(file, name)) {
    id++;
    Student student_new(id, name);
    Students.push_back(student_new);
  }
}
void Deanary::groups_from_file() {
  std::string spec;
  std::string title;
  std::ifstream file("groups.txt");
  while (getline(file, spec)) {
    getline(file, title);
    Group group_new(title, spec);
    groups.push_back(group_new);
  }
}