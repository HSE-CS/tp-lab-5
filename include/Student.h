// Copyright [2021] <Ziganshin Nikita>
#ifndef TP_LAB_5_STUDENT_H_
#define TP_LAB_5_STUDENT_H

#include <string>
#include <vector>
#include "Group.h"
#include <iostream>

class Group;

class Student {
    friend class Group;

    friend class Deanery;

 private:
    int id;
    std::string fio;
    std::vector<int> marks;
    Group *group;
 public:
    Student(int id, std::string fio);

    explicit Student(Student *student);

    ~Student();

    void AddGroup(Group *group);

    void AddMark(int mark);

    double CalcAverageMark();

    int getId() const;

    const std::string &getFio() const;

    Group *getGroup() const;

    void setId(int id);

    void setFio(const std::string &fio);

    const std::vector<int> &getMarks() const;
};

#endif  // TP_LAB_5_STUDENT_H_
