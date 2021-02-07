// Copyright 2020 GHA Test Team

#include "../include/Deanary.h"
#include <gtest/gtest.h>
#include <string>

TEST(DeanaryTest, test1) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  int count = 0;
  for (auto group : den.groups) {
    count++;
  }
  EXPECT_EQ(3, count);
}

TEST(DeanaryTest, test2) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  int count = 0;
  for (auto group : den.groups) {
    for (auto student : group->students)
      count++;
  }
  EXPECT_EQ(31, count);
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
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string fio = "Rainbow Dasha Pony";
  std::string title = "transformers";
  Student newbie (666, fio);

  for (auto group : den.groups)
    if (group->getTitle() == title)
      newbie.addToGroup(group);

  EXPECT_EQ(title, newbie.group_->getTitle());
}

TEST(DeanaryTest, test5) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string title = "transformers";
  std::string spec = "who knows";

  Group newgr(title, spec);

  EXPECT_EQ(true, newgr.isEmpty());
}

TEST(DeanaryTest, test6) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  std::string fio = "Rainbow Dasha Pony";
  Student newbie (666, fio);

  newgr.addStudents(&newbie);

  EXPECT_EQ(false, newgr.isEmpty());
}

TEST(DeanaryTest, test7) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string title = "transformers";
  std::string spec = "who knows";
  Group newgr(title, spec);

  std::string fio = "Rainbow Dasha Pony";
  Student newbie (666, fio);

  newgr.addStudents(&newbie);

  newbie.addMark(10);
  newbie.addMark(0);

  EXPECT_DOUBLE_EQ(5, newbie.getAverageMark());
}

TEST(DeanaryTest, test8) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string title = "transformers";
  std::string fio = "Rainbow Dasha Pony";
  Student newbie (666, fio);

  for (auto group : den.groups)
    if (group->getTitle() == title)
      newbie.addToGroup(group);


  EXPECT_EQ(false, newbie.isHeadOfGroup());
}

TEST(DeanaryTest, test9) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  std::string title = "transformers";
  std::string fio = "Rainbow Dasha Pony";
  int id = 666;
  Student newbie (id, fio);
  int count = 0;
  for (auto group : den.groups) {
    for (auto student : group->students)
      count++;
  }

  int new_count = 0;
  for (auto group : den.groups)
    if (group->getTitle() == title) {
      newbie.addToGroup(group);
      group->addStudents(&newbie);
    }
  for (auto group : den.groups) {
    for (auto student : group->students)
      new_count++;
  }

  EXPECT_EQ(new_count, count+1);
}

TEST(DeanaryTest, test10) {
  Deanary den;
  den.createGroups();
  den.hireStudents();
  den.initHeads();

  int id = 10;

  for (auto group : den.groups) {
    for (auto student : group->students)
      if (student->getID() == id)
        group->removeStudent(id);
  }

  bool find = false;
  for (auto group : den.groups) {
    for (auto student : group->students)
      if (student->getID() == id)
        find = true;
  }

  EXPECT_EQ(false, find);
}