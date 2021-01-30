// Copyright 2021 soda

#ifndef LAB_5_GROUP_H
#define LAB_5_GROUP_H

#include <string>
#include <vector>


class Student;

class Deanery;

class Group {
    friend class Deanary;
 private:
    std::string title;
    std::string spec;
    std::vector<Student*>* students;
    Deanary* deanary;
    Student* head{};
    void removeStudent(Student& student);
    void addStudent(Student& student);
 public:
    Group(std::string& _title_, std::string& _spec_, Deanary& _deanary_):
        title(_title_), spec(_spec_), deanary(&_deanary_),
        students(new std::vector<Student*>()) {}
    double getAverageMark();
    Student& getStudent(int);
    Student& getStudent(std::string&);
    int containsStudent(Student&);
    std::string getTitle();
    Student& getHead();
    bool isEmpty();
    ~Group();

    //Student& getStudent(const std::string& fio);
};


#endif  // LAB_5_GROUP_H