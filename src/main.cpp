// Copyright 2021 Bodrov Egor
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <vector>
#include <string>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

int main()
{
    Student s1 {12, "Egor Bodrov"};
    Student s2 {50, "Michele Bekuson"};
    Student s3 {11, "Bodrov Egor"};
    Student s4 {77, "Bekuson Michele"};
    Group gr1 {"19SE-2", "SE"};
    gr1.addStudent(&s1);
    gr1.addStudent(&s2);
    gr1.addStudent(&s3);
    gr1.addStudent(&s4);
    gr1.removeStudent(&s1);
    gr1.removeStudent(&s2);
    gr1.removeStudent(&s3);
    gr1.removeStudent(&s4);
    std::cout << gr1.isEmpty();
    return 0;
}