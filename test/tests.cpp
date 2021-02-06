// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(deanary, test1) {
  Student newbie;
  EXPECT_DOUBLE_EQ(0, newbie.getAverageMark());
}

TEST(deanary, test2) {
  Group team_no_7("team_no_7", "shinobi");
  EXPECT_EQ(true, team_no_7.isEmpty());
}

TEST(deanary, test3) {
  Student st("203", "Sai");
  EXPECT_EQ(false, st.isHeadOfGroup());
}

TEST(deanary, test4) {
  Group team_no_7("team_no_7", "shinobi");
  Student newbie("1", "Kakashi Hataki");
  EXPECT_DOUBLE_EQ(0, team_no_7.getAverageMark());
}

TEST(deanary, test5) {
  Student st("203", "Sai");
  EXPECT_DOUBLE_EQ(0, st.getAverageMark());
}

TEST(deanary, test6) {
  Group gr;
  EXPECT_EQ(true, gr.isEmpty());
}

TEST(deanary, test7) {
  Group gr;
  EXPECT_DOUBLE_EQ(0, gr.getAverageMark());
}

TEST(deanary, test8) {
  Group gr("sport");
  EXPECT_EQ(true, gr.isEmpty());
}

TEST(deanary, test9) {
  Group gr("", "sport");
  EXPECT_DOUBLE_EQ(0, gr.getAverageMark());
}

TEST(deanary, test10) {
  Group gr("sport", "sport");
  EXPECT_EQ(true, gr.isEmpty());
}

TEST(deanary, test11) {
  Group gr("sport", "sport");
  EXPECT_DOUBLE_EQ(0, gr.getAverageMark());
}
