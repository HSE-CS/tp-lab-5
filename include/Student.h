// Copyright 2021 valvarl

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "Group.h"
#include <utility>
#include <vector>
#include <numeric>
#include <string>

class Group;

class Student {
    friend class Deanery;
 private:
    int id;
    std::string fio;
    Group *group{};
    std::vector<int>marks;
    void addToGroup(Group *_group);
    void addmark(int mark);
 public:
    Student(int _id, std::string& _fio) : id(_id), fio(_fio) {}
    [[nodiscard]] int getId() const;
    [[nodiscard]] const std::string &getName() const;
    double getAverageMark();
    bool isHeadOfGroup();
};

#endif  // INCLUDE_STUDENT_H_
