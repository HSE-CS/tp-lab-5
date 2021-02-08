//
// Created by Краюшкина Екатерина on 08.02.2021.
//

#include "Student.h"


    Student::Student(int a, string f) {
        this->fio = f;
        this->id = a;
    }
    Student::Student() = default;

    void Student::addMark(int m) {
        num++;
        Marks.insert(Marks.end(), m);
    }

    void Student::show() {
        cout << "ID" << id << ": " << fio << " | Marks: ";
        printMarks();
        cout << " | Avr: " << average();
        cout << endl;
    }

    double Student::average() {
        double sum = 0;
        for (int i = 0; i < num; i++)
            sum = sum + Marks[i];
        return sum / num;
    };

    string Student::getFio() {
        return fio;
    }
    void Student::printMarks() {
        for (int i = 0; i < num; i++)
            cout << Marks[i] << " ";
    }


    /*void Student::printGroup(){
        cout << group->getGroup() << endl;
    }*/

    void Student::setGroup(Group *g) {
        this->group = g;
    }

Group *Student::getGroup() {
    return group;
}

double Student::getAvr() {
    return avr;
}

void Student::setAvr(double) {
        avr = this->average();
}