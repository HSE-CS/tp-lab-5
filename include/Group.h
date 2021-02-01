// Copyright by JMax 2020

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>
#include "Deanary.h"
#include "Student.h"

class Student;

class Group {
    friend class Deanary;
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head;

    void addStudent(Student* student);
    void chooseHead();
    void removeStudent(Student* student);
    void removeStudent(unsigned int id);
    void removeStudent(const std::string& fio);
    int studentIndex(unsigned int id) const;
    int studentIndex(const std::string& fio) const;

 public:
    Group(const std::string& title, const std::string& spec);
    ~Group();
    double getAverageMark() const;
    Student* getStudent(unsigned int id) const;
    Student* getStudent(const std::string& fio) const;
    bool containsStudent(unsigned int id) const;
    bool containsStudent(const std::string& fio) const;
    bool isEmpty() const;
    unsigned int numOfStudents() const;
    Student* getHead() const;
    void setHead(const std::string& fio);
};

#endif  // INCLUDE_GROUP_H_
