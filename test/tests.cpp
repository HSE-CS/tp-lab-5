// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Deanary.h"
#include "Group.h"

TEST(DeanaryTest, test1) {
  Deanary d;
  Student* s = d.hire_student(2312412, "John Doe", "TestGroup");

  EXPECT_EQ(false, s->is_head());
}

TEST(DeanaryTest, test2) {
  Deanary d;
  Student* s = d.hire_student(2312412, "John Doe", "TestGroup");
  d.add_marks_to_all(5);
  d.add_marks_to_all(2);

  EXPECT_DOUBLE_EQ(s->get_average_mark(), 3.5);
}

TEST(DeanaryTest, test3) {
  Deanary d;
  Student* s = d.hire_student(2312412, "John Doe", "TestGroup");

  d.init_heads();

  EXPECT_EQ(s->is_head(), true);
}

TEST(DeanaryTest, test4) {
  Deanary d;
  Group* g = d.create_group("TestGroup");

  EXPECT_EQ(g->is_empty(), true);
}

TEST(DeanaryTest, test5) {
  Deanary d;
  Group* g = d.create_group("TestGroup");
  d.hire_student(2312412, "John Doe", "TestGroup");

  EXPECT_EQ(g->contains_student(2312412), true);
}

TEST(DeanaryTest, test6) {
  Deanary d;
  Group* g = d.create_group("TestGroup");
  d.hire_student(2312412, "John Doe", "TestGroup");
  d.fire_student(2312412);

  EXPECT_EQ(g->contains_student(2312412), false);
}

TEST(DeanaryTest, test7) {
  Deanary d;
  Group* g2 = d.create_group("TestGroup2");
  d.hire_student(2312412, "John Doe", "TestGroup1");

  d.move_student(2312412, "TestGroup2");
  EXPECT_EQ(g2->contains_student(2312412), true);
}

TEST(DeanaryTest, test8) {
  Deanary d;
  Group* g = d.create_group("TestGroup");
  d.hire_student(2312412, "John Doe", "TestGroup");
  d.hire_student(3142132, "Jin Doe", "TestGroup");

  d.add_marks_to_all(4);
  d.add_marks_to_all(5);

  EXPECT_DOUBLE_EQ(g->get_average_mark(), 4.5);
}

TEST(DeanaryTest, test9) {
  Deanary d;
  d.hire_student(2312412, "John Doe", "TestGroup");
  d.hire_student(3142132, "Jinn Doe", "TestGroup");

  EXPECT_STREQ(d.get_statistics().c_str(), "Overall statistics:\n"
                                           "TestGroup (2 students)\n"
                                           "2312412\tJohn Doe\t0.000000\n"
                                           "3142132\tJinn Doe\t0.000000\n\n");
}

TEST(DeanaryTest, test10) {
  Deanary d;
  Group* g = d.create_group("TestGroup");
  d.hire_student(2312412, "John Doe", "TestGroup");

  EXPECT_EQ(g->is_empty(), false);
}
