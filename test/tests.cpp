// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include "../include/Deanary.h"

TEST(DeanaryTest, test1) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string title = "transformers";
  std::string spec = "who knows";

  Group newgr(title, spec);

  EXPECT_EQ(0, newgr.students.size());
}

TEST(DeanaryTest, test2) {
  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  std::string fio = "Rainbow Dasha Pony";
  Student newbie(666, fio);

  newgr.addStudents(&newbie);

  EXPECT_EQ(1, newgr.students.size());
}

TEST(DeanaryTest, test3) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string title = "pony";
  int id = 25;
  den.moveStudents(id, title);

  for (auto group : den.groups) {
    for (auto student : group->students)
      if (student->getID() == id)
        EXPECT_EQ(title, group->getTitle());
  }
}

TEST(DeanaryTest, test4) {
  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  std::string fio = "Rainbow Dasha Pony";
  Student newbie(666, fio);

  newgr.addStudents(&newbie);

  EXPECT_EQ(title, newgr.getTitle());
}

TEST(DeanaryTest, test5) {
  std::string title = "transformers";
  std::string spec = "who knows";

  Group newgr(title, spec);

  EXPECT_EQ(true, newgr.isEmpty());
}

TEST(DeanaryTest, test6) {
  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  std::string fio = "Rainbow Dasha Pony";
  Student newbie(666, fio);

  newgr.addStudents(&newbie);

  EXPECT_EQ(false, newgr.isEmpty());
}

TEST(DeanaryTest, test7) {
  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  std::string fio = "Rainbow Dasha Pony";
  Student newbie(666, fio);

  newgr.addStudents(&newbie);

  newbie.addMark(10);
  newbie.addMark(0);

  EXPECT_DOUBLE_EQ(5, newbie.getAverageMark());
}

TEST(DeanaryTest, test8) {
  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  EXPECT_EQ("who knows", newgr.getSpec());
}

TEST(DeanaryTest, test9) {
  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);
  int count = newgr.students.size();

  std::string fio = "Rainbow Dasha Pony";
  Student newbie(666, fio);
  newgr.addStudents(&newbie);
  int new_count = newgr.students.size();

  EXPECT_EQ(new_count, count+1);
}

TEST(DeanaryTest, test10) {
  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  std::string fio1 = "Rainbow Dasha Pony";
  std::string fio2 = "Rainbow Dasha Pony2";
  Student newbie(666, fio1);
  Student newbie2(777, fio2);

  newgr.addStudents(&newbie);
  newgr.addStudents(&newbie2);

  newgr.removeStudent(777);
  bool find = false;
  for (auto students : newgr.students)
    if (students->getID() == 777)
      find = true;

  EXPECT_EQ(false, find);
}
