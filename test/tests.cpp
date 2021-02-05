// Copyright 2021 Drobot E.D.

#include <gtest/gtest.h>
#include "Deanary.h"
#include <string>

TEST(Student_Test, test1) {
  Student number1(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ(1, number1.get_id());
}

TEST(Student_Test, test2) {
  Student number1(54, "Ivan Ivan Ivan");
  EXPECT_EQ(54, number1.get_id());
}

TEST(Student_Test, test3) {
  Student number1(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ("Ivanov Ivan Ivanovich", number1.get_fio());
}

TEST(Student_Test, test4) {
  Student number1(1, "Ivanov Ivan Ivanovich");
  EXPECT_EQ(0.0, number1.average_mark());
}

TEST(Student_Test, test5) {
  Student number1(1, "Ivanov Ivan Ivanovich");
  number1.add_mark(9);
  number1.add_mark(9);
  number1.add_mark(9);
  EXPECT_EQ(9.0, number1.average_mark());
}

TEST(Group_Test, test6) {
  Group number1("EC", "Economy");
  EXPECT_EQ("Economy", number1.get_spec());
}

TEST(Group_Test, test7) {
  Group number1("EC", "Economy");
  EXPECT_EQ("EC", number1.get_title());
}

TEST(Group_Test, test8) {
  Group number1("EC", "Economy");
  EXPECT_EQ(0.0, number1.avarage_mark());
}

TEST(Deanary_Test, test9) {
  Student number1(1, "Ivanov Ivan Ivanovich");
  Student number2(2, "Makarov Denis Aleksandrovich");
  number1.add_mark(9);
  number1.add_mark(9);
  number1.add_mark(9);

  number2.add_mark(7);
  number2.add_mark(7);
  number2.add_mark(7);

  Group num1("Ec", "Economy");
  Deanary only;
  only.add_group(num1);
  only.add_student(&number1, "Economy");
  only.add_student(&number2, "Economy");
  EXPECT_EQ(9, only.get_statistic_students("Ivanov Ivan Ivanovich"));
}

TEST(Deanary_Test, test10) {
  Student number1(1, "Ivanov Ivan Ivanovich");
  Student number2(2, "Makarov Denis Aleksandrovich");
  number1.add_mark(9);
  number1.add_mark(9);
  number1.add_mark(9);

  number2.add_mark(7);
  number2.add_mark(7);
  number2.add_mark(7);

  Group num1("Ec", "Economy");
  Deanary only;
  only.add_group(num1);
  only.add_student(&number1, "Economy");
  only.add_student(&number2, "Economy");
  EXPECT_EQ(8, only.get_statistic_groups("Economy"));
}
