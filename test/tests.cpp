// Copyright 2020 Konina Tatiana

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


TEST(st_test, test1) {
  Deanery* d = new Deanery("specList.txt", "students.txt");
  Student* st = d->findStudent(2);
  EXPECT_EQ(2, 2);
  delete st;
  delete d;
}

TEST(st_test, test2) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Student* st = test->findStudent(2);

  EXPECT_EQ("Peter Parker", st->getFio());
  delete st;
  delete test;
}

TEST(st_test, test3) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Student* st = test->findStudent(2);

  EXPECT_EQ(false, st->isHeadOfGroup());
  delete st;
  delete test;
}

TEST(gr_test, test4) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Group* gr = test->getGroups()[0];
  EXPECT_EQ(4, gr->getGroupSize());
  delete gr;
  delete test;
}

TEST(gr_test, test5) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Group* gr = test->getGroups()[1];
  EXPECT_DOUBLE_EQ(4.25, gr->getAverageMarks());
  delete gr;
  delete test;
}

TEST(gr_test, test6) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  Group* gr = test->getGroups()[1];
  EXPECT_EQ(-1, gr->getHead());
  delete gr;
  delete test;
}
TEST(d_test, test7) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  Group* gr = test->getGroups()[1];
  test->printGroups();
  EXPECT_EQ(5, gr->getHead());
  delete gr;
  delete test;
}
TEST(d_test, test8) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  test->fireStudents();
  Group* gr = test->getGroups()[1];
  EXPECT_EQ(2, gr->getGroupSize());
  delete gr;
  delete test;
}

TEST(d_test, test9) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  Group* gr = test->getGroups()[0];
  EXPECT_EQ(2, gr->getHead());
  delete gr;
  delete test;
}

TEST(d_test, test10) {
  Deanery* test = new Deanery("specList.txt", "students.txt");
  test->initHeads();
  test->fireStudents();
  Group* gr = test->getGroups()[0];
  EXPECT_EQ(4, gr->getGroupSize());
  delete gr;
  delete test;
}

