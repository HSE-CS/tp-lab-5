//
// Created by toliman on 03.02.2021.
//

#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"

template<typename T>
void print(T value) {
    std::cout << value << '\n';
}

signed main() {
    Student s(0, "Obiwan Kenobi");
    Group g("19SE-2");

    s.setGroup(g);
    print(s.getGroup()->getTitle());
    g.setTitle("19SE-1");
    print(s.getGroup()->getTitle());

    return 0;
}
