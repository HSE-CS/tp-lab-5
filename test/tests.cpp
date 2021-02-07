// Copyright 2021 Tatsenko Ilya
#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(DeanaryTest, test1) {
    Student student(1001, "Tatsenko Ilya");
    EXPECT_EQ("Tatsenko Ilya", student.get_fio());
}

TEST(DeanaryTest, test2) {
    Student student(1001, "akakks");
    EXPECT_EQ(1001, student.get_id());
}

TEST(DeanaryTest, test3) {
    Student st(1001, "Tatsenko Ilya");
    Group  grup("Economic", "Economic");
    st.add_to_group(&grup);
    EXPECT_EQ("Economic", st.get_group());
}

TEST(DeanaryTest, test4) {
    Student student(1333, "Tatsenko Ilya");
    student.add_mark(3);
    student.add_mark(5);
    student.add_mark(4);
    EXPECT_EQ(4.0, student.get_avarage_mark());
}

TEST(DeanaryTest, test5) {
    Student student1(1333, "Tatsenko Ilya");
    Student student3(1339, "Kravchenko Nikita");
    Student student9(1399, "Manachinsky Anton");
    Group friends("Sarov", "School");
    friends.add_student(&student1);
    friends.add_student(&student3);
    friends.add_student(&student9);

    EXPECT_EQ(&student1, friends.find_of_student("Tatsenko Ilya", 1333));
}

TEST(DeanaryTest, test6) {
    Student student1(1333, "Tatsenko Ilya");
    Student student3(1339, "Kravchenko Nikita");
    Student student9(1399, "Manachinsky Anton");
    Group friends("Sarov", "School");
    friends.add_student(&student1);
    friends.add_student(&student3);
    friends.add_student(&student9);
    friends.choose_header(&student9);
    EXPECT_EQ("Manachinsky Anton", friends.get_header());
}

TEST(DeanaryTest, test7) {
    Student student1(1333, "Tatsenko Ilya");
    Student student3(1339, "Kravchenko Nikita");
    Student student9(1399, "Manachinsky Anton");
    Group friends("Sarov", "School");
    friends.add_student(&student1);
    friends.add_student(&student3);
    friends.remove_student(&student3);
    EXPECT_EQ("Tatsenko Ilya", friends.get_students());
}

TEST(DeanaryTest, test8) {
    Student student1(1333, "Tatsenko Ilya");
    Student student3(1339, "Kravchenko Nikita");
    Student student9(1399, "Manachinsky Anton");
    Group friends("Sarov", "School");
    friends.add_student(&student1);
    friends.add_student(&student3);
    student1.add_mark(9);
    student1.add_mark(8);
    student1.add_mark(10);
    student3.add_mark(10);
    student3.add_mark(10);
    student3.add_mark(10);

    EXPECT_EQ(9.5, friends.calculate_of_avarage_mark());
}

TEST(DeanaryTest, test9) {
    Student student1(1333, "Tatsenko Ilya");
    Student student2(1334, "Tatsenko Michail");
    Group grup("HSSE", "PI");
    student1.add_to_group(&grup);
    grup.add_student(&student2);
    EXPECT_EQ("Tatsenko Ilya", grup.get_students());
}

TEST(DeanaryTest, test10) {
    Student student1(1333, "Tatsenko Ilya");
    Student student3(1933, "Kravchenko Nikita");

    student1.add_mark(3);
    student3.add_mark(5);

    Group* gr = new Group("Hse", "PI");
    gr->add_student(&student1);
    gr->add_student(&student3);
    EXPECT_EQ(4, gr->calculate_of_avarage_mark());
}
