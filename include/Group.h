// Copyright 2021 Shatilov Victor

#ifndef INCLUDE_GROUP_H
#define INCLUDE_GROUP_H
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
    explicit Group(std::string title);
    void addStudent(Student* student);
    void delStudent(Student* student);
    void appointHead(Student* student);
    Student* findStudentById(int student_id);
    Student* findStudentByFio(std::string student_name);
    float getAverageMark();
    std::string getTitle();
    std::string getSpec();
};


#endif //INCLUDE_5_GROUP_H
