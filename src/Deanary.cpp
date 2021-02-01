// Copyright 2020 GHA Test Team
#include "Deanary.h"


Deanary::Deanary() {
  this->groups = nullptr;
  this->number_of_groups = 0;
  this->reader = new DataReader;
}

Deanary::Deanary(unsigned number_of_groups, std::string students_file_name,
  std::string groups_file_name, bool random_division) {
  this->students_file_name = students_file_name;
  this->groups_file_name = groups_file_name;
  this->groups = new Group[number_of_groups];
  this->number_of_groups = number_of_groups;
  this->reader = new DataReader;
  this->createGroups(this->hireStudents(this->students_file_name),
    this->groups_file_name, random_division);
  this->addMarksToAll(10);
  this->initHeads();
}

void Deanary::printDeanary(bool marks_on) {
  for (unsigned i = 0; i < this->number_of_groups; i++) {
    std::cout << "Group: "<< groups[i].getTitle() << 
      " \t\t\t\t\t\tHead: " << groups[i].getHead()->getFio() << std::endl;
    unsigned number_of_students = groups[i].students.size();
    for (unsigned j = 0; j < number_of_students; j++) {
      if (marks_on) {
        std::cout << "Average Mark: " << 
          groups[i].students.at(j)->getAverageMark();
        std::cout << " \tMarks: ";
        groups[i].students.at(j)->printMarks(); 
        std::cout << "\t" << groups[i].students.at(j)->getFio();
        std::cout << std::endl;
      }
      else
        std::cout << "FIO: " << groups[i].students.at(j)->getFio() << 
        std::endl;
    }
    std::cout << std::endl;
  }
}

int Deanary::getNumberOfGroups() const {
  return this->number_of_groups;
}

void Deanary::addMarksToAll(unsigned number_of_marks, bool random) {
  for (unsigned i = 0; i < this->number_of_groups; i++) {
    unsigned size = this->groups[i].students.size();
    for (unsigned j = 0; j < size; j++) {
      for (unsigned k = 0; k < number_of_marks; k++) {
        if (random)
          this->groups[i].students.at(j)->addMark(std::rand() % 5 + 1);
        else
          this->groups[i].students.at(j)->addMark(k + 1);
      }
    }
  }
}

std::vector<Student*> Deanary::findBestStudents(Group* group) {
  std::vector<Student*> best_students;
  float max_avg_mark = 0;
  unsigned number_of_students = group->students.size();
  for (unsigned i = 0; i < number_of_students; i++) {
    float mark = group->students.at(i)->getAverageMark();
    if (mark > max_avg_mark)
      max_avg_mark = mark;
  }
  for (unsigned i = 0; i < number_of_students; i++) {
    float mark = group->students.at(i)->getAverageMark();
    if (mark == max_avg_mark)
      best_students.push_back(group->students.at(i));
  }
  return best_students;
}

std::vector<Student*> Deanary::findWorstStudents(Group* group) {
  std::vector<Student*> worst_students;
  float min_avg_mark = std::numeric_limits<float>::infinity();;
  unsigned number_of_students = group->students.size();
  for (unsigned i = 0; i < number_of_students; i++) {
    float mark = group->students.at(i)->getAverageMark();
    if (mark < min_avg_mark) 
      min_avg_mark = mark;
  }
  for (unsigned i = 0; i < number_of_students; i++) {
    float mark = group->students.at(i)->getAverageMark();
    if (mark == min_avg_mark)
      worst_students.push_back(group->students.at(i));
  }
  return worst_students;
}

unsigned* Deanary::findNumberOfCatigoriesOfStudents(Group* group) {
  unsigned* result = new unsigned[4]{ 0 };
  unsigned number_of_students = group->students.size();
  for (unsigned j = 0; j < number_of_students; j++) {
    float avg_mark = group->students.at(j)->getAverageMark();
    if (avg_mark <= 10.f) {
      if (avg_mark >= 8.0f)
        result[0]++;
      else if (avg_mark >= 6.0f)
        result[1]++;
      else if (avg_mark >= 3)
        result[2]++;
      else
        result[3]++;
    }
  }
  return result;
}

void Deanary::printStatistics() {
  for (unsigned i = 0; i < this->number_of_groups; i++) {
    unsigned* catigories_of_students = 
      this->findNumberOfCatigoriesOfStudents(&this->groups[i]);
    std::vector<Student*> best_students =
      this->findBestStudents(&this->groups[i]);
    std::vector<Student*> worst_students =
      this->findWorstStudents(&this->groups[i]);
    std::cout << "Group: " << this->groups[i].getTitle() << std::endl;
    std::cout << "The best students: ";
    for (unsigned i = 0; i < best_students.size(); i++)
      std::cout << best_students.at(i)->getFio() << ", ";
    std::cout << " \t\tAverage mark: " <<
      best_students.at(0)->getAverageMark() << std::endl;
    std::cout << "The worst students: ";
    for (unsigned i = 0; i < worst_students.size(); i++)
      std::cout << worst_students.at(i)->getFio() << ", ";
    std::cout << " \t\tAverage mark: " <<
      worst_students.at(0)->getAverageMark() << std::endl;
    std::cout << "Number of A students: " <<
      catigories_of_students[0]  << std::endl;
    std::cout << "Number of B students: " <<
      catigories_of_students[1]  << std::endl;
    std::cout << "Number of C students: " <<
      catigories_of_students[2]  << std::endl;
    std::cout << "Number of F students: " <<
      catigories_of_students[3]  << std::endl;
    std::cout << std::endl;
  }
}

