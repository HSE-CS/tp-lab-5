// copyright Toliman 2021

#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <iostream>
#include <fstream>
#include <vector>

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

    void setGroup(Group groupParam);

    Group *getGroup();

    void addMark(int mark);

    float getMiddleMark();

    void str();

    void leaveGroup();
};


#endif  // INCLUDE_STUDENT_H_
