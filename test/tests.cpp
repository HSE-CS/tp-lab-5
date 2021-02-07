// Copyright 2021 Kris


#include <gtest/gtest.h>
#include <string>
#include "../include/Student.h"
#include "../include/Group.h"
#include "../include/Deanary.h"

TEST(Student, test1) {
    Student st = Student(456, "Vasiya Pupkin");
    EXPECT_EQ(456, st.getId());
}

TEST(Student, test2) {
    Student st = Student(456, "Vasiya Pupkin");
    EXPECT_EQ("Vasiya Pupkin", st.getFio());
}

TEST(Student, test3) {
    Student st = Student(456, "Vasiya Pupkin");
    st.addmark(5);
    st.addmark(4);
    EXPECT_EQ(4.5, st.getAveragemark());
}

TEST(Deanary, test4) {
    Deanary d;
    d.AddGroup("19pmi-2", "imics");
    Group gr = d.getLastGroup();
    EXPECT_EQ("19pmi-2", gr.gettitle());
}

TEST(Deanary, test5) {
    Deanary deanary;
    deanary.AddGroup("19pmi-2", "imics");
    Group gr = deanary.getLastGroup();
    Student st = Student(345, "Vasiya Pupkin");
    gr.addStudent(&st);
    deanary.AddGroup("18pmi-2", "imics");
    gr = deanary.getLastGroup();
    st = Student(543, "Liza Kraeva");
    gr.addStudent(&st);
    deanary.fireStudents();
    gr = deanary.getLastGroup();
    EXPECT_EQ(1, gr.isEmpty());
}

TEST(Deanary, test6) {
    Deanary deanary;
    deanary.AddGroup("19pmi-2", "imics");
    Group gr = deanary.getLastGroup();
    Student st = Student(345, "Vasiya Pupkin");
    st.addmark(10);
    gr.addStudent(&st);
    deanary.AddGroup("18pmi-2", "imics");
    gr = deanary.getLastGroup();
    st = Student(543, "Liza Kraeva");
    st.addmark(10);
    gr.addStudent(&st);
    EXPECT_EQ(10, gr.getAveragemark());
}

TEST(Deanary, test7) {
    Deanary deanary;
    deanary.AddGroup("19pmi-2", "imics");
    Group gr = deanary.getLastGroup();
    Student st = Student(345, "Vasiya Pupkin");
    st.addmark(10);
    gr.addStudent(&st);
    deanary.AddGroup("18pmi-2", "imics");
    gr = deanary.getLastGroup();
    st = Student(543, "Liza Kraeva");
    st.addmark(10);
    st.addmark(8);
    gr.addStudent(&st);
    EXPECT_EQ(9, st.getAveragemark());
}

TEST(Deanary, test8) {
    Deanary deanary;
    deanary.AddGroup("19pmi-2", "imics");
    Group gr = deanary.getLastGroup();
    Student st = Student(345, "Vasiya Pupkin");
    gr.addStudent(&st);
    deanary.AddGroup("18pmi-2", "imics");
    gr = deanary.getLastGroup();
    st = Student(543, "Liza Kraeva");
    gr.addStudent(&st);
    EXPECT_EQ(0, gr.isEmpty());
}

TEST(Group, test9) {
    Deanary deanary;
    deanary.AddGroup("19pmi-2", "imics");
    Group gr = deanary.getLastGroup();
    Student st = Student(345, "Vasiya Pupkin");
    gr.addStudent(&st);
    st = Student(543, "Liza Kraeva");
    gr.addStudent(&st);
    Student* stud = gr.containsStudent("Liza Kraeva");
    Student st1 = *stud;
    EXPECT_EQ(543, st1.getId());
}

TEST(Deanary, test10) {
    Deanary deanary;
    deanary.AddGroup("19pmi-2", "imics");
    Group gr = deanary.getLastGroup();
    Student st = Student(345, "Vasiya Pupkin");
    gr.addStudent(&st);
    deanary.AddGroup("18pmi-2", "imics");
    gr = deanary.getLastGroup();
    st = Student(543, "Liza Kraeva");
    gr.addStudent(&st);
    deanary.fireStudents();
    deanary.addMarksToAll();
    gr = deanary.getLastGroup();
    EXPECT_EQ(1, gr.isEmpty());
}
