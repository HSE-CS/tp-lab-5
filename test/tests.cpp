// Copyright 2020 Dumarevskaya
#include <gtest/gtest.h>
#include <string>

#include "Student.h"
#include "Deanary.h"
#include "Group.h"

TEST(Test, test1) {
  Student st("1", "Nikolaev Nikita Olegovich");
  Student st2("2", "Tarunova Tatiana Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  gr.chooseHead(&st);
  EXPECT_EQ(st.isHeadGroup(), true);
}

TEST(Test, test2) {
  Student st("1", "Nikolaev Nikita Olegovich");
  Student st2("2", "Tarunova Tatiana Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  gr.chooseHead(&st2);
  EXPECT_EQ(st.isHeadGroup(), false);
}

TEST(Test, test3) {
  Student st("1", "Nikolaev Nikita Olegovich");
  Student st2("2", "Tarunova Tatiana Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  st.addmark(4);
  st2.addmark(4);
  EXPECT_DOUBLE_EQ(gr.getAveragemark(), 4);
}

TEST(Test, test4) {
  Student st("1", "Nikolaev Nikita Olegovich");
  st.addmark(4);
  st.addmark(3);
  EXPECT_DOUBLE_EQ(st.getAveragemark(), 3.5);
}

TEST(Test, test5) {
  Student st("1", "Nikolaev Nikita Olegovich");
  Student st2("2", "Tarunova Tatiana Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  EXPECT_EQ(gr.containsStudent("1"), true);
}

TEST(Test, test6) {
  Student st("1", "Dubova Tamara Nikolaevna");
  Student st2("2", "Belyashova Kristina Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  EXPECT_EQ(gr.containsStudent("3"), false);
}

TEST(Test, test7) {
  Student st("1", "Dubova Tamara Nikolaevna");
  Student st2("2", "Belyashova Kristina Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  EXPECT_EQ(gr.isEmpty(), false);
}

TEST(Test, test8) {
  Group gr("19E", "Economy");
  EXPECT_EQ(gr.isEmpty(), true);
}

TEST(Test, test9) {
  Deanary de;
  Student st("1", "Dubova Tamara Nikolaevna");
  Student st2("2", "Belyashova Kristina Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  de.addGroup(&gr);
  EXPECT_EQ(de.getGroup("19E")->isEmpty(), false);
}

TEST(Test, test10) {
  Deanary de;
  Group gr("19E", "Economy");
  de.addGroup(&gr);
  EXPECT_EQ(de.getGroup("19E")->isEmpty(), true);
}

TEST(Test, test11) {
  Deanary de;
  Student st("1", "Dubova Tamara Nikolaevna");
  Student st2("2", "Belyashova Kristina Nikolaevna");
  Group gr("19E", "Economy");
  st.addToGroup(&gr);
  st2.addToGroup(&gr);
  de.addGroup(&gr);
  de.initHeads("19E", "Dubova Tamara Nikolaevna");
  EXPECT_EQ(de.getStudent("2", "19E")->isHeadGroup(), false);
}
