// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>


#include "Student.h"
#include "Deanary.h"
#include "Group.h"

TEST(test, test1) {
    Deanary d;
    Student* s = d.hireStudent(1, "Шар. Ев. Алек.", "HR", 4);
    EXPECT_EQ(false, s->isHeadGroup());
}

TEST(test, test2) {
    Deanary d;
    Student* s = d.hireStudent(1, "Шар. Ев. Алек.", "HR", 4);
    d.addMarks();
    ASSERT_NE(s->getAvrMark(), 0);
}

TEST(test, test3) {
    Deanary d;
    Group* g = d.createGroup("Math", 12);
    EXPECT_EQ(g->isEmpty(), true);
}
TEST(test, test4) {
    Deanary d;
    Student* s = d.hireStudent(1, "Шар. Ев. Алек.", "HR", 4);
    d.initHeads();
    EXPECT_EQ(true, s->isHeadGroup());
}

TEST(test, test5) {
    Deanary d;
    Group* g = d.createGroup("english language", 90);
    d.hireStudent(302, "Шафин Евгений Вадимович", "english language", 90);
    EXPECT_EQ(g->containsStudent(302), true);
}

TEST(test, test6) {
    Deanary d;
    Group* g = d.createGroup("english language", 19);
    d.hireStudent(300, "Шарунов Евгений Вадимович", "english language", 24);
    EXPECT_EQ(g->containsStudent("Шарунов Евгений Вадимович"), false);
}

TEST(test, test7) {
    Deanary d;
    Group* g = d.createGroup("english language", 21);
    d.hireStudent(303, "Шаломов Евгений Вадимович", "Programming", 25);
    d.transferStudent(303, 25);
    EXPECT_EQ(g->containsStudent(300), true);
}
