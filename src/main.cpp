// Copyright 2021 Stolbov Yaroslav
#include <iostream>
#include "Student.h"
#include "Group.h"
int main(){
    Student student1 = Student(Student::userId, "Ziganshin N.R.");
    student1.addMark(5);
    student1.addMark(3);
    //std::cout<<student1.getMiddleMark();
    Student student2 = Student(Student::userId, "Stolbov Y.V.");
    student2.addMark(4);
    Group group1 = Group("Something group", "PE");
    //student1.addGroup(&group1);
    group1.addStudent(student1);
    group1.addStudent(student2);
    group1.removeStudent(2);
    return 0;
}

