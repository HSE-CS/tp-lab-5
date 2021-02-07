// Copyright 2021 DBarinov

#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <string>

int main() {
    Student st1(109, "Barinov D.S.");
    Deanary dr;
    dr.acceptStudents();
    dr.createGroups();
    dr.studentRegistration();
    dr.addMarks();
    std::cout << dr.getStatisticByGroups("AMI") << std::endl;
    dr.addStudent(&st1, "BI");
    std::cout << dr.getStatisticByStudents("Artem Chesnokov") << std::endl;
    dr.transferStudent("Barinov D.S.", "AMI");
    dr.initOfHeadElection();
    std::cout << "---------------------------------------------" << std::endl;
    dr.printAllInfo();
    std::cout << "---------------------------------------------" << std::endl;
    dr.printAllInfo();
    dr.hireStudent("Barinov D.S.");
    std::cout << "---------------------------------------------" << std::endl;
    dr.printAllInfo();
    dr.saveToFiles();
}
