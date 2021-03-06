//
//  include:Deanary.h
//  tp-lab-5
//
//  Created by Anastasiya Rogozyan on 03.03.2021.
//  Copyright © 2021 Anastasiya Rogozyan. All rights reserved.
//

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <iostream>
#include <string>
#include <vector>

#include "Group.h"
#include "Student.h"

class Group;
class Student;

class Deanary {
 private:
    std::vector<Group> groups;
    std::vector<Student> Students;

 public:
    void student_hire(Student* student, std::string num_group);
    void student_reading();
    void student_distribution();
    double student_statistic(std::string FIO);
    void student_moving(std::string FIO, std::string programm);
    void student_expulsion(std::string FIO);
    void student_head();
    void marks_adding();
    void group_adding(Group group);
    void group_reading();
    double group_statistic(std::string programm);
    void information_save();
    void print();
    friend class Group;
    friend class Student;
};

#endif  // INCLUDE_DEANARY_H_
