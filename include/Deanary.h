//
// Created by Краюшкина Екатерина on 08.02.2021.
//

#ifndef LAB5_DEANARY_H
#define LAB5_DEANARY_H


#include "Student.h"
#include "Group.h"


class Deanary {
private:
    vector<Student *> students;
    vector<Group *> groups;
    int id = 0;
public:

    void addStudentFromFile(string f);

    void createGroupFromFile(string f);

    void addRandomMarks();

    void printGroup(string f);

    int findPos(string f);

    void Statistics();

    void Statistics(int n);

    void moveFromGroup(string st, string gr);

    int findStudent(string st);

    void moveFromGroup(int numId, string gr);

    int findStudent(int numId);

    void removeDvoechnik();

    void writeToNewFile(string f);

    void makeHead();

    };

#endif //LAB5_DEANARY_H