// Copyright 2021 dmitrycvetkov2000


#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;
class Deanary;

class Student {
    public:
    friend class Group;
    friend class Deanary;

    Student(int id, std::string name);

    void addToGroup(Group *group);
    void addMark(int mark);

    double getAverageMark() const;
    bool isHeadOfGroup() const;

    private:
    int id;
    std::string name;
    Group* group;
    std::vector<int> marks;
};

#endif  // INCLUDE_STUDENT_H_
