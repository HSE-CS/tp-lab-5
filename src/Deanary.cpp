// Copyright 2021 Drobot E.D.

#include "Deanary.h"
#include <string>
#include <iostream>
#include <fstream>

void Deanary::add_student(Student* student, std::string spec_) {
  for (int i = 0; i < groups.size(); i++) {
    if (groups[i].get_spec() == spec_) {
      groups[i].add_student(student);
    }
  }
}

void Deanary::students_from_file() {
  std::string fio;
  std::ifstream file("students.txt");
  int id = 1;
  while (getline(file, fio)) {
    Student student_new(id, fio);
    Students.push_back(student_new);
    id++;
  }
}

void Deanary::groups_from_file() {
  std::string spec;
  std::string title;
  std::ifstream file("groups.txt");
  while (getline(file, spec)) {
    getline(file, title);
    Group gr(title, spec);
    groups.push_back(gr);
  }
}

void Deanary::distribution_of_students() {
  for (int i = 0; i < Students.size(); i++) {
    int number = std::rand() % groups.size();
    groups[number].add_student(&Students[i]);
  }
}

void Deanary::add_marks() {
  for (int number_group = 0; number_group < groups.size(); number_group++) {
    for (int number_student = 0;
        number_student < groups[number_group].students.size();
        number_student++) {
      for (int i = 0; i < 10; i++) {
        groups[number_group].students[number_student]->add_mark(std::rand() % 10 + 1);
      }
    }
  }
}

double Deanary::get_statistic_students(std::string fio) {
  for (int number_group = 0; number_group < groups.size(); number_group++) {
    for (int number_student = 0;
         number_student < groups[number_group].students.size();
         number_student++) {
      if (groups[number_group].students[number_student]->get_fio() == fio) {
        return groups[number_group].students[number_student]->average_mark();
      }
    }
  }
}

double Deanary::get_statistic_groups(std::string spec) {
  for (int number_group = 0; number_group < groups.size(); number_group++) {
      if (groups[number_group].get_spec() == spec) {
        return groups[number_group].avarage_mark();
      }
  }
}

void Deanary::student_transfer(std::string fio, std::string spec) {
  for (int number_group = 0; number_group < groups.size(); number_group++) {
    for (int number_student = 0;
         number_student < groups[number_group].students.size();
         number_student++) {
      if (groups[number_group].students[number_student]->get_fio() == fio) {
        for (int i = 0; i < groups.size(); i++) {
          if (groups[i].get_spec() == spec) {
            groups[i].add_student(
                groups[number_group].students[number_student]);
            groups[number_group].remove_student(
                groups[number_group].students[number_student]);
          }
        }
      }
    }
  }
}

void Deanary::deduction_student(std::string fio) {
  for (int number_group = 0; number_group < groups.size(); number_group++) {
    for (int number_student = 0;
         number_student < groups[number_group].students.size();
         number_student++) {
      if (groups[number_group].students[number_student]->get_fio() == fio) {
        groups[number_group].remove_student(
            groups[number_group].students[number_student]);
      }
    }
  }
}

void Deanary::save_to_file() {
  std::ofstream fout;
  fout.open("output.txt");
  for (int number_group = 0; number_group < groups.size(); number_group++) {
    fout << groups[number_group].get_title() << std::endl;
    for (int number_student = 0; number_student < groups[number_group].students.size(); number_student++) {
      fout << groups[number_group].students[number_student]->get_fio()
           << std::endl;
    }
  }
  fout.close();
}

void Deanary::choice_head() {
  for (int i = 0; i < groups.size(); i++) {
    groups[i].choice_head();
  }
}

void Deanary::print() {
  for (int number_group = 0; number_group < groups.size(); number_group++) {
    std::cout << "The group's specialty is " << groups[number_group].get_spec()
              << std::endl;
    std::cout << "The group's title is " << groups[number_group].get_title()
              << std::endl;
    std::cout << "Head of group is " << groups[number_group].head->get_fio()
              << std::endl;
    for (int number_student = 0; number_student < groups[number_group].students.size(); number_student++) {
      std::cout << groups[number_group].students[number_student]->get_fio()
                << std::endl;
    }
  }
}

void Deanary::add_group(Group group) {
    groups.push_back(group);
}
