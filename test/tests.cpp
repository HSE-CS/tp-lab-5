// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <fstream>

#include "Deanary.h"

TEST(test, test1) {
    Deanary d;
    d.createGroup("group-1.txt");
    d.save();
    std::fstream oldSave("../../Groups/group-1.txt");
    std::fstream newSave("../../Groups1/group-1.txt");
    int s1, s2;
    std::string c1, c2;
    oldSave >> s1;
    newSave >> s2;
    for (int i = 0; i < s1 + 1; i++) {
        std::getline(oldSave, c1);
        std::getline(newSave, c2);
    }
    EXPECT_EQ(c1, c2);
}

TEST(test, test2) {
    Student s1(0, "Van Darkholme");
    Group g1("Dungeon");
    g1.addStudent(s1);
    EXPECT_EQ(g1.getTitle(), s1.getGroup()->getTitle());
}

TEST(test, test3) {
    Deanary d;
    d.createGroup("group-1.txt");
    d.createGroup("group-2.txt");
    auto g1 = d.getGroups()[0];
    auto g2 = d.getGroups()[1];
    Student s1(0, "Mark Wolff");
    g1->addStudent(s1);
    Deanary::changeGroup(s1, *(d.getGroups()[1]));
    EXPECT_EQ((*g2).getTitle(), s1.getGroup()->getTitle());
}

//TEST(test, test4) {
//
//}
//
//TEST(test, test5) {
//
//}
//
//TEST(test, test6) {
//
//}
//
//TEST(test, test7) {
//
//}
//
//TEST(test, test8) {
//
//}
//
//TEST(test, test9) {
//
//}
//
//TEST(test, test10) {
//
//}
