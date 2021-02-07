//
//  main.cpp
//  programming-technologies
//
//  Created by Даниил Иванов on 07.02.2021.
//  Copyright © 2021 Daniil Ivanov. All rights reserved.
//

#include <stdio.h>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <string>
int main() {
    Student st1(109, "Ivanov I.I.");
    Deanary dr;
    dr.acceptStudents();
    dr.createGroups();
    dr.studentRegistration();
    dr.addMarks();
    std::cout << dr.getStatisticByGroups("AMI") << std::endl;
    dr.addStudent(&st1, "BI");
    std::cout << dr.getStatisticByStudents("Christabella Merrill") << std::endl;
    dr.transferStudent("Ivanov D.A.", "AMI");
    dr.initOfHeadElection();
    std::cout << "---------------------------------------------" << std::endl;
    dr.printAllInfo();
    std::cout << "---------------------------------------------" << std::endl;
    dr.printAllInfo();
    dr.hireStudent("Petrov I.I.");
    std::cout << "---------------------------------------------" << std::endl;
    dr.printAllInfo();
    dr.saveToFiles();
}
