// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(StudentTest, Test1) {
  Student st (1122, "Ivan Ivanov");
  EXPECT_EQ(1122, st.getID());
}

TEST(StudentTest, Test2) {
  Student st (1122, "Ivan Ivanov");
  EXPECT_EQ("Ivan Ivanov", st.getFio());
}

TEST(StudentTest, Test3) {
  Student st (1122, "Ivan Ivanov");
  EXPECT_EQ(0, st.getMarks().size());
}

TEST(GroupTest, Test4) {
  Group gp ("TestGroup", "PI");
  EXPECT_EQ(0, gp.getStudentsNum());
}

TEST(GroupTest, Test5) {
  Group gp ("TestGroup", "PI");
  EXPECT_EQ("PI", gp.getSpec());
}


TEST(DeanaryTest, Test6) {
  Deanary dn;
  dn.hireStudents("studentsData.txt");
  EXPECT_EQ(30, dn.getStudentsNum());
}

TEST(DeanaryTest, Test7) {
  Deanary dn;
  dn.hireStudents("studentsData.txt");
  dn.createGroups("groupsData.txt");
  EXPECT_EQ(3, dn.getGroupsNum());
}

TEST(DeanaryTest, Test8) {
  Deanary dn;
  dn.hireStudents("studentsData.txt");
  dn.createGroups("groupsData.txt");
  dn.addMarksToAll();
  float av_m = dn.getGroup(0).getAverageMark();
  EXPECT_TRUE(av_m >= 0 && av_m <= 5);
}

TEST(DeanaryTest, Test9) {
  Deanary dn;
  dn.hireStudents("studentsData.txt");
  dn.createGroups("groupsData.txt");
  dn.addMarksToAll();
  EXPECT_EQ("Group1", dn.getGroup(0).getTitle());
}

TEST(DeanaryTest, Test10) {
  Deanary dn;
  dn.hireStudents("studentsData.txt");
  dn.createGroups("groupsData.txt");
  dn.addMarksToAll();
  Student st_test = dn.getGroup(0).getHead();
  EXPECT_TRUE(st_test.isHeadOfGroup());
}


