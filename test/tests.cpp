// Copyright 2021 Artem Danyaev
#include "Deanary.h"
#include "Group.h"
#include "Student.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

TEST(Test, test1) {
  Student s1(1, "Ivan Petrov");
  s1.addMark(3);
  s1.addMark(4);
  EXPECT_FLOAT_EQ(3.5, s1.getAverageMark());
}

TEST(Test, test2) {
  Group gr("19PI-2", "pi");
  EXPECT_TRUE(gr.isEmpty());
}

TEST(Test, test3) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_EQ("pi", gr->getSpec());
}

TEST(Test, test4) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_EQ("pi", gr->getSpec());
}

TEST(Test, test5) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_TRUE(gr->containsStudentByFio("Ivan Petrov"));
}

TEST(Test, test6) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  d.hireStudent("Petr Sidorov", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_TRUE(gr->containsStudentById(2));
}

TEST(Test, test7) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  d.hireStudent("Petr Sidorov", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  std::vector<Student *> toBeDeleted;
  toBeDeleted.push_back(gr->getStudentByFio("Ivan Petrov"));
  toBeDeleted.push_back(gr->getStudentByFio("Petr Sidorov"));
  d.fireStudents(toBeDeleted);
  EXPECT_TRUE(gr->isEmpty());
}

TEST(Test, test8) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  d.hireStudent("Petr Sidorov", "19PI-2");
  d.hireStudent("Boris Britva", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  std::vector<Student *> toBeDeleted;
  toBeDeleted.push_back(gr->getStudentByFio("Ivan Petrov"));
  toBeDeleted.push_back(gr->getStudentByFio("Petr Sidorov"));
  d.fireStudents(toBeDeleted);
  EXPECT_TRUE(gr->containsStudentByFio("Boris Britva"));
}

TEST(Test, test9) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  d.hireStudent("Petr Sidorov", "19PI-2");
  d.hireStudent("Boris Britva", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  Student *s = gr->getStudentByFio("Boris Britva");
  s->addMark(2);
  s->addMark(2);
  s = gr->getStudentByFio("Ivan Petrov");
  s->addMark(3);
  s->addMark(3);
  s = gr->getStudentByFio("Petr Sidorov");
  s->addMark(4);
  s->addMark(4);

  EXPECT_FLOAT_EQ(3.0, gr->getAverageMark());
}

TEST(Test, test10) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  d.hireStudent("Petr Sidorov", "19PI-2");
  d.hireStudent("Boris Britva", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  Student *s = gr->getStudentByFio("Boris Britva");
  s->addMark(2);
  s->addMark(2);
  s = gr->getStudentByFio("Ivan Petrov");
  s->addMark(3);
  s->addMark(3);
  s = gr->getStudentByFio("Petr Sidorov");
  s->addMark(4);
  s->addMark(4);

  d.initHeads();

  EXPECT_TRUE(s->isHeadOfGroup());
}

TEST(Test, test11) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.createGroup("19PI-1", "pi");
  d.hireStudent("Ivan Petrov", "19PI-1");
  d.hireStudent("Petr Sidorov", "19PI-2");
  d.hireStudent("Boris Britva", "19PI-2");
  Group *gr2 = d.getGroup("19PI-2");
  Group *gr1 = d.getGroup("19PI-1");
  Student *s = gr2->getStudentByFio("Boris Britva");
  s->addMark(2);
  s->addMark(2);
  s = gr1->getStudentByFio("Ivan Petrov");
  s->addMark(3);
  s->addMark(3);
  s = gr2->getStudentByFio("Petr Sidorov");
  s->addMark(4);
  s->addMark(4);

  d.moveStudent(s, "19PI-1");
  EXPECT_TRUE(gr1->containsStudentByFio("Petr Sidorov"));
}
