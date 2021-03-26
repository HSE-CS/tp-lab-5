// Copyright [2021] <Nikita Semaev>
#include <string>
#include <vector>
#include "../include/Deanary.h"

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

class Student;
class Deanery;

class Group {
 public:
    explicit Group(std::string title) : title(title), head(nullptr) {}
    Student* findStudent(const uint16_t id);
    Student* findStudent(const std::string fio);
    void addStudent(Student *student);
    void setHead(Student *student);
    float averageMark() const;
    void excludeStudent(Student *student);
    const std::vector <Student *> &getStudents() const;
    const std::string &getTitle() const;

 private:
    std::string title;
    std::string spec;
    std::vector <Student *> students;
    Student* head;

    bool isExist(Student *student);
};

#endif  // INCLUDE_GROUP_H_
