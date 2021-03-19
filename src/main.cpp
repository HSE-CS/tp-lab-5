//
// Created by mushka on 19.03.2021.
//

#include "../include/Deanary.h"
#include <iostream>

int main() {
    Student s = Student(1,"a s");
    Student * s1 = &s;

    Group g = Group("PI","programming");
    Group * g1 = &g;
    g.ChooseLeader(s1);
    cout << g.GetHead()->GetFio();
}