// copyright Toliman 2021
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
    Student s1(0, "Steve Rambo");
    Student s2(1, "Mark Wolff");
    Student s3(2, "Billy Harrington");
    Student s4(3, "Van Darkholme");
    Group g1("Dungeon");
    Group g2("GYM");
    Group g3("Leatherclub");
    Deanary d1;
    auto s = Deanary::createStudents(5);
    s[0]->str();
    print(s[1]);
    print(s[2]);
    s1.setGroup(g1);
    print(&g1);
    g1.deleteStudent(s1);
    print(s1.getGroup());
    g1.addStudent(s1);
    g1.addStudent(s2);
    g1.addStudent(s3);
    g1.addStudent(s4);
    g1.str();
    print(s1.getGroup()->getTitle());
    g1.str();
    g1.deleteStudent(s1);
    g1.str();
    print(s1.getGroup()->getTitle());

    auto d = new Deanary();
    d->createGroup("group-1.txt");
    d->createGroup("group-2.txt");

    auto s = d->getGroups()[0]->getStudents()[0];
    print(s->getGroup()->getTitle());
    d->changeGroup(*s, *d->getGroups()[1]);
    print(s->getGroup()->getTitle());
    d->getStats();
    d->initializeHeadChoose();
    d->getGroups()[0]->str();
    d->save();


    return 0;
}
