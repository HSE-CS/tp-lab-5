// Copyright 2021 Shatilov Victor

#include "Deanary.h"
#include "Group.h"
#include "Student.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Test, test1) {
Student s1(1, "Шатилов Виктор");
s1.rate(8);
s1.rate(4);
EXPECT_FLOAT_EQ(6, s1.getAverageMark());
}

TEST(Test, test2) {
Group gr("19ПИ-1", "Программная инженерия");
EXPECT_TRUE(gr.isEmpty());
}

TEST(Test, test3) {
Deanary d;
d.createGroup("19ПИ-1", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-1");
EXPECT_EQ("Программная инженерия", gr->getSpec());
}

TEST(Test, test4) {
Deanary d;
d.createGroup("19ПИ-1", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-1");

Student s1(1, "Ваня Ургант");
s1.rate(3.0);
Student s2(2, "Ваня Ушлёпышь");
s2.rate(2.0);
gr->addStudent(&s1);
gr->addStudent(&s2);
d.kickStudentsForBadMarks(5.0);
EXPECT_TRUE(gr->isEmpty());
}

TEST(Test, test5) {
Deanary d;
d.createGroup("19ПИ-2", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-2");
d.createStudent("Шатилов Виктор", gr);

EXPECT_EQ(1, gr->getStudentByFio("Шатилов Виктор")->getId());
}

TEST(Test, test6) {
Deanary d;
d.createGroup("19ПИ-2", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-2");
d.createStudent("Лол Кеков", gr);
d.createStudent("Кек Лолов", gr);
EXPECT_EQ("Кек Лолов", gr->getStudentById(2));
}

TEST(Test, test7) {
Deanary d;
d.createGroup("19ПИ-2", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-2");
d.createStudent("Лол Кеков", gr);
d.createStudent("Митя Петин", gr);

gr->kickStudent(gr->getStudentById(1));
gr->kickStudent(gr->getStudentById(2));
EXPECT_TRUE(gr->isEmpty());
}

TEST(Test, test8) {
Deanary d;
d.createGroup("19ПИ-2", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-2");
d.createStudent("Лол Кеков", gr);
d.createStudent("Митя Петин", gr);
d.createStudent("Ваня Ургант", gr);

gr->kickStudent(gr->getStudentById(1));
gr->kickStudent(gr->getStudentById(2));
EXPECT_EQ(3, gr->getStudentByFio("Ваня Ургант")->getId());
}

TEST(Test, test9) {
Deanary d;
d.createGroup("19ПИ-2", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-2");
d.createStudent("Лол Кеков", gr);
d.createStudent("Митя Петин", gr);
d.createStudent("Ваня Ургант", gr);

Student *s = gr->getStudentByFio("Ваня Ургант");
s->rate(2);
s->rate(2);
s = gr->getStudentByFio("Лол Кеков");
s->rate(3);
s->rate(3);
s = gr->getStudentByFio("Митя Петин");
s->rate(4);
s->rate(4);

EXPECT_FLOAT_EQ(3.0, gr->getAverageMark());
}

TEST(Test, test10) {
Deanary d;
d.createGroup("19ПИ-2", "Программная инженерия");
Group *gr = d.getGroupByTitle("19ПИ-2");
d.createStudent("Лол Кеков", gr);
d.createStudent("Митя Петин", gr);
d.createStudent("Ваня Ургант", gr);

Student *s = gr->getStudentByFio("Ваня Ургант");
s->rate(2);
s->rate(2);
s = gr->getStudentByFio("Лол Кеков");
s->rate(3);
s->rate(3);
s = gr->getStudentByFio("Митя Петин");
s->rate(4);
s->rate(4);

d.initHeads();

EXPECT_EQ(s->getId(), gr->getHead()->getId());
}

TEST(Test, test11) {
Deanary d;
d.createGroup("19ПИ-2", "Программная инженерия");
d.createGroup("19PI-1", "Программная инженерия");

Group *gr1 = d.getGroupByTitle("19PI-1");
Group *gr2 = d.getGroupByTitle("19ПИ-2");

d.createStudent("Лол Кеков", gr1);
d.createStudent("Митя Петин", gr2);
d.createStudent("Ваня Ургант", gr2);

Student *s = gr2->getStudentByFio("Ваня Ургант");
s->rate(2);
s->rate(2);
s = gr1->getStudentByFio("Лол Кеков");
s->rate(3);
s->rate(3);
s = gr2->getStudentByFio("Митя Петин");
s->rate(4);
s->rate(4);

d.moveStudent(s, gr1);
EXPECT_EQ(2, gr1->getStudentByFio("Митя Петин")->getId());
}