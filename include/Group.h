// Copyright Mushka Nikita, 2021

#ifndef INCLUDE_GROUP_H_
#define INCLUDE_GROUP_H_

#include <string>
#include <vector>


class Student;

class Group {
    friend class Student;

    friend class Deanary;

 private:
    std::string title;
    std::string spec;
    std::vector<Student *> students;
    Student *leader = nullptr;

 public:
    explicit Group(std::string title, std::string spec);

    void AddStudent(Student *student);

    void RemoveStudent(Student *student);

    void ChooseLeader(Student *student);

    float CountAvgMark();

    Student *GetById(int student_id);

    Student *GetByFio(const std::string &student_name);

    std::string GetTitle();

    std::string GetSpec();

    Student *GetLeader();

    bool IsEmpty();
};


#endif  // INCLUDE_GROUP_H_
