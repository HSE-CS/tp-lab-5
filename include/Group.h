// Copyright [2021] <Ziganshin Nikita>
#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include "Student.h"
#include <string>
#include <vector>

class Student;

class Group {
    friend class Student;

 private:
    std::string title;
    std::string spec;
    std::vector<Student> students;
    Student *head;

 public:
    Student *getHead() const;

    void setHead(Student *head);

    explicit Group(std::string title);

    ~Group();

    void AddStudent(const Student &student);

    Student *FindStudent(const std::string &fio);

    Student *FindStudent(int id);

    double CalcAverageMarkInGroup();

    void KickStudent(Student *student);

    std::string getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getSpec() const;

    void setSpec(const std::string &spec);

    std::vector<Student> *getStudents();
};

#endif  // INCLUDE_GROUP_H_
