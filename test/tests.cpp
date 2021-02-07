// Copyright 2021 Lab_5 TiNa

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(PostfixTest, test1) {
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  EXPECT_EQ(21, stud.getId());
}

TEST(PostfixTest, test2) {
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  EXPECT_EQ(fname, stud.getFio());
}

TEST(PostfixTest, test3) {
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  stud.addMark(6);
  EXPECT_EQ(6, stud.getAveragemark());
}

TEST(PostfixTest, test4) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  EXPECT_EQ(title, gr.getTitle());
}

TEST(PostfixTest, test5) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  EXPECT_EQ(spec, gr.getSpec());
}

TEST(PostfixTest, test6) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  stud.addMark(6);
  gr.addStudent(&stud);
  EXPECT_EQ(6, gr.getAveragemark_Gr());
}

TEST(PostfixTest, test7) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  stud.addMark(6);
  stud.addToGroup(&gr);
  EXPECT_EQ(title, stud.getGroup()->getTitle());
}
