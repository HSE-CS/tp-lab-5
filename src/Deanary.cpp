// Copyright 2021 Dev-will-work
#include <iostream>
#include <fstream>
#include <random>
#include "../include/Deanary.h"
#include "../include/Group.h"
#include "../include/Student.h"

Group* Deanary::operator[](int index) {
  if (index < 0 || index >= this->groups.size()) return nullptr;
  else
    return this->groups[index];
}  // get by index

DeanFactory::DeanFactory(std::string filename, FileFormat format) {
  this->filename = filename;
  this->format = format;
}

std::vector<Student*> DeanFactory::createStudents() {
  std::vector<Student*> students;
  std::string fio;
  std::ifstream fin(this->filename);
  for (std::string name, surname, patronymic; fin >> surname
                                          >> name >> patronymic;) {
    fio = surname += std::string(" ") += name += std::string(" ") += patronymic;
    Student* st = new Student(fio, this->createId());
    students.push_back(st);
  }
  fin.close();
  return students;
}

void DeanFactory::returnStudents(std::vector<Student*> students) {
  std::ofstream fwrite(this->filename);
  for (size_t i = 0; i < students.size(); i++) {
    fwrite << students[i]->getName() << std::endl;
    delete students[i];
  }
  fwrite.close();
}

std::vector<Group*> DeanFactory::createGroups() {
  std::vector<Group*> groups;
  std::ifstream fin(this->filename);
  for (std::string name, spec; fin >> name >> spec; ) {
    Group* gr = new Group(name, spec);
    groups.push_back(gr);
  }
  fin.close();
  return groups;
}

void DeanFactory::returnGroups(std::vector<Group*> groups) {
  std::ofstream fwrite(this->filename);
  for (size_t i = 0; i < groups.size(); i++) {
    fwrite << groups[i]->getName() << " " << groups[i]->getSpec() << std::endl;
    delete groups[i];
  }
  fwrite.close();
}

uint64_t DeanFactory::createId() {
  static uint64_t s_id = 0;
  return s_id++;
}

void Deanary::getLastState() {
  std::ifstream fin("state.txt");
  int groups_number, students_number, marks_number;
  uint64_t id;
  std::string fio, surname, name, patronymic;
  std::string head_surname, head_name, head_patronymic;
  std::string title, spec, head_fio;
  fin >> groups_number;
  this->groups.resize(groups_number);
  for (size_t i = 0; i < this->groups.size(); i++) {
    fin >> title >> spec;
    this->groups[i] = new Group(title, spec);
    fin >> students_number;
    this->groups[i]->students.resize(students_number);
    fin >> head_surname >> head_name >> head_patronymic;
    head_fio = head_surname + " " + head_name + " " + head_patronymic;
    for (size_t j = 0; j < this->groups[i]->students.size(); j++) {
      fin >> id;
      fin >> surname >> name >> patronymic;
      fio = surname + " " + name + " " + patronymic;
      this->groups[i]->students[j] = new Student(fio, id);
      fin >> marks_number;
      this->groups[i]->students[j]->marks.resize(marks_number);
      for (size_t k = 0; k < this->groups[i]->students[j]->marks.size(); k++) {
        fin >> this->groups[i]->students[j]->marks[k];
      }
      this->groups[i]->students[j]->group = this->groups[i];
    }
    this->groups[i]->head = this->groups[i]->getStudent(head_fio);
  }
  fin.close();
}

void Deanary::hireStudents(int students_count) {
  if (students_count <= 0) return;
  DeanFactory df("students.txt", FileFormat::TXT);
  std::vector<Student*> students = df.createStudents();
  for (size_t i = 0; i < this->groups.size(); i++) {
    for (size_t j = 0; j < students_count; j++) {
      this->groups[i]->addStudent(students.front());
      students.front()->addToGroup(this->groups[i]);
      students.erase(students.begin());
    }
    this->groups[i]->chooseHead();
  }
  df.returnStudents(students);
}

void Deanary::createGroups(int num_groups) {
  if (num_groups <= 0) return;
  DeanFactory df("groups.txt", FileFormat::TXT);
  std::vector<Group*> groups = df.createGroups();
  for (size_t i = 0; i < num_groups; i++) {
    this->groups.push_back(groups.front());
    groups.erase(groups.begin());
  }
  df.returnGroups(groups);
}

void Deanary::addMarksToAll(int count) {
  if (count <= 0) return;
  std::random_device rd;
  std::mt19937 mersenne(rd());
  for (size_t i = 0; i < this->groups.size(); i++) {
    for (size_t j = 0; j < this->groups[i]->students.size(); j++) {
      for (size_t k = 0; k < count; k++) {
        this->groups[i]->students[j]->addmark(1 + mersenne() % 5);
      }
    }
  }
}

