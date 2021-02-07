// Copyright 2021 Smirnov Grigory

#include <gtest/gtest.h>
#include <string>
#include "Deanery.h"

TEST(TestStudent, testId) {
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  EXPECT_EQ(s.getId(), 100);
}

TEST(TestStudent, testFio) {
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  EXPECT_EQ(s.getFio(), "Pupkin Egor Fedorovich");
}

TEST(TestStudent, testHead) {
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  EXPECT_FALSE(s.isHeadOfGroup());
}

TEST(TestStudent, testAverageMark1) {
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  s.addMark(111);
  s.addMark(10);
  ASSERT_NEAR(10.0, s.getAverageMark(), 0.0001);
}

TEST(TestStudent, testAverageMark2) {
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  s.addMark(7);
  s.addMark(5);
  s.addMark(2);
  s.addMark(9);
  ASSERT_NEAR(5.75, s.getAverageMark(), 0.0001);
}

TEST(TestGroup, testEmpty) {
  std::string title = "SE1";
  std::string spec = "Software Engineering";
  Group g(title, spec);
  EXPECT_TRUE(g.isEmpty());
}

TEST(TestGroup, testAdd) {
  std::string title = "SE1";
  std::string spec = "Software Engineering";
  Group g(title, spec);
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  g.addStudent(&s);
  EXPECT_EQ(g.getNumberOfStudents(), 1);
}

TEST(TestGroup, testGHead) {
  std::string title = "SE1";
  std::string spec = "Software Engineering";
  Group g(title, spec);
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  g.addStudent(&s);
  g.chooseHead();
  EXPECT_TRUE(s.isHeadOfGroup());
}

