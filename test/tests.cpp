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
    EXPECT_EQ(s1.getFio(), g1.searchStudent(0)->getFio());
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

TEST(test, test4) {
    Student s1(0, "Steve Rambo");
    EXPECT_EQ(s1.getFio(), std::string(""));
}

TEST(test, test5) {
    Deanary d;
    d.createGroup("group-1.txt");
    auto g1 = d.getGroups()[0];
    float m = g1->getMiddleMark();
    EXPECT_GE(m, 0);
}

TEST(test, test6) {
    Deanary d;
    d.createGroup("group-1.txt");
    auto g1 = d.getGroups()[0];
    float m = g1->getMiddleMark();
    EXPECT_LE(m, 10);
}

TEST(test, test7) {
    Group g("GYM");
    Student s1(1946729, "Boss of this gym");
    Student s2(0, "Leatherman");
    Student s3(97346, "Jabroni");
    Student s4(32434, "College boy");
    g.addStudent(s1);
    g.addStudent(s2);
    g.addStudent(s3);
    g.addStudent(s4);
    Deanary::addMark(s1, 3);
    Deanary::addMark(s3, 5);
    EXPECT_GE(g.getMiddleMark(), 0);
}