bool Deanary::fireStudents() {
  bool result = false;
  for (unsigned i = 0; i < this->number_of_groups; i++) {
    bool remake_head = false;
    unsigned* catigories_students =
      this->findNumberOfCatigoriesOfStudents(&this->groups[i]);
    if (catigories_students[3] > 0) {
      result = true;
      unsigned number_of_students = this->groups[i].students.size();
      for (unsigned j = 0; j < number_of_students; j++)
        if (this->groups[i].students.at(j)->getAverageMark() < 3) {
          if (this->groups[i].students.at(j)->isHeadOfGroup())
            remake_head = true;
          groups[i].students.erase(this->groups[i].students.begin() + j);
          j--;
          number_of_students--;
        }
      if (remake_head)
        this->groups[i].chooseHead();
    }
  }
  return result;
}

Student* Deanary::findStudentByFio(std::string fio) {
  for (unsigned i = 0; i < this->number_of_groups; i++) {
    Student* student = this->groups[i].getStudentByFio(fio);
    if (student != nullptr) {
      return student;
    }
  }
  return nullptr;
}

Group* Deanary::findGroupByTittle(std::string title) {
  for (unsigned i = 0; i < this->number_of_groups; i++) {
    if (this->groups[i].getTitle() == title)
      return &this->groups[i];
  }
  return nullptr;
}

void Deanary::moveStudents(std::string fio, std::string new_group_name) {
  bool remake_head_flag = false;
  Student* student = this->findStudentByFio(fio);
  Group* new_group = this->findGroupByTittle(new_group_name);
  if (student == nullptr || new_group == nullptr)
    return;
  std::cout << student->group->getTitle() << std::endl;
  Group* cur_group = student->group;
  unsigned number_of_students = cur_group->students.size();
  if (student->getFio() == cur_group->getHead()->getFio())
    remake_head_flag = true;
  for (unsigned i = 0; i < number_of_students; i++) {
      if (student->getId() == cur_group->students.at(i)->getId()) {
        new_group->addStudent(new Student(student));
        cur_group->students.erase(cur_group->students.begin() + i);
        break;
      }
  }
  if (remake_head_flag)
    cur_group->chooseHead();
}

void Deanary::saveStaff(std::string new_students_file_name,
  std::string new_goups_file_name) {
  std::ofstream out, out1;
  out.open(new_students_file_name);
  if (out.is_open()) {
    for (unsigned i = 0; i < this->number_of_groups; i++) {
      unsigned number_of_students = this->groups[i].students.size();
      for (unsigned j = 0; j < number_of_students; j++)
        out << this->groups[i].students.at(j)->getFio() << std::endl;
      out << std::endl;
    }
  }
  out1.open(new_goups_file_name);
  if (out1.is_open()) {
    for (unsigned i = 0; i < this->number_of_groups; i++)
      out1 << this->groups[i].getTitle() << std::endl;
    out1 << std::endl;
  }
}

void Deanary::initHeads() {
  for (unsigned i = 0; i < this->number_of_groups; i++) {
    this->groups[i].chooseHead();
  }
}

std::vector<Student*>  Deanary::hireStudents(std::string file_name,
  std::string format) {
  std::vector<Student*> students;
  this->reader->readStudentsData(file_name);
  std::vector<std::string> student_names = reader->getStudents();
  unsigned number_of_students = student_names.size();
  for (unsigned i = 0; i < number_of_students; i++)
    students.push_back(new Student(i, student_names.at(i)));
  return students;
}

void  Deanary::createGroups(std::vector<Student*> students,
  std::string file_name, bool random_division, std::string format) {
  this->reader->readGroupsData(file_name);
  std::vector<std::string> group_names = reader->getGroups();
  unsigned number_of_students = students.size();
  unsigned remains = number_of_students % this->number_of_groups;
  if (random_division) {
    for (unsigned i = 0; i < this->number_of_groups; i++) {
      this->groups[i] = *new Group(group_names.at(i));
      for (unsigned j = 0; j < number_of_students - remains; j++)
        if (j % number_of_groups == i) {
          students.at(j)->setGroup(&groups[i]);
          this->groups[i].addStudent(students.at(j));
        }
    }
  } else {
    unsigned j = 0, shift = 1;
    for (unsigned i = 0; i < number_of_groups; i++)
      this->groups[i] = *new Group(group_names.at(i));
    for (unsigned i = 0; i < number_of_students - remains; i++) {
      if (i >= (number_of_students / number_of_groups) * shift) {
        j++;
        shift++;
      }
      students.at(i)->setGroup(&groups[j]);
      this->groups[j].addStudent(students.at(i));
    }
  }
  if (remains)
    for (unsigned i = 0; i < remains; i++) {
      students.at(number_of_students - remains + i)->setGroup(&groups[i]);
      this->groups[number_of_groups - 1].addStudent(
        students.at(number_of_students - remains + i));
    }
}
