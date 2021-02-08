// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_
#include <string>
#include <vector>
#include <Student.h>

class Student;
class Group {
    friend class Student;
    friend class Deanary;

 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* head = nullptr;

 public:
    explicit Group(std::string title, std::string spec);
    void addStudent(Student* student);
    void kickStudent(Student* student);
    void chooseHead(Student* student);
    Student* getStudentById(int student_id);
    Student* getStudentByFio(std::string student_name);
    float getAverageMark();
    std::string getTitle();
    std::string getSpec();
    Student* getHead();
    bool isEmpty();
};


#endif  // INCLUDE_GROUP_H_
