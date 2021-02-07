// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Deanary.h"


TEST(DeanaryTest, test1) {
  Student stud("Pernon", 100);
  unsigned expected = 0;
  unsigned result = stud.getId();
  EXPECT_EQ(expected, postf);
}

TEST(DeanaryTest, test2) {
  Student stud("Pernon", 100);
  std::string expected = "Person";
  std::string result = stud.getFio();
  EXPECT_EQ(expected, postf);
}

TEST(DeanaryTest, test3) {
  Student stud("Pernon", 100);
  stud.addMark(10);
  stud.addMark(0);
  double expected = 5.;
  double result = stud.getAveragemark();
  EXPECT_NEAR(expected, postf);
}

TEST(DeanaryTest, test4) {
  Group gr("PMI", "<3");
  bool expected = true;
  bool result = gr.isEmpty();
  EXPECT_EQ(expected, postf);
}

TEST(DeanaryTest, test5) {
  Group gr("PMI", "<3");
  gr.addStudent(Student * ("Person", 100));
  bool expected = false;
  bool result = gr.isEmpty();
  EXPECT_EQ(expected, postf);
}

TEST(DeanaryTest, test6) {
  Group gr("PMI", "<3");
  Student st("Person", 100);
  gr.addStudent(st);
  gr.chooseHead();
  Student* expected = *st;
  Student* result = gr.getHead();
  EXPECT_EQ(expected, postf);
}

TEST(DeanaryTest, test7) {
  Group gr("PMI", "<3");
  Student st1("Person", 100);
  Student st2("Another Person", 90);
  gr.addStudent(st1);
  gr.addStudent(st2);
  st1.addMark(10);
  st1.addMark(9);
  st2.addMark(0);
  st2.addMark(1);
  double expected = ((10 + 9) / 2. + (0 + 1) / 2.) / 2.;
  double result = gr.getAveragemark();
  EXPECT_NEAR(expected, postf);
}

TEST(DeanaryTest, test8) {
  Group gr("PMI", "<3");
  Student st1("Person", 100);
  gr.addStudent(st1);
  gr.removeStudent(*st1);
  bool expected = true;
  bool result = gr.isEmpty();
  EXPECT_EQ(expected, postf);
}

TEST(DeanaryTest, test9) {
  Deanary dean;
  Group gr("PMI", "<3");
  Student st("Person", 100);
  dean.createGroups(gr);
  gr.addStudent(st);
  dean.initHeads();
  Student* expected = *st;
  Student* result = gr.getHead();
  EXPECT_EQ(expected, postf);
}

TEST(DeanaryTest, test10) {
  Deanary dean;
  Group gr("PMI", "<3");
  Student st("Person", 100);
  dean.createGroups(gr);
  gr.addStudent(st);
  dean.fireStudents(st.id);
  bool expected = true;
  bool result = gr.isEmpty();
  EXPECT_EQ(expected, postf);
}