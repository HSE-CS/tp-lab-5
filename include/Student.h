#ifndef LAB5_STUDENT_H
#define LAB5_STUDENT_H

#include <iostream>
#include <string>
#include <cstring>
#include <vector>

using namespace std;

class Group;

class Student{
private:
    int num = 0;
    Group *group;
    string fio;
    vector<int> Marks;
    double avr = average();

public:
    int id;
    Student(int a, string f);
    Student();
    void addMark(int m);
    void show();
    double average();
    string getFio();
    void printMarks();
    void setGroup(Group *g);
    Group* getGroup();
    double getAvr();
    void setAvr(double a);
};

#endif //LAB5_STUDENT_H