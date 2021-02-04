// Copyright 2021 soda

#ifndef LAB_5_GROUP_H
#define LAB_5_GROUP_H

#include <string>
#include <vector>


class Student;

class Deanary;

class Group {
    friend class Deanary;
private:
    std::string title;
    std::string spec;
    std::vector<Student*>* students;
    Deanary* deanary;
    Student* head{};
    int head_id;
    void addStudent(Student* student);
    void removeStudent(Student* student);
    void chooseHead();
public:
    Group(std::string& _title_, std::string& _spec_, Deanary& _deanary_) :
        title(_title_), spec(_spec_), head_id(-1), deanary(&_deanary_),
        students(new std::vector<Student*>()) {}
    Group(std::string& _title_, std::string& _spec_) :
        title(_title_), spec(_spec_), head_id(-1), deanary(nullptr),
        students(new std::vector<Student*>()) {}
    Student& getStudent(int);
    Student& getStudent(std::string&);
    Student& getHead();
    std::string getTitle();
    std::vector<Student*>* getGroupStudents();
    int containsStudent(Student&);
    double getAverageMark();
    bool isEmpty();
    ~Group();

};


#endif  // LAB_5_GROUP_H