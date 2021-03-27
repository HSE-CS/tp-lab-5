// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>

TEST(StudentTest, test1) {
  Student test(1, "Ivan Ivan");
  EXPECT_EQ(1, test.get_id());
}

TEST(StudentTest, test2) {
  Student test(2, "Ivan Smirnov");
  EXPECT_EQ(2, test.get_id());
}

TEST(StudentTest, test3) {
  Student test(3, "Ivan Kuznecov");
  EXPECT_EQ("Ivan Kuznecov", test.get_fio());
}

TEST(StudentTest, test4) {
  Student a(1, "Anna Smirnova");
  a.add_mark(7);
  EXPECT_EQ(7.0, a.average_mark());
}

TEST(StudentTest, test5) {
  Student b(1, "Maria Svetlova");
  b.add_mark(7);
  b.add_mark(5);
  b.add_mark(6);
  EXPECT_EQ(6.0, b.average_mark());
}

TEST(StudentTest, test6) {
  Group c("Man", "Management");
  EXPECT_EQ("Management", c.get_spec());
}

TEST(StudentTest, test7) {
  Group d("Man", "Management");
  EXPECT_EQ("Man", d.get_title());
}

TEST(GroupTest, test8) {
  Group e("Man", "Management");
  Student ee(8, "Ivan Ivanov");
  e.add_student(&ee);
  EXPECT_EQ("Ivan Ivanov", e.findStudent(8).get_fio());
}

TEST(GroupTest, test9) {
  Group f("Man", "Management");
  Student ff(9, "Ivan Ivanov");
  f.add_student(&ff);
  EXPECT_EQ(9, f.findStudent("Ivan Ivanov").get_id());
}

TEST(GroupTest, test10) {
  Group g("SE", "Software Engineeringt");
  Student gg(10, "Alina Ivanova");
  g.add_student(&gg);
  EXPECT_EQ(10, g.findStudent("Alina Ivanova").get_id());
}


