// Copyright 2021 Egor Trukhin

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "Deanary.h"

TEST(student_test, test1) {
  Student student(101, std::string("Egor Trukhin"));
  EXPECT_EQ(101, student.getId());
}

TEST(student_test, test2) {
  Student student(101, std::string("Egor Trukhin"));
  EXPECT_STREQ("Egor Trukhin", student.getName().c_str());
}

TEST(student_test, test3) {
  Student student(101, std::string("Egor Trukhin"));
  EXPECT_EQ(nullptr, student.getGroup());
}

TEST(student_test, test4) {
  Student student(101, std::string("Egor Trukhin"));
  student.addMark(5);
  EXPECT_DOUBLE_EQ(5.0, student.getMeanMark());
}

TEST(student_test, test5) {
  Student student(101, std::string("Egor Trukhin"));
  student.addMark(5);
  student.addMark(10);
  EXPECT_DOUBLE_EQ(7.5, student.getMeanMark());
}

TEST(student_test, test6) {
  Student student1(100, std::string("Egor Trukhin"));
  Student student2(101, std::string("Egor Trukhin"));
  EXPECT_EQ(false, student1 == student2);
}

TEST(student_test, test7) {
  Student student1(100, std::string("Egor Trukhin"));
  Student student2(student1);
  EXPECT_EQ(true, student1 == student2);
}

TEST(group_test, test1) {
  Group group(std::string("19PI-1"), std::string("PI"));
  EXPECT_EQ(0, group.getStudents().size());
}

TEST(group_test, test2) {
  Group group(std::string("19PI-1"), std::string("PI"));
  group.addStudent(Student(100, std::string("Egor Trukhin")));
  group.addStudent(Student(101, std::string("Ilya Bychkov")));
  EXPECT_EQ(2, group.getStudents().size());
}

TEST(group_test, test3) {
  Group group(std::string("19PI-1"), std::string("PI"));
  group.addStudent(Student(100, std::string("Egor Trukhin")));
  group.addStudent(Student(101, std::string("Ilya Bychkov")));
  group.removeStudent(101);
  EXPECT_EQ(1, group.getStudents().size());
}

TEST(group_test, test4) {
  Group group(std::string("19PI-1"), std::string("PI"));
  group.addStudent(Student(100, std::string("Egor Trukhin")));
  group.addStudent(Student(101, std::string("Ilya Bychkov")));
  group.removeStudent(std::string("Egor Trukhin"));
  EXPECT_EQ(1, group.getStudents().size());
}

TEST(group_test, test5) {
  Student student1(100, std::string("Egor Trukhin"));
  student1.addMark(6);
  student1.addMark(10);

  Student student2(200, std::string("Ilya Bychkov"));
  student2.addMark(8);
  student2.addMark(10);

  Group group(std::string("19PI-1"), std::string("PI"));
  group.addStudent(student1);
  group.addStudent(student2);

  EXPECT_DOUBLE_EQ(8.5, group.getMeanMark());
}

TEST(group_test, test6) {
  Student student1(100, std::string("Egor Trukhin"));
  student1.addMark(6);
  student1.addMark(10);

  Student student2(200, std::string("Ilya Bychkov"));
  student2.addMark(8);
  student2.addMark(10);

  Group group(std::string("19PI-1"), std::string("PI"));
  group.addStudent(student1);
  group.addStudent(student2);

  group.setHead();

  EXPECT_EQ(200, group.getHead()->getId());
}

TEST(deanary_test, test1) {
  std::vector<std::string> groups_info;
  groups_info.push_back(std::string("19PI-1 PI"));
  groups_info.push_back(std::string("19PI-2 PI"));
  groups_info.push_back(std::string("19PMI-1 PMI"));
  groups_info.push_back(std::string("19PMI-2 PMI"));

  Deanary deanary;
  deanary.createGroups(groups_info);

  EXPECT_EQ(4, deanary.getGroups().size());
}

TEST(deanary_test, test2) {
  std::vector<std::string> groups_info;
  groups_info.push_back(std::string("19PI-1 PI"));
  groups_info.push_back(std::string("19PI-2 PI"));
  groups_info.push_back(std::string("19PMI-1 PMI"));
  groups_info.push_back(std::string("19PMI-2 PMI"));

  std::vector<std::string> students_info;
  students_info.push_back(std::string("Egor Trukhin Sergeevich 19PI-1"));
  students_info.push_back(std::string("Ilya Bychkov Sergeevich 19PI-1"));
  students_info.push_back(std::string("ASda asdfasd SDEfxczdf  19PMI-1"));
  students_info.push_back(std::string("ASVzc cvaerse SDFVxzv 19PMI-2"));

  Deanary deanary;
  deanary.createGroups(groups_info);
  deanary.hireStudents(students_info);

  EXPECT_EQ(0, deanary.getGroup("19PI-2")->getStudents().size());
}

TEST(deanary_test, test3) {
  std::vector<std::string> groups_info;
  groups_info.push_back(std::string("19PI-1 PI"));
  groups_info.push_back(std::string("19PI-2 PI"));
  groups_info.push_back(std::string("19PMI-1 PMI"));
  groups_info.push_back(std::string("19PMI-2 PMI"));

  std::vector<std::string> students_info;
  students_info.push_back(std::string("Egor Trukhin Sergeevich 19PI-1"));
  students_info.push_back(std::string("Ilya Bychkov Sergeevich 19PI-1"));
  students_info.push_back(std::string("ASda asdfasd SDEfxczdf  19PMI-1"));
  students_info.push_back(std::string("ASVzc cvaerse SDFVxzv 19PMI-2"));

  Deanary deanary;
  deanary.createGroups(groups_info);
  deanary.hireStudents(students_info);

  EXPECT_EQ(2, deanary.getGroup("19PI-1")->getStudents().size());
}

