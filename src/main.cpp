// Copyright 2021 Andrey Rogov

#include <iostream>
#include "Deanary.h"
#include "Student.h"
#include "Group.h"

int main() {
    Deanary deanary;
    deanary.createGroups();
    deanary.sortStudents(deanary.hireStudents());
    deanary.initHeads();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    deanary.addMarksToAll();
    std::vector<Student*> delstds = { new Student("00011", "Elon Musk") };
    deanary.fireStudents(delstds);
    deanary.getStatistics();
    deanary.saveStaff();
    std::vector<Student*> movstds = { new Student("00000", "Joe Biden") };
    deanary.moveStudents(deanary.getGroups()[0],
        deanary.getGroups()[1], movstds);
    deanary.getStatistics();

    Group gr("PI", "hardware engineering");
    Student st("00000", "Donald Trump");
    gr.addStudent(&st);
    std::cout << st.getGr()->getSpec();
}