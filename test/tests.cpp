// Copyright 2021 Ryzhova

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"
#include "Student.h"

TEST(deanary_test, test1) {
  Student st(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ(1, st.get_id());
}

TEST(deanary_test, test2) {
  Student st(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ("Ivanov Ivan Ivanovich", st.get_fio());
}

TEST(deanary_test, test3) {
  Student st(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ(0, st.get_average_mark());
}

TEST(deanary_test, test4) {
  Student st(1, "Ivanov Ivan Ivanovich");
  st.add_mark(10);
  st.add_mark(2);
  EXPECT_EQ(6, st.get_average_mark());
}

TEST(deanary_test, test5) {
  Group g("test_title", "test_spec");
  EXPECT_EQ("test_title", g.get_title());
}

TEST(deanary_test, test6) {
  Group g("test_title", "test_spec");
  EXPECT_EQ("test_spec", g.get_spec());
}

TEST(deanary_test, test7) {
  Group g("test_title", "test_spec");
  EXPECT_EQ(true, g.is_empty());
}

TEST(deanary_test, test8) {
  Group g("test_title", "test_spec");
  Student st(1, "Ivanov Ivan Ivanovich");
  g.add_student(&st);
  g.choose_head();
  EXPECT_EQ(true, st.is_head_of_group());
}

TEST(deanary_test, test9) {
  Student st(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ(1, st.get_id());
}

TEST(deanary_test, test10) {
  Student st(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ(1, st.get_id());
}
