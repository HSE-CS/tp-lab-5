// Copyright 2021 Galex
#include <string>
#include <fstream>
#include <iostream>
#include "../include/Deanary.h"
#include "../include/Student.h"

Deanary::Deanary(std::string specialization) {
  this->spec = specialization;
  this->nextId = 1;
}
void Deanary::createGroups() {
  std::fstream groupsList;
  groupsList.open(R"(../../data/groups.txt)");
  std::string input;
  std::getline(groupsList, input);
  int groupsNum = std::stoi(input);
  for (int i = 0; i < groupsNum; ++i) {
    std::getline(groupsList, input);
    Group *group = new Group(input, this->spec);
    this->groups.push_back(group);
  }
  groupsList.close();
}
Group *Deanary::getGroup(int number) {
  return groups[number - 1];
}
void Deanary::hireStudent(std::string fio, int groupNum) {
  Student *student = new Student(nextId, fio);
  student->add2group(this->groups[groupNum - 1]);
  ++nextId;
}
void Deanary::hireStudents() {
  std::fstream studentsList;
  studentsList.open(R"(../../data/students.txt)");
  std::string input;
  std::getline(studentsList, input);
  int studentsNum = std::stoi(input);
  int iteratorTotal = 0;
  while (iteratorTotal < studentsNum) {
    for (int i = 0; i < this->groups.size(); ++i) {
      if (iteratorTotal < studentsNum) {
        std::getline(studentsList, input);
        Student *student = new Student(nextId, input);
        student->add2group(groups[i]);
        ++nextId;
        ++iteratorTotal;
      }
    }
  }
  initHeads();
}
void Deanary::fireStudent(unsigned int id) {
  for (int i = 0; i < this->groups.size(); ++i) {
    if (this->groups[i]->containsStudent(id)) {
      this->groups[i]->getStudent(id)->remove();
      return;
    }
  }
}
void Deanary::moveStudent(Student *student, Group *a, Group *b) {
  if (a->containsStudent(student->getId())) {
    student->add2group(b);
    a->removeStudent(student);
  }
}
void Deanary::initHeads() {
  for (int i = 0; i < this->groups.size(); ++i) {
    if (this->groups[i]->getNumOfStudents() != 0) {
      int randomHead = std::rand() % (this->groups[i]->getNumOfStudents());
      this->groups[i]->chooseHead(this->groups[i]->
          getStudentByIndex(randomHead));
    }
  }
}
void Deanary::addMarks2All(int numOfMarks) {
  unsigned int seed = 234123;
  for (int i = 0; i < this->groups.size(); ++i) {
    for (int j = 0; j < this->groups[i]->getNumOfStudents(); ++j) {
      for (int k = 0; k < numOfMarks; ++k) {
        this->groups[i]->getStudentByIndex(j)->addMark(rand_r(&seed) % 10);
      }
    }
  }
}
double Deanary::getAverage() {
  double totalNum = 0.0;
  double sum = 0.0;
  for (int i = 0; i < this->groups.size(); ++i) {
    for (int j = 0; j < this->groups[i]->getNumOfStudents(); ++j) {
      if (this->groups[i]->getStudentByIndex(j)->isAnyMarks()) {
        sum += this->groups[i]->getStudentByIndex(j)->getAverage();
        ++totalNum;
      }
    }
  }
  return sum / totalNum;
}
void Deanary::createGroup(std::string name) {
  Group *group = new Group(name, this->spec);
  this->groups.push_back(group);
}
void Deanary::saveState() {
  std::ofstream outfile;
  outfile.open(R"(../../data/out.txt)");
  outfile << "Specialization - " << this->spec << "\n";
  outfile << "Total Groups - " << this->groups.size() << "\n \n";
  for (int i = 0; i < this->groups.size(); ++i) {
    outfile << "Group " << i + 1 << " Name - " <<
            this->groups[i]->getName() << "\n";
    outfile << "   Group head - " <<
            this->groups[i]->getHead()->getName() <<
            " id - " << this->groups[i]->getHead()->getId() << "\n";
    for (int j = 0; j < this->groups[i]->getNumOfStudents(); ++j) {
      outfile << "   >>> " << j << ". Id - " <<
              this->groups[i]->getStudentByIndex(j)->getId() << "  "
              << this->groups[i]->getStudentByIndex(j)->getName()
              << "  Average mark - " << this->groups[i]->
          getStudentByIndex(j)->getAverage()
              << "  All marks: " << this->groups[i]->
          getStudentByIndex(j)->getMarks2String() << "\n";
    }
    outfile << "\n \n";
  }
  outfile.close();
}
