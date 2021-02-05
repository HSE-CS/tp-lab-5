// Copyright 2021 Andrey Bakurskii

#include <gtest/gtest.h>
#include <string>
#include "./Student.h"
#include "./Group.h"
#include "./Deanary.h"

TEST(StudentTest, Test1) {
  Student student(1, "Mashova Masha Artemovna");
  EXPECT_EQ(1, student.getId());
}

TEST(StudentTest, Test2) {
  Student student(1, "Mashova Masha Artemovna");
  EXPECT_EQ("Mashova Masha Artemovna", student.getFIO());
}

TEST(StudentTest, Test3) {
  Student student(1, "Mashova Masha Artemovna");
  EXPECT_EQ(0, student.getAveragemark());
}

TEST(GroupTest, Test4) {
  Group group("Group1", "HSE_PI_1");
  EXPECT_EQ("HSE_PI_1", group.getSpec());
}

TEST(GroupTest, Test5) {
  Group group("Group1", "HSE_PI_1");
  EXPECT_EQ("Group1", group.getTittle());
}
