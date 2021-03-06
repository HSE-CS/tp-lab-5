//
//  main.cpp
//  tp-lab-5
//
//  Created by Anastasiya Rogozyan on 03.03.2021.
//  Copyright © 2021 Anastasiya Rogozyan. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include "../include/rapidjson/document.h"
#include "../include/rapidjson/writer.h"
#include "../include/rapidjson/stringbuffer.h"
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"
int main() {
    Deanery dn = Deanery();
    std::vector<Group*> groups = dn.createGroupsFromFile("input.json");
     dn.setGroups(groups);
     dn.printInfo();
     dn.saveData("output.json");

     Student *sf = new Student(999, "Student A");
     std::cout << sf->getFio() << std::endl;
     sf->setFio("Student A(Changed)");
     std::cout << sf->getFio() << std::endl;
     sf->addMark(10);
     sf->addMark(8);
     sf->addMark(4);
     std::cout << sf->calculateMeanMark() << std::endl;
     std::cout << sf->getGroup() << std::endl;

     Group *gr = new Group("19 PMI-1", "Computer Science");
     gr->addStudentToGroup(sf);
     std::cout << sf->getGroup()->getTitle() << std::endl;
     Student *st = new Student(1000, "Student B");
     st->addMark(5);
     gr->addStudentToGroup(st);
     std::cout << gr->getStudents()[1]->getFio()  << std::endl;
     std::cout << gr->calculateMeanMark() << std::endl;
     gr->chooseHeadman(sf);

     Deanery deanery = Deanery();
     std::vector<Group*> grps = {gr};
     deanery.setGroups(grps);
     deanery.addMarksToAll();
     std::cout << "New random mark was added: "
         << deanery.getGroups()[0]->
         getStudents()[0]->getMarks()[4] << std::endl;
     return 0;
 }
