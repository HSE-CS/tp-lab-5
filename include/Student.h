// Copyright 2021 soda

#ifndef LAB_5_STUDENT_H
#define LAB_5_STUDENT_H

#include "Group.h"
#include <vector>
#include <string>

class Group;

class Student {
    friend class Deanery;
 private:
    int id;
    std::string fio;
    Group* group{};
    std::vector<int>marks;
    void addToGroup(Group*);
    void addmark(int);
 public:
    Student(int id, std::string& fio): this->id(id), this->fio(fio) {}
    
    double getAverageMark();
    bool isHeadOfGroup();

    //Может понадобиться
    //const std::string& getName() const;
    //int getId() const;
};

#endif  // LAB_5_STUDENT_H