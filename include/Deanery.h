// Copyright 2021 valvarl

#ifndef INCLUDE_DEANERY_H_
#define INCLUDE_DEANERY_H_

#include <vector>
#include <string>
#include <random>
#include "Student.h"

class Student;

class Group;

class Deanery {
 private:
    int id;
    std::vector<Group *> *groups;
    void createGroups();
    void hireStudents();
    std::stringbuf generateStatistic();
    std::minstd_rand simple_rand;
    Group &groupByStudent(int _id);
    Group &groupByStudent(const std::string& name);
    Group &getGroup(const std::string &title);
    std::string getProjectPath();

 public:
    Deanery();
    void addMarksToAll(int amount);
    void getStatistics();
    void moveStudents(int _id, const std::string &title);
    void moveStudents(const std::string& name, const std::string &title);
    void saveStuff();
    void initHeads();
    void fireStudents(int _id);
    void fireStudents(const std::string& name);
    std::vector<Group *> *getGroups() const;
    int rand_int() { return simple_rand(); }
    ~Deanery();
};

#endif  // INCLUDE_DEANERY_H_
