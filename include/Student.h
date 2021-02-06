// Copyright 2021 Andrey Rogov

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include "Group.h"
#include <vector>
#include <string>

class Group;

class Student {
private:
    std::string fio;
    std::string id;
    std::vector<int> marks;
    Group* group{};
public:
    Student(const std::string& i, const std::string& f);
    void addToGroup(Group* g);
    void addMark(int mark);
    double getAverageMark();
    void setFIO(std::string f);
    std::string getFIO();
    void setId(std::string i);
    std::string getId();
    void setGr(Group* g);
    Group* getGr() const;
    std::vector<int> getMarks() const;
    ~Student();
};

#endif  // INCLUDE_STUDENT_H_
