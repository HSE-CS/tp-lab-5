//
// Created by Краюшкина Екатерина on 08.02.2021.
//

#include "Group.h"
#include "Student.h"

using namespace std;

Group::Group(string a) {
title = a;
numS = 0;
}

void Group::addStudent(Student *a) {
    students.push_back(a);
    students[numS] -> setGroup(this);
    numS++;
}

void Group::printStudent(int a) {
    students[a]->show();
}

void Group::printAll() {
    for (int i = 0; i < numS; i++)
        printStudent(i);
}

string Group::getGroup(){
    return title;
}

int Group::searchStudent(int a) {
    for (int i = 0; i < numS; i++)
        if (students[i]->id == a)
        {
            students[i]->show();
            return i;
        }
    cout << endl << "No student with ID " << a << endl;
    return -1;
}

int Group::searchStudent(string h) {
    int ch = 0;
    cout << endl;
    for (int i = 0; i < numS; i++)
        if (students[i]->getFio() == h) {
            cout << "Founded: ";
            students[i]->show();
            return i;
        }
    cout << endl << "No student "<< h << endl;
    return -1;
}

double Group::groupAverage() {
    double sum = 0;
    for (int i = 0; i < numS; i++)
        sum = sum + students[i]->average();
    //scout << "\nGroup " << getGroup() << " AVR: "<<sum / numS;
    return sum / numS;
}

void Group::election(){
    srand (time(NULL));
    int rnum = rand() % numS;
    head = (students[rnum]);

}

void Group::exclude(string h){
    int i = searchStudent(h);
    if (i!=-1)
    {
        cout << "killin " << students[i]->getFio() << endl;
        bool repElec = false;
        if ((students[i])==head)
            repElec = true;
        students.erase(students.begin() + i);
        numS--;
        if (repElec)
            this->election();
    }
}


void Group::exclude(int n){
    int i = searchStudent(n);
    if (i!=-1)
    {
        cout << "killin " << students[i]->getFio() << endl;
        bool repElec = false;
        if ((students[i])==head)
            repElec = true;
        students.erase(students.begin() + i);

        numS--;
        if (repElec)
            this->election();
    }
}

Student *Group::getHead() {
    return head;
}