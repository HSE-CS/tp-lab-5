////// Copyright 2021 Ozhiganova Polina
#include <gtest/gtest.h>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"
#include "reader/Reader.h"

TEST(TestStudent, check_empty_const) {
  Student student;
  int rez = 0;
  EXPECT_EQ(rez, student.getStId());
}

TEST(TestStudent, check_id_creation) {
  UniqueID *newId = new UniqueID;
  Student student("Mitchel Mia", newId);
  int rez = 1;
  EXPECT_EQ(rez, student.getStId());
}

TEST(TestStudent, check_st_name) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  std::string rez = "Mitchel Mia";
  EXPECT_EQ(rez, student1->getStNamed());
}

TEST(TestStudent, check_st_spec) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "PI";
  EXPECT_EQ(rez, student1->getStSpec());
}

TEST(TestStudent, check_st_av_mark) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  float rez = 0.0;
  EXPECT_EQ(rez, student1->getAverageMark());
}

TEST(TestStudent, finale_st) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  student1->~Student();
  EXPECT_EQ(0, student1->getStId());
}

TEST(TestGroup, check_gr_head) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  ASSERT_TRUE(student1->isHeadOfGroup());
}

TEST(TestGroup, check_gr_empty) {
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  Group *newGr = new Group("PI", "1st",
                           newStudents, nullptr);
  ASSERT_TRUE(newGr->isEmpty());
}


TEST(TestGroup, check_st_in_gr) {
  UniqueID *newId1 = new UniqueID;
  Student* student1 = new Student("Mitchel Mia", newId1);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  ASSERT_TRUE(newGr->containStudent(1));
}

TEST(TestGroup, check_gr_spec) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  EXPECT_EQ("PI", newGr->getSpec());
}

TEST(TestGroup, check_gr_title) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "1st";
  EXPECT_EQ(rez, newGr->getTitle());
}

TEST(TestGroup, check_sts_size_in_gr) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  int rez = 2;
  EXPECT_EQ(rez, newGr->getStudents().size());
}

TEST(TestGroup, check_get_st) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "Greich Mark";
  EXPECT_EQ(rez, newGr->getStudent(2)->getStNamed());
}

TEST(TestGroup, check_gr_not_empty) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  ASSERT_FALSE(newGr->isEmpty());
}

TEST(TestGroup, check_get_st_name) {
  UniqueID *newId1 = new UniqueID;
  Student *student1 = new Student("Mitchel Mia", newId1);
  UniqueID *newId2 = new UniqueID;
  Student * student2 = new Student("Greich Mark", newId2);
  Group *gr = nullptr;
  std::vector<Student *> newStudents;
  newStudents.push_back(student1);
  newStudents.push_back(student2);
  Student *newHead = student1;
  Group *newGr = new Group("PI", "1st",
                           newStudents, newHead);
  std::string rez = "Greich Mark";
  EXPECT_EQ(rez, newGr->getStudent(2)->getStNamed());
}

TEST(TestDeanary, check_empty_dean_size) {
  Deanary* d = new Deanary;
  int rez = 0;
  EXPECT_EQ(rez, d->getGrsSize());
}

TEST(TestDeanary, check_groups_creation) {
  Reader *r = new Reader;
  std::ifstream f("groups.json");
  nlohmann::json jf = nlohmann::json::parse(f);
  f.close();
  std::map<std::string, std::string> nameGrSp = r->parseGrSp(jf);
  std::vector<std::vector<std::string>> namesFI = r->parseFI(jf);
  Deanary *d = new Deanary;
  d->createGroups(nameGrSp, namesFI);
  int rez = 3;
  EXPECT_EQ(rez, d->getGrsSize());
}
