// Copyright Roman Balayan @ 2021

#pragma once
#include <string>
#include <memory>
#include <vector>
#include <numeric>
#include "../include/Group.h"

class Group;

using u_int = unsigned int;
class Student {

public:
    Student(const std::string name);
    Student(const std::string name, std::vector<short>& marks);
    Student(const std::string name, std::shared_ptr<Group>& group);
    Student(const std::string name, std::shared_ptr<Group>& group, std::vector<short>& marks);
    bool setGroup(std::shared_ptr<Group>& group);
    void addMark(const short mark);
    void printStudent() const;
    float getAverageMark() const;
    std::string getName() const;
    u_int getId() const;
    std::weak_ptr<Group> getGroup() const;
private:
    static u_int id_generator;
    u_int id;
    std::string name;
    std::weak_ptr<Group> group;
    std::vector<short> marks;

    friend class Group;
};
