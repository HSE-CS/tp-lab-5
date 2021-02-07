// Copyright 2021 Lab_5 TiNa

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include <string>

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
