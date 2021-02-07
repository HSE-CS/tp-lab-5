// Copyright 2020 VladimirUspensky

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

class Student;
class Deanary;


class Group {
 private:
    std::string title;
    std::string spec;
    Student* head;

 public:
    std::vector<Student*> students;
    std::string getTitle();
    explicit Group(std::string title);
    void addStudent(Student* student);
    void removeStudent(Student* student);
    void chooseHead();
    Student* searchStudentById(int id);
    Student* searchStudentByName(std::string name);
    double getAverageGroupMark();
};

#endif // INCLUDE_GROUP_H_
