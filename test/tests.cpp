// Copyright Nikita Demashow 2021

#include <gtest/gtest.h>
#include <string>
#include"Student.h"
#include"Group.h"
#include"Deanary.h"

TEST(DeanaryTest, test1) {
  setlocale(LC_ALL, "Russian");
  unsigned int id = 666;
  std::string fio = "Bulgakov";
  Student student(fio, id);
  EXPECT_EQ("Bulgakov", student.getFio());
}
TEST(DeanaryTest, test2) {
  setlocale(LC_ALL, "Russian");
  unsigned int id = 666;
  std::string fio = "Bulgakov";
  Student student(fio, id);
  EXPECT_EQ(666, student.getId());
}
TEST(DeaneryTest, test3) {
  Group gr("CarskoeSelo", "literature");
  EXPECT_EQ(false, gr.isFull());
}
TEST(DeaneryTest, test4) {
  Group gr("CarskoeSelo", "literature");
  EXPECT_EQ(true, gr.isEmpty());
}
TEST(DeaneryTest, test5) {
  Deanary D;
  Group gr("CarskoeSelo", "literature");
  D.addGroup(&gr);
  EXPECT_EQ(1, D.getCntGroups());
}
TEST(DeaneryTest, test6) {
  Group gr("CarskoeSelo", "literature");
  EXPECT_EQ("CarskoeSelo", gr.getTitle());
}
TEST(DeaneryTest, test7) {
  Group gr("CarskoeSelo", "literature");
  EXPECT_EQ("literature", gr.getSpec());
}
TEST(DeaneryTest, test8) {
  Group gr("CarskoeSelo", "literature");
  EXPECT_EQ(NULL, gr.getStudentByFio("Пушкин"));
}
TEST(DeaneryTest, test9) {
  Group gr("CarskoeSelo", "literature");
  EXPECT_EQ(NULL, gr.getStudentById(10));
}
