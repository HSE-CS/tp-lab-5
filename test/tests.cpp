// Copyright 2020 Uskova
#include "gtest/gtest.h"
#include "Deanary.h"
#include "Group.h"
#include "Student.h"


TEST(GroupTest, test1) {
  Group group;
  EXPECT_EQ(true, group.isEmpty());
}

TEST(DeanaryTest, test2) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  EXPECT_EQ(18, deanary->return_gr_num());
}

TEST(DeanaryTest, test3) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  std::string str = "Jeffrey James";
  EXPECT_EQ(str, deanary->findFio("Jeffrey James")->getFio());
}

TEST(DeanaryTest, test4) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  int id = 150;
  EXPECT_EQ(id, deanary->findId(150)->getId());
}

TEST(DeanaryTest, test5) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  EXPECT_EQ("Management", deanary->findGr("1", "Management")->getSpec());
}

TEST(DeanaryTest, test6) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  EXPECT_EQ(true, deanary->findGrS(deanary->findId(81))->
      containsStudent(deanary->findId(81)));
}

TEST(DeanaryTest, test7) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  deanary->moveStudents(deanary->findId(81), deanary->findGr("1", "Economics"));
  EXPECT_EQ(false,
            deanary->findGr("1", "Management")->
      containsStudent(deanary->findId(81)));
}

TEST(DeanaryTest, test8) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  deanary->moveStudents(deanary->findId(81), deanary->findGr("1", "Economics"));
  EXPECT_EQ(true,
            deanary->findGr("1", "Economics")->
      containsStudent(deanary->findId(81)));
}

TEST(GroupTest, test9) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  EXPECT_EQ("1", deanary->findGr("1", "Management")->getTitle());
}

TEST(GroupTest, test10) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  deanary->initHeads();
  EXPECT_EQ(true,
            deanary->findGr("1", "Management")->
      containsStudent(deanary->findGr("1", "Management")->getHead()));
}

TEST(GroupTest, test11) {
  Deanary* deanary = new Deanary;
  std::vector<Student*> sts = deanary->hireStudents("students.txt");
  deanary->createGroups("spec.txt", sts);
  deanary->addMarks(6);
  deanary->initHeads();
  EXPECT_EQ(true, deanary->saveChangesInFile("data.txt"));
}
