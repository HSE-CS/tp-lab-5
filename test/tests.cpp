// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"

TEST(PostfixTest, test1) {
  Student student("1", "Pavlov pavel Pavlovich");
  EXPECT_EQ("1", student.getId);
}

TEST(PostfixTest, test2) {
  Student student("1", "Pavlov pavel Pavlovich");
  EXPECT_EQ(student.getFio, "Pavlov pavel Pavlovich");
}

TEST(PostfixTest, test3) {
  Student student("1", "Pavlov pavel Pavlovich");
  EXPECT_EQ(nullptr, student.getGroup);
}

TEST(PostfixTest, test4) {
  Student student("1", "Pavlov pavel Pavlovich");
  Group group1("19SE-1", "SE");
  student1.addToGroup(&group1);
  EXPECT_EQ("19SE-1", student.getGroup()->GetTitle());
}