void Deanary::getStatistics() {
  std::cout << "Number of groups: " << this->groups.size() << "\n\n";
  for (size_t i = 0; i < this->groups.size(); i++) {
    std::cout << "Group N " << i + 1 << ": " << this->groups[i]->title;
    std::cout << '\n';
    std::cout << "Specialization: " << this->groups[i]->spec << '\n';
    std::cout << "Number of students: " << this->groups[i]->students.size();
    std::cout << '\n';
    std::cout << "Head of the group: " << (this->groups[i]->head
                  ? this->groups[i]->head->fio : "Not assigned") << std::endl;
    std::cout << "Average mark by group: " <<
                this->groups[i]->getAverageMark();
    std::cout << "\n\n";
    for (size_t j = 0; j < this->groups[i]->students.size(); j++) {
      std::cout << "Student with id " << this->groups[i]->students[j]->id;
      std::cout << ":\n";
      std::cout << this->groups[i]->students[j]->fio << '\n';
      std::cout << "Marks:\n";
      for (size_t k = 0; k < this->groups[i]->students[j]->marks.size(); k++) {
        std::cout << this->groups[i]->students[j]->marks[k] << ' ';
      }
      std::cout << std::endl;
      std::cout << "Average mark: " <<
        this->groups[i]->students[j]->getAveragemark() << "\n\n";
    }
    std::cout << "\n\n";
  }
}

void Deanary::moveStudents(std::string from_n, std::string to_n) {
  Group* from = nullptr, *to = nullptr;
  for (size_t i = 0; i < this->groups.size(); i++) {
    if (this->groups[i]->getName() == from_n) {
    from  = this->groups[i];
    } else if (this->groups[i]->getName() == to_n) {
    to = this->groups[i];
    }
  }
  if (from && to) {
    for (size_t i = 0; !from->students.empty(); i++) {
      from->students.front()->group = to;
      to->students.push_back(from->students.front());
      from->students.erase(from->students.begin());
    }
    if (!to->getHead()) to->chooseHead();
    from->head = nullptr;
  }
}

void Deanary::moveStudents(int pos_from, int pos_to) {
  if (pos_from < 0 || pos_to < 0) return;
  for (size_t i = 0; (*this)[pos_from]->size(); i++) {
    (*this)[pos_from]->students.front()->group = (*this)[pos_to];
    (*this)[pos_to]->students.push_back((*this)[pos_from]->students.front());
    (*this)[pos_from]->students.erase((*this)[pos_from]->students.begin());
  }
  if (!(*this)[pos_to]->getHead()) (*this)[pos_to]->chooseHead();
  (*this)[pos_from]->head = nullptr;
}

void Deanary::saveStaff(std::string filename) {
  std::ofstream fwrite(filename);
  fwrite << this->groups.size() << std::endl;
  for (size_t i = 0; i < this->groups.size(); i++) {
    fwrite << this->groups[i]->title << std::endl;
    fwrite << this->groups[i]->spec << std::endl;
    fwrite << this->groups[i]->students.size() << std::endl;
    fwrite << (this->groups[i]->head
               ? this->groups[i]->head->fio : "not-assigned");
    fwrite << std::endl;
    for (size_t j = 0; j < this->groups[i]->students.size(); j++) {
      fwrite << this->groups[i]->students[j]->id << std::endl;
      fwrite << this->groups[i]->students[j]->fio << std::endl;
      fwrite << this->groups[i]->students[j]->marks.size() << std::endl;
      for (size_t k = 0; k < this->groups[i]->students[j]->marks.size(); k++) {
        fwrite << this->groups[i]->students[j]->marks[k] << ' ';
      }
      fwrite << std::endl;
    }
    fwrite << std::endl;
  }
  fwrite.close();
}

void Deanary::initHeads() {
  for (size_t i = 0; i < this->groups.size(); i++) {
    this->groups[i]->chooseHead();
  }
}

void Deanary::fireStudents(int count) {
  if (count <= 0) return;
  Student* bad_boy = nullptr;
  float main_average = 5.0;
  for (size_t k = 0; k < count; k++) {
    main_average = 5.0;
    for (size_t i = 0; i < this->groups.size(); i++) {
      for (size_t j = 0; j < this->groups[i]->students.size(); j++) {
          if (this->groups[i]->students[j]->getAveragemark() < main_average) {
            main_average = this->groups[i]->students[j]->getAveragemark();
            bad_boy = this->groups[i]->students[j];
          }
      }
    }
    if (bad_boy) bad_boy->group->removeStudent(bad_boy->fio);
  }
}

size_t Deanary::size() { return this->groups.size();}
