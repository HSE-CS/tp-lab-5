// Copyright 2021 VadMack

#include <iostream>
#include <vector>
#include <fstream>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

#define SIZE 30

int main() {
  srand(time(0));

  auto **arr = new int *[12];
  for (int i = 0; i < 12; ++i) {
    arr[i] = new int[8];
  }

  //  Test-case 1
  Group group1("19SE-1", "SE");
  Student student1("1", "Pavlov Efrem Pavlovich");
  student1.addToGroup(&group1);
  std::cout << student1.getGroup()->GetTitle() << std::endl;
  std::cout << group1.getStudent("1")->getFio() << std::endl << std::endl;

  //  Test-case 2
  Student student2("2", "Sedov Oleg Andreevich");
  group1.addStudent(&student2);
  std::cout << student2.getGroup()->GetTitle() << std::endl;


  //  Test-case 3
  //  #Archived

  //  Test-case 4
  student1.addMark(10);
  student1.addMark(9);
  std::cout << student1.calculateAverageMark() << std::endl;
  student2.addMark(9);
  student2.addMark(8);
  std::cout << student2.calculateAverageMark() << std::endl << std::endl;
  std::cout << group1.calculateAverageMark() << std::endl << std::endl;

  //  Test-case 5
  group1.chooseHead(&student2);
  std::cout << group1.getHead()->getFio() << std::endl << std::endl;

  // Test-case 6
  std::cout << "* Before removing:" << std::endl;
  for (int i = 0; i < group1.getStudents().size(); ++i) {
    std::cout << group1.getStudents()[i]->getFio() << std::endl;
  }
  group1.removeStudent(&student1);
  std::cout << "* After removing:" << std::endl;
  for (int i = 0; i < group1.getStudents().size(); ++i) {
    std::cout << group1.getStudents()[i]->getFio() << std::endl;
  }
  if (student1.getGroup() == nullptr) {
    std::cout << "* Group has deleted" << std::endl << std::endl;
  }

  //  Test-case 7
  Deanary deanary1;
  deanary1.createGroups();
  std::cout << deanary1.getGroups()[0]->GetTitle() << std::endl;
  std::cout << deanary1.getGroups()[1]->GetTitle() << std::endl;
  std::cout << deanary1.getGroups()[2]->GetTitle() << std::endl << std::endl;

  //  Test-case 8
  std::vector < Student * > students;
  students = Deanary::createStudents();
  for (int i = 0; i < SIZE; ++i) {
    std::cout << students[i]->getId() << " --- " <<
              students[i]->getFio() << std::endl;
  }
  std::cout << std::endl;

  //  Test-case 9
  for (int i = 0; i < 10; ++i) {
    deanary1.getGroups()[0]->addStudent(students[i]);
  }
  for (int i = 0; i < deanary1.getGroups()[0]->getStudents().size(); ++i) {
    std::cout << deanary1.getGroups()[0]->
        getStudents()[i]->getFio() << std::endl;
    std::cout << students.at(i)->getGroup()->GetTitle() << std::endl;
  }
  std::cout << std::endl;

  //  Test-case 10
  std::vector < Student * > studentsToMove;

  studentsToMove.reserve(SIZE / 3);
  for (int i = 0; i < SIZE / 3; ++i) {
    studentsToMove.push_back(students.at(i));
  }
  Deanary::moveStudents(studentsToMove,
                        deanary1.getGroups()[0],
                        deanary1.getGroups()[1]);
  for (int i = 0; i < deanary1.getGroups()[1]->getStudents().size(); ++i) {
    std::cout << deanary1.getGroups()[1]->
        getStudents()[i]->getFio() << std::endl;
    std::cout << students.at(i)->getGroup()->GetTitle() << std::endl;
  }
  std::cout << std::endl;

  //  Test-case 11
  for (int i = 10; i < 20; ++i) {
    students.at(i)->addToGroup(deanary1.getGroups().at(0));
  }
  for (int i = 20; i < 30; ++i) {
    students.at(i)->addToGroup(deanary1.getGroups().at(2));
  }
  deanary1.addRandomMarksToAll();
  deanary1.addRandomMarksToAll();
  for (int i = 0; i < deanary1.getGroups().size(); ++i) {
    for (int j = 0; j < deanary1.getGroups().at(i)->getStudents().size(); ++j) {
      std::cout << deanary1.getGroups().at(i)->
          getStudents().at(j)->getMarks().at(0) << std::endl;
    }
  }
  std::cout << std::endl;

  //  Test-case 12
  deanary1.initHeads();
  std::cout << deanary1.getGroups().at(0)->getHead()->getFio() << std::endl;
  std::cout << deanary1.getGroups().at(1)->getHead()->getFio() << std::endl;
  std::cout << deanary1.getGroups().at(2)->getHead()->getFio() <<
            std::endl << std::endl;

  // Test-case 13
  deanary1.getStatistics();
  deanary1.saveStaff();
}
