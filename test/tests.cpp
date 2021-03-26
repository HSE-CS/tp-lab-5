// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include <string>

#include "Deanery.h"
#include "Group.h"
#include "Student.h"

TEST(group1, test1) {
  const std::string fio = "NAME";
  const int id = 0;
  Student s(id, fio);
  ASSERT_EQ(s.getFio(), fio);
  ASSERT_EQ(s.getId(), id);
}
TEST(group1, test2) {
  const std::string fio = "NAME";
  const int id = 0;
  Student s(id, fio);
  ASSERT_EQ(s.getMarks().size(), 0);
  ASSERT_DOUBLE_EQ(s.averageMark(), 0.0);
}
TEST(group1, test3) {
  const std::string title = "TITLE";
  const std::string spec = "SPECIALITY";
  Group g(title, spec);
  ASSERT_EQ(g.getTitle(), title);
  ASSERT_EQ(g.getSpeciality(), spec);
}
TEST(group1, test4) {
  const std::string title = "TITLE";
  const std::string spec = "SPECIALITY";
  Group g(title, spec);
  ASSERT_DOUBLE_EQ(g.averageMark(), 0.0);
}
TEST(group1, test5) {
  Deanery d;
  const std::string title = "TITLE";
  const std::string spec = "SPECIALITY";
  Group g(title, spec);
  Student s(0, "");
  d.addGroup(g);
  Deanery::addStudentToGroup(&g, s);
  Deanery::addMarkToStudent(&s, 10);
  ASSERT_DOUBLE_EQ(g.averageMark(), 10.0);
  ASSERT_DOUBLE_EQ(s.averageMark(), 10.0);
  Deanery::addMarkToStudent(&s, 0);
  ASSERT_DOUBLE_EQ(g.averageMark(), 5.0);
  ASSERT_DOUBLE_EQ(s.averageMark(), 5.0);
}
TEST(group1, test6) {
  Deanery d;
  Student s1(0, "");
  Student s2(1, "");
  Student s3(2, "");
  Group g("", "");
  Student s4(3, "");
  d.addGroup(g);
  Deanery::addStudentToGroup(&g, s1);
  Deanery::addStudentToGroup(&g, s2);
  Deanery::addStudentToGroup(&g, s3);
  Deanery::addStudentToGroup(&g, s4);
  Deanery::addMarkToStudent(&s1, 10);
  Deanery::addMarkToStudent(&s2, 0);
  Deanery::addMarkToStudent(&s3, 4);
  Deanery::addMarkToStudent(&s4, 8);
  Deanery::addMarkToStudent(&s4, 3);
  d.removeFailingStudents();
  ASSERT_DOUBLE_EQ(g.averageMark(), (10. + 0. + 4. + 8. + 3.) / 5.);
  ASSERT_DOUBLE_EQ(g.averageMark(), (10. + 4. + 8. + 3.) / 4.);
}
TEST(group1, test7) {
  Deanery d;
  Group g1("g1", "");
  Group g2("g2", "");
  Student s(0, "");
  Deanery::addMarkToStudent(&s, 10);
  d.addGroup(g1);
  d.addGroup(g2);
  Deanery::addStudentToGroup(&g1, s);
  ASSERT_DOUBLE_EQ(g1.averageMark(), 10.);
  ASSERT_DOUBLE_EQ(g2.averageMark(), 0.);
  d.moveStudent(0, "g1", "g2");
  ASSERT_DOUBLE_EQ(g1.averageMark(), 0.);
  ASSERT_DOUBLE_EQ(g2.averageMark(), 10.);
}
TEST(group1, test8) {
  Deanery d;
  Group g("", "");
  Student s(0, "NAME");
  d.addGroup(g);
  Deanery::addStudentToGroup(&g, s);
  auto x = g.getStudentByFio(s.getFio());
  ASSERT_EQ(&x.front(), &s);
}
TEST(group1, test9) {
  Deanery d;
  Group g("", "");
  Student s(0, "NAME");
  d.addGroup(g);
  ASSERT_EQ(g.getHead(), nullptr);
  Deanery::addStudentToGroup(&g, s);
  d.reelectHeads();
  ASSERT_EQ(g.getHead(), &s);
}
TEST(group1, test10) {
  Deanery d;
  Group g1("", "");
  Group g2("", "");
  Group g3("", "");
  Group g4("", "");
  d.addGroup(g1);
  d.addGroup(g2);
  d.addGroup(g3);
  d.addGroup(g4);
  ASSERT_EQ(d.getGroups().size(), 4);
}
