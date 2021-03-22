// Copyright by JMax 2020


#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>
#include "Group.h"
#include "Deanary.h"

class Group;

class Student {
    friend class Deanary;
    friend class Group;
 private:
    unsigned int id;
    std::string fio;
    Group* group;
    std::vector<unsigned int> marks;

    void addToGroup(Group* group);
    void removeFromGroup();
    void addMark(unsigned int mark);
    unsigned int sumOfMarks();
    unsigned int numOfMarks();

 public:
    Student(const unsigned int id, const std::string& fio);
    double getAverageMark();
    bool isHeadOfGroup();
    std::string getFio() const;
    unsigned int getId() const;
};

#endif  // INCLUDE_STUDENT_H_
