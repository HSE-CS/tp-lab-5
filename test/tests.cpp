// Copyright 2020 GHA Test Team

#include <Deanery.h>
#include <gtest/gtest.h>
#include <string>

TEST(DeaneryTest, test1) {
Deanery deanery{};
int st = 0;
for (auto group : *deanery.getGroups()) {
st += group->getStudents()->size();
}
EXPECT_EQ(100, st);
}

TEST(DeaneryTest, test2) {
Deanery deanery{};
int st = 0;
int number_of_students[]{40, 25, 35};
for (auto group : *deanery.getGroups()) {
EXPECT_EQ(number_of_students[st++], group->getStudents()->size());
}
}

TEST(DeaneryTest, test3) {
Deanery deanery{};
auto *name = new std::string{"Колесников Р.А"};
auto *title = new std::string{"19FM-1"};
deanery.moveStudents(*name, *title);
int st = 0;
int number_of_students[]{40, 24, 36};
for (auto group : *deanery.getGroups()) {
EXPECT_EQ(number_of_students[st++], group->getStudents()->size());
}
}

TEST(DeaneryTest, test4) {
Deanery deanery{};
auto *title = new std::string{"19FM-1"};
deanery.moveStudents(56, *title);
int st = 0;
int number_of_students[]{39, 25, 36};
for (auto group : *deanery.getGroups()) {
EXPECT_EQ(number_of_students[st++], group->getStudents()->size());
}
}

TEST(DeaneryTest, test5) {
Deanery deanery{};
auto *name2 = new std::string{"Яковлева У."};
deanery.fireStudents(*name2);
int st = 0;
int number_of_students[]{40, 24, 35};
for (auto group : *deanery.getGroups()) {
EXPECT_EQ(number_of_students[st++], group->getStudents()->size());
}
}

TEST(DeaneryTest, test6) {
Deanery deanery{};
auto *name3 = new std::string{"Смирнова Е.М"};
deanery.fireStudents(99);
EXPECT_EQ(*name3, deanery.getGroups()->at(1)->getHead().getName());
}

TEST(DeaneryTest, test7) {
Deanery deanery{};
int st = 0;
std::vector<std::string> heads{"Булгаков А.П", "Яковлева У.", "Федорова М.В"};
for (auto group : *deanery.getGroups()) {
EXPECT_EQ(heads[st++], group->getHead().getName());
}
}

TEST(DeaneryTest, test8) {
Deanery deanery{};
deanery.addMarksToAll(3);
double average = deanery.getGroups()->at(2)->getAverageMark();
EXPECT_NEAR(5.26667, average, 0.01);
}

TEST(DeaneryTest, test9) {
Deanery deanery{};
deanery.addMarksToAll(3);
double average = deanery.getGroups()->at(1)->getHead().getAverageMark();
EXPECT_NEAR(3.66667, average, 0.01);
}

TEST(DeaneryTest, test10) {
Deanery deanery{};
deanery.addMarksToAll(3);
auto *name = new std::string{"Колесников Р.А"};
auto *title = new std::string{"19FM-1"};
deanery.moveStudents(*name, *title);
deanery.moveStudents(56, *title);
double average = deanery.getGroups()->at(2)->getAverageMark();
EXPECT_NEAR(5.18018, average, 0.0001);
}
