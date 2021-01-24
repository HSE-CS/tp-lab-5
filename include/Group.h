// Copyright 2021 soda

#ifndef LAB_5_GROUP_H
#define LAB_5_GROUP_H

#include <string>
#include <vector>


class Student;

class Deanery;

class Group {
    friend class Deanery;
 private:
    std::string title;
    std::string spec;
    std::vector<Student*>* students;
    Student* head{};
    void addStudent(Student& student);
    void removeStudent(Student& student);
    void chooseHead(int oldHeadId = -1, bool silence = true);
 public:
    Group(std::string& _title, std::string& _spec):
        title(_title), spec(_spec),
        students(new std::vector<Student*>()) {}
    double getAverageMark();
    Student& getStudent(int);
    int containsStudent(Student&);
    std::string getTitle();
    Student& getHead();
    bool isEmpty();
    ~Group();

    //Student& getStudent(const std::string& fio);
};


#endif  // LAB_5_GROUP_H