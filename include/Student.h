// Copyright 2020 VladimirUspensky

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"

class Student {
 private:
    int id;
    std::string fio;
    std::vector<int> marks;

 public:
    Group* group;
    int getId() const;
    std::string getName() const;
    Student(int input_id, const std::string& input_fio);
    void addToGroup(Group* group);
    void addMark(int mark);
    double getAverageMark();
};

#endif  // INCLUDE_STUDENT_H_
