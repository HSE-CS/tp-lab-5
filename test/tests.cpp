// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include <fstream>
#include <string>

#include "Deanery.h"
#include "Group.h"
#include "Student.h"

TEST(DeaneryTest, test1) {
  Deanery deanery{};
  EXPECT_EQ(3, deanery.group.size());
}

TEST(DeaneryTest, test2) {
  Deanery decan{};
  int st = 0;
  for (auto group : *decan.getGroups()) {
    st += group->getStudents()->size();
  }
  EXPECT_EQ(100, st);
}

TEST(DeaneryTest, test3) {
  int st = 0;
  Deanery decan{};
  int cnt = *decan.getGroups()->at(0)->getStudents()->size();
  if (cnt > 0) int ans = 1;
  EXPECT_EQ(1, ans);
}

TEST(DeaneryTest, test4) {
  Deanery decan{};
  auto *name = new std::string{"Титов Д.Д"};
  auto *title = new std::string{"19PMI-2"};
  decan.moveStudents(*name, *title);

  EXPECT_EQ(decan.groupByStudent("Титов Д.Д"), decan.getGroup("19PMI-2"));
}

TEST(DeaneryTest, test5) {
  Deanery decan{};
  int _id = 42;
  auto *title = new std::string{"19PMI-2"};
  decan.moveStudents(_id * title);

  EXPECT_EQ(decan.groupByStudent(_id), decan.getGroup("19PMI-2"));
}

TEST(DeaneryTest, test6) {
  Deanery decan{};
  int cnt = 0;
  std::vector<std::string> heads{"Булгаков А.П", "Яковлева У.", "Федорова М.В"};
  for (auto group : *decan.getGroups()) {
    EXPECT_EQ(heads[cnt++], group->getHead().getName());
  }
}

TEST(DeaneryTest, test7) {
  Deanery decan{};
  decan.saveStuff();
  ifstream f("./data/statistic.txt");

  EXPECT_EQ(1, f.good());
}

TEST(DeaneryTest, test8) {
  Deanery deanery{};
  deanery.addMarksToAll(3);
  double average = deanery.getGroups()->at(2)->getAverageMark();
  if (average > 0)
    int ans = 1;
  else
    int ans = 0;
  EXPECT_EQ(1, ans);
}

TEST(DeaneryTest, test9) {
  Deanery decan{};
  decan.addMarksToAll(3);
  double average = decan.getGroups()->at(1)->getHead().getAverageMark();
  EXPECT_NEAR(3.66667, average, 0.01);
}

TEST(DeaneryTest, test10) {
  Deanery decan{};
  decan.addMarksToAll(3);
  auto *name = new std::string{"Колесников Р.А"};
  auto *title = new std::string{"19FM-1"};
  decan.moveStudents(*name, *title);
  decan.moveStudents(56, *title);
  double average = decan.getGroups()->at(2)->getAverageMark();
  EXPECT_NEAR(5.18018, average, 0.0001);
}
