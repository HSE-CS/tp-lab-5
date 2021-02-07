// Copyright 2021 Stifeev Nikita

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <iostream>
#include <string>
#include <vector>

class Group;
class Student {
 private:
    unsigned int Id;
    std::string FIO;
    Group* group;
    std::vector<int> marks;
 public:
    Student(int ID, std::string full_name);
    void addToGroup(Group* group);
    void addmark(int mark);
    int calcAv() const;
    std::string getFIO() const;
    unsigned int getID() const;
    Group* getGroup() const;
    ~Student();
};

#endif  // INCLUDE_STUDENT_H_
