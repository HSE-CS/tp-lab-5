// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"

TEST(PostfixTest, test1) {
  Student student("1", "Pavlov pavel Pavlovich");
  std::string id = student.getId();
  EXPECT_EQ("1", id);
}

TEST(PostfixTest, test2) {
  Student student("1", "Pavlov pavel Pavlovich");
  std::string fio = student.getFio();
  EXPECT_EQ("Pavlov pavel Pavlovich", fio);
}

TEST(PostfixTest, test3) {
  Student student("1", "Pavlov pavel Pavlovich");
  EXPECT_EQ("", student.getGroup()->GetTitle());
}

TEST(PostfixTest, test4) {
  Student student("1", "Pavlov pavel Pavlovich");
  Group group1("19SE-1", "SE");
  student.addToGroup(&group1);
  EXPECT_EQ("19SE-1", student.getGroup()->GetTitle());
}



