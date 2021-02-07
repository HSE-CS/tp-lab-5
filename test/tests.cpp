// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Deanary.h"

TEST(StudentTest, test1) {
  Deanary test;
  test.createGroups();
}

TEST(StudentTest, test2) {
  Student stud(0, "Boryaev Sergey Sergeevich");
}

TEST(StudentTest, test3) {
  Group gr("PI-1", "Prog");
  EXPECT_EQ(gr.isEmpty(), true);
}
