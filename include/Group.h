// Copyright 2021 MalininDmitry
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>

class Student;

class Group{
 private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student * head;

 public:
    explicit Group(std::string title, std::string spec);

    explicit Group(std::string title);

    void addStudent(Student * student);

    void chooseHead(Student * student);

    void chooseHead();

    void removeStudent(Student *student1);

    double getAverageMark();

    Student * containsStudent(int num);

    Student * containsStudent(std::string fio);

    int countStudent();

    std::vector<Student*> listStudent();

    std::string getSpec();

    std::string getTitle();

    bool isEmpty();
};

#endif  // INCLUDE_GROUP_H_

