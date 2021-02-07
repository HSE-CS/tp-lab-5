#ifndef TP_LAB_5_GROUP_H
#define TP_LAB_5_GROUP_H

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


#endif //TP_LAB_5_GROUP_H
