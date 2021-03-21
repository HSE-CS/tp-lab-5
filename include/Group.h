//
// Created by mushka on 19.03.2021.
//

#ifndef TP_LAB_5_GROUP_H
#define TP_LAB_5_GROUP_H
#include <string>
#include <vector>


class Student;
class Group {
    friend class Student;
    friend class Deanary;

private:
    std::string title;
    std::string spec;
    std::vector<Student*> students;
    Student* leader = nullptr;

public:
    explicit Group(std::string title, std::string spec);

    void AddStudent(Student* student);
    void RemoveStudent(Student* student);
    void ChooseLeader(Student* student);
    float CountAvgMark();

    Student* GetById(int student_id);
    Student* GetByFio(const std::string& student_name);


    std::string GetTitle();
    std::string GetSpec();
    Student* GetLeader();
    bool IsEmpty();
};



#endif //TP_LAB_5_GROUP_H
