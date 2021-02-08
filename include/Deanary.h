// Copyright 2021 SharunovEvgeny
//
// Created by sharg on 06.02.2021.
//
#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <fstream>

class Group;
class Student;

class Deanary {
 private:
    std::vector<Group*> groups;
    Group *findGroup(int title);
    Student* findStudent(unsigned int id);

 public:
    Deanary() = default;
    void addMarks();
    std::string getStat() const;
    void transferStudent(unsigned int id, int title);
    void readFile(const std::string&);
    void saveStaff(const std::string&) const;
    void initHeads();
    Group* createGroup(std::string valSpec, int valTitle);
    Student* hireStudent(unsigned int id,std::string,std::string,int);



};

#endif  // INCLUDE_DEANARY_H_
