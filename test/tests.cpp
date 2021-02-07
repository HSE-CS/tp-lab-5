// Copyright 2021 Sozinov Kirill

#include "Deanary.h"
#include "gtest/gtest.h"
#include <string>
#include <vector>

TEST(DeaneryTest, test1) {
    Deanery deanery{};
    EXPECT_EQ(3, deanery.getGroups()->size());
}

TEST(DeaneryTest, test1_1) {
    Deanery deanery{};
    int n = 0;
    for (auto &group : deanery.getGroups()) {
        n += group->getStudents()->size();
    }
    EXPECT_EQ(63, n);
}

TEST(DeaneryTest, test2) {
    Deanery deanery{};
    int st = 0;
    int n = 21;
    for (auto &group : deanery.getGroups()) {
        EXPECT_EQ(n, group->getStudents()->size());
    }
}

TEST(DeaneryTest, test3) {
    Deanery deanery{};
    auto *fio = new std::string{ "Michael Young" };
    auto *title = new std::string{ "20-ABC-1" };
    deanery.moveStudents(std::vector<Student *>
    {deanery.getGroup(0)->getStudent("Pedro Smith")},
        deanery.getGroup(1));
    int st = 0;
    int n[]{ 20, 22, 21 };
    for (auto &group : deanery.getGroups()) {
        EXPECT_EQ(n[st++], group->getStudents()->size());
    }
}

/*TEST(DeaneryTest, test4) {
    Deanery deanery{};
    auto *title = new std::string{ "19FM-1" };
    deanery.moveStudents(56, *title);
    int st = 0;
    int number_of_students[]{ 39, 25, 36 };
    for (auto group : *deanery.getGroups()) {
        EXPECT_EQ(number_of_students[st++], group->getStudents()->size());
    }
}

TEST(DeaneryTest, test5) {
    Deanery deanery{};
    auto *name2 = new std::string{ "�������� �." };
    deanery.fireStudents(*name2);
    int st = 0;
    int number_of_students[]{ 40, 24, 35 };
    for (auto group : *deanery.getGroups()) {
        EXPECT_EQ(number_of_students[st++], group->getStudents()->size());
    }
}

TEST(DeaneryTest, test6) {
    Deanery deanery{};
    auto *name3 = new std::string{ "�������� �.�" };
    deanery.fireStudents(99);
    EXPECT_EQ(*name3, deanery.getGroups()->at(1)->getHead().getName());
}

TEST(DeaneryTest, test7) {
    Deanery deanery{};
    int st = 0;
    std::vector<std::string> heads{ "�������� �.�", "�������� �.", "�������� �.�" };
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
    auto *name = new std::string{ "���������� �.�" };
    auto *title = new std::string{ "19FM-1" };
    deanery.moveStudents(*name, *title);
    deanery.moveStudents(56, *title);
    double average = deanery.getGroups()->at(2)->getAverageMark();
    EXPECT_NEAR(5.18018, average, 0.0001);
}*/
