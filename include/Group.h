#ifndef TP_LAB_5_GROUP_H
#define TP_LAB_5_GROUP_H

#include "Student.h"

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

    Group(std::string title);

    ~Group();

    void AddStudent(const Student &student);

    Student *FindStudent(const std::string &fio);

    Student *FindStudent(int id);

    double CalcAverageMarkInGroup();

    void KickStudent(Student &student);

    std::string getTitle() const;

    void setTitle(const std::string &title);

    const std::string &getSpec() const;

    void setSpec(const std::string &spec);

    std::vector<Student> *getStudents();
};

#endif //TP_LAB_5_GROUP_H
