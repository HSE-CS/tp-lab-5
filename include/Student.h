// Copyright 2021 Grachev Alexander

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;

class Student {
 private:
    unsigned int id;
    std::string name;
    std::vector<int> marks;
    Group *group{};

 public:
    friend class Group;
    friend class Deanary;

    Student(unsigned int id, const std::string& name);

    void setId(int id);
    int getId();
    void setName(std::string name);
    std::string getName();
    void addMark(int mark);
    double getMidMark();
    void addGroup(Group group);
    Group &getGroup();
};

#endif  // INCLUDE_STUDENT_H_
