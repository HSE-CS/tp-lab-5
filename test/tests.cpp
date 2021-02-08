// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <string>
#include <fstream>

#include "Deanary.h"

TEST(test, test1) {
    Deanary d;
    d.createGroup("group-1.txt");
    d.save();
    std::fstream oldSave("../../Groups/group-1.txt");
    std::fstream newSave("../../Groups1/group-1.txt");
    int s1, s2;
    std::string c1, c2;
    oldSave >> s1;
    newSave >> s2;

    for (int i = 0; i < s1 + 1; i++) {
        std::getline(oldSave, c1);
        std::getline(newSave, c2);
    }
    EXPECT_EQ(c1, c2);
}

//TEST(test, test2) {
//
//}
//
//TEST(test, test3) {
//
//}
//
//TEST(test, test4) {
//
//}
//
//TEST(test, test5) {
//
//}
//
//TEST(test, test6) {
//
//}
//
//TEST(test, test7) {
//
//}
//
//TEST(test, test8) {
//
//}
//
//TEST(test, test9) {
//
//}
//
//TEST(test, test10) {
//
//}
