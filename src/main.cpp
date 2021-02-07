// Copyright 2021
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <string>

int main() {
    Student st("1", 1);
    auto s = st.getFio();
    Deanary dr;
    dr.createGroups("group.txt");
    dr.hireStudents("students.txt");
    dr.addMarkToAll();
    dr.moveStudents();
    dr.initHead();
    dr.printInfo();
    dr.moveStudent("Lewis Ramirez", "First group");
    dr.fireStudent();
    dr.printInfo();
    dr.saveStuff("out.txt");
}