TEST(deanary_test, test4) {
  std::vector<std::string> groups_info;
  groups_info.push_back(std::string("19PI-1 PI"));
  groups_info.push_back(std::string("19PI-2 PI"));
  groups_info.push_back(std::string("19PMI-1 PMI"));
  groups_info.push_back(std::string("19PMI-2 PMI"));

  std::vector<std::string> students_info;
  students_info.push_back(std::string("Egor Trukhin Sergeevich 19PI-1"));
  students_info.push_back(std::string("Ilya Bychkov Sergeevich 19PI-1"));
  students_info.push_back(std::string("ASda asdfasd SDEfxczdf  19PI-1"));
  students_info.push_back(std::string("ASVzc cvaerse SDFVxzv 19PI-1"));

  Deanary deanary;
  deanary.createGroups(groups_info);
  deanary.hireStudents(students_info);

  deanary.getGroup("19PI-1")->getStudents()[0]->addMark(7.5);
  deanary.getGroup("19PI-1")->getStudents()[1]->addMark(5.3);
  deanary.getGroup("19PI-1")->getStudents()[2]->addMark(3.5);
  deanary.getGroup("19PI-1")->getStudents()[3]->addMark(2.9);

  deanary.fireStudents(6.0);

  EXPECT_EQ(1, deanary.getGroup("19PI-1")->getStudents().size());
}

TEST(deanary_test, test5) {
  std::vector<std::string> groups_info;
  groups_info.push_back(std::string("19PI-1 PI"));
  groups_info.push_back(std::string("19PI-2 PI"));
  groups_info.push_back(std::string("19PMI-1 PMI"));
  groups_info.push_back(std::string("19PMI-2 PMI"));

  std::vector<std::string> students_info;
  students_info.push_back(std::string("Egor Trukhin Sergeevich 19PI-1"));
  students_info.push_back(std::string("Ilya Bychkov Sergeevich 19PI-1"));
  students_info.push_back(std::string("ASda asdfasd SDEfxczdf  19PI-1"));
  students_info.push_back(std::string("ASVzc cvaerse SDFVxzv 19PI-1"));

  Deanary deanary;
  deanary.createGroups(groups_info);
  deanary.hireStudents(students_info);

  deanary.getGroup("19PI-1")->getStudents()[0]->addMark(10);
  deanary.getGroup("19PI-1")->getStudents()[1]->addMark(8);
  deanary.getGroup("19PI-1")->getStudents()[2]->addMark(8);
  deanary.getGroup("19PI-1")->getStudents()[3]->addMark(6);

  deanary.fireStudents();

  EXPECT_EQ(3, deanary.getGroup("19PI-1")->getStudents().size());
}

TEST(deanary_test, test6) {
  std::vector<std::string> groups_info;
  groups_info.push_back(std::string("19PI-1 PI"));
  groups_info.push_back(std::string("19PI-2 PI"));
  groups_info.push_back(std::string("19PMI-1 PMI"));
  groups_info.push_back(std::string("19PMI-2 PMI"));

  std::vector<std::string> students_info;
  students_info.push_back(std::string("Egor Trukhin Sergeevich 19PI-1"));
  students_info.push_back(std::string("Ilya Bychkov Sergeevich 19PI-1"));
  students_info.push_back(std::string("ASda asdfasd SDEfxczdf  19PI-1"));
  students_info.push_back(std::string("ASVzc cvaerse SDFVxzv 19PI-1"));

  Deanary deanary;
  deanary.createGroups(groups_info);
  deanary.hireStudents(students_info);

  std::vector<Student*> move_list(deanary.getGroup("19PI-1")->getStudents());
  deanary.moveStudents(move_list, deanary.getGroup("19PI-2"));

  EXPECT_EQ(0, deanary.getGroup("19PI-1")->getStudents().size());
}

TEST(deanary_test, test7) {
  std::vector<std::string> groups_info;
  groups_info.push_back(std::string("19PI-1 PI"));
  groups_info.push_back(std::string("19PI-2 PI"));
  groups_info.push_back(std::string("19PMI-1 PMI"));
  groups_info.push_back(std::string("19PMI-2 PMI"));

  std::vector<std::string> students_info;
  students_info.push_back(std::string("Egor Trukhin Sergeevich 19PI-1"));
  students_info.push_back(std::string("Ilya Bychkov Sergeevich 19PI-1"));
  students_info.push_back(std::string("ASda asdfasd SDEfxczdf  19PI-1"));
  students_info.push_back(std::string("ASVzc cvaerse SDFVxzv 19PI-1"));

  Deanary deanary;
  deanary.createGroups(groups_info);
  deanary.hireStudents(students_info);

  std::vector<Student*> move_list(deanary.getGroup("19PI-1")->getStudents());
  deanary.moveStudents(move_list, deanary.getGroup("19PI-2"));

  EXPECT_EQ(4, deanary.getGroup("19PI-2")->getStudents().size());
}
