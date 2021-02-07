// Copyright 2021 Artem Danyaev
#include "Deanary.h"
#include "Group.h"
#include "Student.h"
#include <gtest/gtest.h>
#include <string>
#include <vector>

Test(StudentTest, test1) {
  Student s1(1, "Ivan Petrov");
  s1.addMark(3);
  s1.addmark(4);
  EXPECT_FLOAT_EQ(3.5, s1.getAverageMark());
}

Test(StudentTest, test2) {
  Group gr("19PI-2", "pi");
  EXPECT_TRUE(gr.isEmpty());
}

Test(StudentTest, test3) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_EQ("pi", gr->getSpec());
}

Test(StudentTest, test4) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_EQ("pi", gr->getSpec());
}

Test(StudentTest, test5) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_TRUE(gr->containsStudentByFio("Ivan Petrov"));
}

Test(StudentTest, test6) {
  Deanary d;
  d.createGroup("19PI-2", "pi");
  d.hireStudent("Ivan Petrov", "19PI-2");
  d.hireStudent("Petr Sidorov", "19PI-2");
  Group *gr = d.getGroup("19PI-2");
  EXPECT_TRUE(gr->containsStudentId(2));
}

Test(StudentTest, test7) {
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

Test(StudentTest, test8) {
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

Test(StudentTest, test9) {
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

Test(StudentTest, test10) {
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

Test(StudentTest, test11) {
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
