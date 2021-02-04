// Copyright 2021 GN
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
    dr.addStudent(&st1, "PH");
    std::cout << dr.getStatisticByStudents("Debbie Bowen") << std::endl;
    dr.transferStudent("Ivanov I.I.", "AMI");
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
