//
// Created by toliman on 03.02.2021.
//

#ifndef TP_LAB_5_STUDENT_H
#define TP_LAB_5_STUDENT_H

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

//#include "Group.h"
//#include "../include/Deanary.h"

class Group;

class Student {
private:
    int id;
    std::string fio;
    Group *group;
    std::vector<int> marks;
public:
    explicit Student(int idParam, std::string fioParam);

    std::string getFio();

    int getId() const;

    void setGroup(Group &groupParam);

    Group *getGroup();

    void addMark(int mark);

    float getMiddleMark();
};


#endif //TP_LAB_5_STUDENT_H
