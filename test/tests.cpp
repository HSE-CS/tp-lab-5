// Copyright 2021 Lab_5 TiNa

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(PostfixTest, test1) {
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  EXPECT_EQ(21, stud.getId());
}

TEST(PostfixTest, test2) {
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  EXPECT_EQ(fname, stud.getFio());
}

TEST(PostfixTest, test3) {
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  stud.addMark(6);
  EXPECT_EQ(6, stud.getAveragemark());
}

TEST(PostfixTest, test4) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  EXPECT_EQ(title, gr.getTitle());
}

TEST(PostfixTest, test5) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  EXPECT_EQ(spec, gr.getSpec());
}

TEST(PostfixTest, test6) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  stud.addMark(6);
  gr.addStudent(&stud);
  EXPECT_EQ(6, gr.getAveragemark_Gr());
}

TEST(PostfixTest, test7) {
  std::string title = "19pmi2";
  std::string spec = "PMI";
  Group gr(title, spec);
  std::string fname = "Shherbakov Aleksey";
  Student stud(21, fname);
  stud.addMark(6);
  stud.addToGroup(&gr);
  EXPECT_EQ(title, stud.getGroup()->getTitle());
}

TEST(PostfixTest, test8) {
  Deanery dec;
  dec.createGroups();
  std::string fname1 = "Shherbakov Aleksey";
  Student stud1(21, fname1);
  stud1.addMark(6);
  dec.groups[0]->addStudent(&stud1);
  std::string fname2 = "Osipova Anna";
  Student stud2(13, fname2);
  stud2.addMark(7);
  dec.groups[1]->addStudent(&stud2);
  dec.moveStudents(stud2.getId(), dec.groups[1]->getTitle(), dec.groups[0]->getTitle());
  EXPECT_EQ(6.5, dec.groups[0]->getAveragemark_Gr());
}

TEST(PostfixTest, test9) {
    Deanery dec;
    dec.createGroups();
    std::string fname1 = "Shherbakov Aleksey";
    Student stud1(21, fname1);
    stud1.addMark(6);
    std::string fname3 = "Klimov Daniil";
    Student stud3(17, fname3);
    stud3.addMark(5);
    dec.groups[0]->addStudent(&stud1);
    dec.groups[0]->addStudent(&stud3);
  EXPECT_EQ(5.5, dec.groups[0]->getAveragemark_Gr());
}

TEST(PostfixTest, test10) {
    Deanery dec;
    dec.createGroups();
    std::string fname1 = "Shherbakov Aleksey";
    Student stud1(21, fname1);
    stud1.addMark(6);
    std::string fname3 = "Klimov Daniil";
    Student stud3(17, fname3);
    stud3.addMark(5);
    dec.groups[0]->addStudent(&stud1);
    dec.groups[0]->addStudent(&stud3);
    std::string fname2 = "Osipova Anna";
    Student stud2(13, fname2);
    stud2.addMark(7);
    dec.groups[1]->addStudent(&stud2);
    dec.moveStudents(stud2.getId(), dec.groups[1]->getTitle(), dec.groups[0]->getTitle());
  EXPECT_EQ(6, dec.groups[0]->getAveragemark_Gr());
