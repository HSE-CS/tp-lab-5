// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>

#include <fstream>
#include <string>

#include "Deanery.h"
#include "Group.h"
#include "Student.h"

TEST(DeaneryTest, test1) {
  Deanery deanery{};
  EXPECT_EQ(3, deanery.getGroups()->size());
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
  int ans = 0;
  Deanery decan{};
  int cnt = decan->getGroups()->at(0)->getStudents()->size();
  if (cnt > 0) ans = 1;
  EXPECT_EQ(1, ans);
}

TEST(DeaneryTest, test4) {
  Deanery decan{};
  auto *name = new std::string{"Титов Д.Д"};
  auto *title = new std::string{"19PMI-2"};
  decan.moveStudent(*name, *title);

  EXPECT_EQ(decan.groupByStudent("Титов Д.Д").getTitle(), "19PMI-2");
}

TEST(DeaneryTest, test5) {
  Deanery decan{};
  int _id = 42;
  auto *title = new std::string{"19PMI-2"};
  decan.moveStudent(_id, * title);

  EXPECT_EQ(decan.groupByStudent(_id).getTitle(), "19PMI-2");
}

TEST(DeaneryTest, test6) {
  Deanery decan{};
  int cnt = 0;
  for (auto group : *decan.getGroups()) {
    EXPECT_NE(" ", group->getHead()->getName());
  }
}

TEST(DeaneryTest, test7) {
  Deanery decan{};
  decan.saveStuff();
  int ans = 0;
  // ifstream f("./data/statistic.txt");
  if (FILE *file = fopen("./data/statistic.txt", "r")) {
        fclose(file);
        ans = 1;
  }
  EXPECT_EQ(1, ans);
}

TEST(DeaneryTest, test8) {
  Deanery deanery{};
  deanery.addMarksToAll(3);
  double average = deanery.getGroups()->at(2)->getAveragemark();
  int ans = 0;
  if (average > 0)
    ans = 1;
  else
    ans = 0;
  EXPECT_EQ(1, ans);
}

TEST(DeaneryTest, test9) {
  Deanery decan{};
  decan.addMarksToAll(3);
  double average = decan.getGroups()->at(1)->getHead()->getAveragemark();
  EXPECT_NE(0, average);
}

TEST(DeaneryTest, test10) {
  Deanery decan{};
  decan.addMarksToAll(0);
  double average = decan.getGroups()->at(2)->getAveragemark();
  EXPECT_EQ(0, average);
}
