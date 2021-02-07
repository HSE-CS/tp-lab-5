// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"

TEST(DeanaryTest, test1) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.hireStudent("Александров Александр Александрович", 1);
  EXPECT_EQ(1, SE.getGroup(1)->getStudentByIndex(0)->getId());
}
TEST(DeanaryTest, test2) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.hireStudent("Александров Александр Александрович", 1);
  EXPECT_EQ(false, SE.getGroup(1)->isHeadChoosen());
}
TEST(DeanaryTest, test3) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.hireStudent("Александров Александр Александрович", 1);
  SE.initHeads();
  EXPECT_EQ(true, SE.getGroup(1)->isHeadChoosen());
}
TEST(DeanaryTest, test4) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.createGroup("19SE2");
  SE.hireStudent("Александров Александр Александрович", 1);
  SE.hireStudent("Александро Александ Александрови", 2);
  EXPECT_EQ(2, SE.getGroup(2)->getStudentByIndex(0)->getId());
}
TEST(DeanaryTest, test5) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.hireStudent("Александров Александр Александрович", 1);
  SE.hireStudent("Александро Александ Александрови", 1);
  SE.hireStudent("Александр Алексан Александров", 1);
  SE.fireStudent(2);
  EXPECT_EQ(3, SE.getGroup(1)->getStudentByIndex(1)->getId());
}
TEST(DeanaryTest, test6) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.hireStudent("Александров Александр Александрович", 1);
  SE.getGroup(1)->getStudentByIndex(0)->addMark(6);
  EXPECT_EQ(6, SE.getGroup(1)->getStudentByIndex(0)->getAverage());
}
TEST(DeanaryTest, test7) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.hireStudent("Александров Александр Александрович", 1);
  SE.getGroup(1)->getStudentByIndex(0)->addMark(6);
  SE.hireStudent("Александр Алексан Александров", 1);
  SE.getGroup(1)->getStudentByIndex(1)->addMark(6);
  EXPECT_EQ(6, SE.getAverage());
}
TEST(DeanaryTest, test8) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.createGroup("19SE2");
  SE.hireStudent("Александров Александр Александрович", 1);
  SE.hireStudent("Алекандров Аксандр Алексанвич", 1);
  SE.hireStudent("Алекров Асандр Алсавич", 2);
  SE.moveStudent(SE.getGroup(1)->getStudentByIndex(0), SE.getGroup(1), SE.getGroup(2));
  EXPECT_EQ(1, SE.getGroup(2)->getStudentByIndex(1)->getId());
}
TEST(DeanaryTest, test9) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.createGroup("19SE2");
  SE.hireStudent("Александров Александр Александрович", 1);
  SE.hireStudent("Алекандров Аксандр Алексанвич", 1);
  SE.hireStudent("Алекров Асандр Алсавич", 2);
  SE.moveStudent(SE.getGroup(2)->getStudentByIndex(0), SE.getGroup(2), SE.getGroup(1));
  EXPECT_EQ(true, SE.getGroup(2)->isEmpty());
}
TEST(DeanaryTest, test10) {
  Deanary SE ("Software Engineering");
  SE.createGroup("19SE1");
  SE.hireStudent("Александров Александр Александрович", 1);
  EXPECT_EQ("Александров Александр Александрович", SE.getGroup(1)->getStudentByIndex(0)->getName());
}

