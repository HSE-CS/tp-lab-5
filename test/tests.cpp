// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>


#include "Student.h"
#include "Deanary.h"
#include "Group.h"

TEST(test, test1) {
Deanary d;
Student* s = d.hireStudent(1, "Шарунов Евгений Александрович", "Programming", 4);
EXPECT_EQ(false, s->isHeadGroup());
}

TEST(test, test2) {
Deanary d;
Student* s = d.hireStudent(1, "Шарунов Евгений Александрович", "Programming", 4);
d.addMarks();

ASSERT_NE(s->getAvrMark(), 0);
}



TEST(test, test3) {
Deanary d;
Group* g = d.createGroup("Math",12);
EXPECT_EQ(g->isEmpty(), true);
}
TEST(test, test4) {
Deanary d;
Student* s = d.hireStudent(900, "Шарунов Евгений Александрович", "Programming", 40);
d.initHeads();
EXPECT_EQ(true,s->isHeadGroup());
}

TEST(test, test5) {
Deanary d;
Group* g = d.createGroup("english language",24);
d.hireStudent(300, "Шарунов Евгений Вадимович", "Programming", 40);
EXPECT_EQ(g->containsStudent(300), true);
}

TEST(test, test6) {
Deanary d;
Group* g = d.createGroup("english language",24);
d.hireStudent(300, "Шарунов Евгений Вадимович", "Programming", 40);
EXPECT_EQ(g->containsStudent("Шарунов Евгений Вадимович"), true);
}

TEST(test, test7) {
Deanary d;
Group* g = d.createGroup("english language",23);
d.hireStudent(300, "Шарунов Евгений Вадимович", "Programming", 40);
d.transferStudent(300, 1);
EXPECT_EQ(g->contains_student(300), true);
}
