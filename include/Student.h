// Copyright 2021 Stolbov Yaroslav

#ifndef INCLUDE_STUDENT_H
#define INCLUDE_5_STUDENT_H

#include <string>
#include <vector>
#include "Group.h"
class Group;
class Deanary;

class Student {

private:
    int id;
    std::string fio;
    Group* group{};
    std::vector<int> marks;

public:
    friend class Group;
    friend class Deanary;
    static int userId;

    explicit Student(int, std::string);

    void addMark(int mark);

    double getMiddleMark();

    [[nodiscard]] int getId() const;

    void setId(int id);

    [[nodiscard]] const std::string &getFio() const;

    void setFio(const std::string &fio);

    [[nodiscard]] const Group &getGroup() const;

    void addGroup(Group* group);

    [[nodiscard]] const std::vector<int> &getMarks() const;

    void setMarks(const std::vector<int> &myMarks);
};


#endif // INCLUDE_STUDENT_H
