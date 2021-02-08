// Copyright Roman Balayan @ 2021

#pragma once

#include <vector>
#include <memory>
#include <cstdlib>
#include <iostream>
#include <string>

#include "../include/Group.h"

class Group;
class Student;

class Deanary {
 public:
    Deanary() { }
    void addGroup(const std::shared_ptr<Group>& group);
    void addStudent(const std::shared_ptr<Student>& student);
    void addRandomMarks(int16_t amount = 5);
    void printStatistics();
    bool changeGroup(std::shared_ptr<Student>& student, 
                     std::shared_ptr<Group>& newGroup);
    bool changeGroup(int16_t studentID, std::string newGroupTitle);
    bool removeBadStudents(double minAverageScore = 2.5);
 private:
    std::vector<std::shared_ptr<Group> > groups;

};
