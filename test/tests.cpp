// Copyright 2021 Shaidi

#include <gtest/gtest.h>
#include <string>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"

TEST(lab5, task1) {
  Student* st = new Student("Sharibzhanova Diana", 10);
  st->addMark(3);
  st->addMark(7);
  EXPECT_EQ(5.0, st->get_average_mark());
}

TEST(lab5, task2) {
  Student* st1 = new Student("Sharibzhanova Diana", 10);
  Student* st2 = new Student("Ivan Ivanov", 11);
  st1->addMark(7);
  st1->addMark(5);
  st2->addMark(4);
  st2->addMark(8);
  Group* gr = new Group("19PMI-3", "Prikladnaya Matematica");
  gr->addStudent(st1);
  gr->addStudent(st2);
  EXPECT_EQ(6.0, gr->average_group_mark());
}

TEST(lab5, task3) {
  Student* st1 = new Student("Sharibzhanova Diana", 10);
  Student* st2 = new Student("Ivan Ivanov", 11);
  Group* gr = new Group("19PMI-3", "Prikladnaya Matematica");
  gr->add_student(st1);
  gr->add_student(st2);
  gr->remove_student(st1);
  EXPECT_EQ(1, gr->get_students().size());
}

TEST(lab5, task4) {
  Student* st1 = new Student("Sharibzhanova Diana", 10);
  EXPECT_EQ(10, st1->get_id());
}

