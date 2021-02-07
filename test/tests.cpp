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
  Student* s = new Student(100, name);
  g.addStudent(s);
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

TEST(TestGroup, testGAvg) {
  std::string title = "SE1";
  std::string spec = "Software Engineering";
  Group g(title, spec);
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  s.addMark(5);
  std::string name2 = "Pupkin Vasilii Fedorovich";
  Student s1(112, name2);
  s1.addMark(6);
  g.addStudent(&s);
  g.addStudent(&s1);
  ASSERT_NEAR(5.5, g.getAverageMark(), 0.0001);
}

TEST(TestDeanery, testMove) {
  std::string title = "SE1";
  std::string spec = "Software Engineering";
  Group g(title, spec);
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  std::string name2 = "Pupkin Vasilii Fedorovich";
  Student s1(112, name2);
  g.addStudent(&s);
  g.addStudent(&s1);

  std::string title2 = "SE2";
  std::string spec2 = "Software Engineering";
  Group g2(title2, spec2);

  std::vector<Group*> groups(2);
  groups[0] = &g;
  groups[1] = &g2;

  Deanery D(groups);
  D.moveStudent(&s, title, title2);
  D.moveStudent(&s1, title, title2);

  EXPECT_TRUE(g.isEmpty());
  EXPECT_EQ(2, g2.getNumberOfStudents());
}

TEST(TestDeanery, testMarks) {
  std::string title = "SE1";
  std::string spec = "Software Engineering";
  Group g(title, spec);
  std::string name = "Pupkin Egor Fedorovich";
  Student s(100, name);
  std::string name2 = "Pupkin Vasilii Fedorovich";
  Student s1(112, name2);
  g.addStudent(&s);
  g.addStudent(&s1);

  std::string title2 = "SE2";
  std::string spec2 = "Software Engineering";
  Group g2(title2, spec2);

  std::vector<Group*> groups(2);
  groups[0] = &g;
  groups[1] = &g2;

  Deanery D(groups);
  D.moveStudent(&s1, title, title2);
  D.addRandomMarks(7);
  EXPECT_TRUE(s.getAverageMark());
  EXPECT_TRUE(s1.getAverageMark());
  ASSERT_LT(s1.getAverageMark(), 10);
  ASSERT_GE(s.getAverageMark(), 0);
}
