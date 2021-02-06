// Copyright 2021 MalininDmitry
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;

class Student{
 private:
    int id;
    std::string fio;
    Group * group;
    std::vector<int> marks;

 public:
    explicit Student(int id, std::string fio);

    ~Student();

    double getAveragemark();

    int getId();

    std::string getFio();

    void addToGroup(Group * groupName);

    void addMark(int mark);

    void changeId(int index);

    Group * getGroup();
};

#endif  // INCLUDE_STUDENT_H_

