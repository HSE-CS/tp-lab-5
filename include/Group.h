#ifndef LAB5_GROUP_H
#define LAB5_GROUP_H

#include "Student.h"
#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <time.h>

using namespace std;


class Group {
private:
    string title;
    int numS;
    vector<Student*> students;
    Student *head;
    int searchStudent(int a);
    int searchStudent(string h);
    void printStudent(int a);
public:
    Student *getStudent(int i);
    Group(string a);
    void addStudent(Student *a);
    void printAll();
    string getGroup();
    double groupAverage();
    void election();
    void exclude(string h);
    void exclude(int n);
    Student* getHead();

};


#endif //LAB5_GROUP_H