// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include "../include/Student.h"
#include "../include/Deanary.h"

TEST(Student, getterWithInstant) {
  Student student(1, "Пыня Вова Вович");
  EXPECT_EQ(1, student.getId());
}

TEST(Student, getterWithNew) {
  auto *student = new Student(1, "Пыня Вова Вович");
  EXPECT_EQ(1, student->getId());
  EXPECT_EQ("Пыня Вова Вович", student->getFullname());
}

TEST(Student, GroupAndHeadOfGroupIsNull) {
  auto *student = new Student(1, "Пыня Вова Вович");
  EXPECT_TRUE(student->getGroup() == nullptr);
  EXPECT_FALSE(student->isHeadOfGroup());
}

TEST(Student, AverageMarkNew) {
  auto *student = new Student(1, "Пыня Вова Вович");
  EXPECT_EQ(0, student->getAverageMark());
}

TEST(Student, RealAverageMark) {
  auto *student = new Student(1, "Пыня Вова Вович");
  student->addMark(3);
  student->addMark(3);
  student->addMark(3);
  student->addMark(3);
  student->addMark(3);
  EXPECT_EQ(3, student->getAverageMark());
}

TEST(Student, Destructor) {
  auto *student = new Student(1, "Пыня Вова Вович");
  student->~Student();
  EXPECT_EQ(0, student->getId());
  EXPECT_TRUE(student->getMarks().empty());
  EXPECT_TRUE(student->getGroup() == nullptr);
  EXPECT_TRUE(student->getFullname().empty());
}

TEST(Group, TitleAndSize) {
  auto *student1 = new Student(1, "Пыня Вова Вович");
  EXPECT_EQ(1, student1->getId());
  Group group("Озеро");
  EXPECT_EQ(group.getTitle(), "Озеро");
  group.addStudent(student1);
  EXPECT_EQ(group.getStudents().size(), 1);
}

TEST(Group, AverageGroupMark) {
  auto *student = new Student(1, "Пыня Вова Вович");
  Group group("Озеро");
  group.addStudent(student);
  EXPECT_EQ(group.getStudents().size(), 1);
  student->addMark(3);
  student->addMark(3);
  student->addMark(3);
  student->addMark(3);
  student->addMark(3);
  EXPECT_EQ(3, student->getAverageMark());

  auto *student2 = new Student(2, "Медвед Димуха Толич");
  group.addStudent(student2);
  EXPECT_EQ(group.getStudents().size(), 2);
  student2->addMark(4);
  student2->addMark(4);
  student2->addMark(4);
  student2->addMark(4);
  student2->addMark(4);
  EXPECT_EQ(4, student2->getAverageMark());

  EXPECT_EQ(3.5, group.getAverageMark());
}

TEST(Group, RussianElections) {
  auto *student = new Student(1, "Пыня Вова Вович");
  auto group = new Group("Озеро");
  group->addStudent(student);
  group->chooseHead(student);
  EXPECT_EQ(group->getHead(), student);
}

TEST(Group, ReElectionsAndGroupSize) {
  auto *student = new Student(1, "Пыня Вова Вович");
  Group group("Озеро");
  group.addStudent(student);
  group.chooseHead(student);
  group.removeStudent(student);
  EXPECT_EQ(group.getStudents().size(), 0);
  group.addStudent(student);
  EXPECT_NE(group.getHead(), student);
  EXPECT_EQ(group.getStudents().size(), 1);
  group.chooseHead(student);
  EXPECT_EQ(group.getHead(), student);
}

TEST(Group, ContainsPresident) {
  auto *student = new Student(1, "Пыня Вова Вович");
  auto *student2 = new Student(2, "Медвед Димуха Толич");
  Group group("Озеро");
  group.addStudent(student);
  group.addStudent(student2);
  EXPECT_EQ(group.getStudents().size(), 2);
  EXPECT_EQ(group.containsStudent(1), student);
  EXPECT_EQ(group.containsStudent("Медвед Димуха Толич"), student2);
  EXPECT_NE(group.containsStudent("Медвед Димуха Толич"), student);
  EXPECT_ANY_THROW(group.containsStudent(3));
}

TEST(Group, GetTitleAndSpec) {
  Group group("Озеро");
  EXPECT_EQ(group.getTitle(), "Озеро");
  EXPECT_EQ(group.getSpec(), "");
  Group group1("Озеро3", "Коррупция");
  EXPECT_NE(group1.getTitle(), "Озеро2");
  EXPECT_EQ(group1.getSpec(), "Коррупция");
}

TEST(Overall, VeryStrongTest) {
  // Constructors
  Group group("Озеро", "Коррупция");
  auto *group2 = new Group("ФБК", "Антикоррупция");
  EXPECT_EQ(group.getAverageMark(), 0);
  EXPECT_EQ(group2->getAverageMark(), 0);
  Student student(1, "Пыня Вова Вович");
  auto *student2 = new Student(2, "Медвед Димуха Толич");
  Student student3(3, "Новольный Леха");
  auto *student4 = new Student(4, "Соболь Люба");
  EXPECT_EQ(student.getId(), 1);
  EXPECT_EQ(student2->getAverageMark(), 0);
  EXPECT_TRUE(student3.getGroup() == nullptr);
  EXPECT_EQ(student4->getMarks().size(), 0);
  EXPECT_FALSE(student.isHeadOfGroup());
  // Marks
  group.addStudent(student2);
  student.addMark(3);
  student.addMark(3);
  student.addMark(3);
  student.addMark(3);
  group.addStudent(&student);
  student2->addMark(5);
  student2->addMark(5);
  student2->addMark(5);
  student2->addMark(5);
  EXPECT_EQ(5, student2->getAverageMark());
  EXPECT_EQ(3, student.getAverageMark());
  // Removing students and average marks
  group2->addStudent(&student3);
  group2->addStudent(student4);
  group.removeStudent(&student);
  group2->addStudent(&student);
  EXPECT_EQ(1, group2->getAverageMark());
  group2->removeStudent(&student);
  EXPECT_EQ(0, group2->getAverageMark());
  // Check size and capacity
  EXPECT_EQ(group2->getStudents().capacity(), 4);
  EXPECT_EQ(group.getStudents().capacity(), 2);
  EXPECT_EQ(group2->getStudents().size(), 2);
  EXPECT_EQ(group.getStudents().size(), 1);
  // Head deleting
  group.addStudent(&student);
  group.chooseHead(&student);
  EXPECT_EQ(group.getHead(), &student);
  group.removeStudent(&student);
  EXPECT_NE(group.getHead(), &student);
  group.addStudent(&student);
  // AverageGroupMark
  EXPECT_EQ(4, group.getAverageMark());
}

// TEST(Deanery, GroupsCreating) {
//  auto *deanery = new Deanery();
//  deanery->createGroups(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/data"));
//  std::vector<Group *> groups = deanery->getGroups();
//  EXPECT_EQ(groups[0]->getTitle(), "Озеро");
//  EXPECT_EQ(groups[0]->getSpec(), "Коррупция");
//  EXPECT_EQ(groups[1]->getTitle(), "ФБК");
//  EXPECT_EQ(groups[1]->getSpec(), "Антикоррупция");
//  EXPECT_EQ(groups[2]->getTitle(), "191ПИ");
//  EXPECT_EQ(groups[2]->getSpec(), "Клоуны");
//}
//
// TEST(Deanery, StudentCreating) {
//  auto *deanery = new Deanery();
//  deanery->createGroups(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/data"));
//  std::vector<Group *> groups = deanery->getGroups();
//  deanery->hireStudents(groups[0],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/Озеро-Коррупция.csv"));
//
//  EXPECT_EQ(groups[0]->getTitle(), "Озеро");
//  EXPECT_EQ(groups[0]->getStudents().size(), 11);
//  EXPECT_EQ(groups[0]->getStudents()[0]->getFullname(),
//            "Владимир Владимирович Путин");
//}
//
// TEST(Deanery, GetStatistics) {
//  auto *deanery = new Deanery();
//  deanery->createGroups(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/data"));
//  std::vector<Group *> groups = deanery->getGroups();
//  deanery->hireStudents(groups[0],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/Озеро-Коррупция.csv"));
//  deanery->hireStudents(groups[1],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/ФБК-Антикоррупция.csv"));
//  deanery->hireStudents(groups[2],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/191ПИ-Клоуны.csv"));
//  deanery->addMarksToAll();
//  deanery->getStatistics(const_cast<char *>(
//                             "/home/stanislav/CLionProjects/"
//                             "tp-lab-5/test/output"));
//  EXPECT_EQ(groups[0]->getStudents().size(), 11);
//  EXPECT_EQ(groups[1]->getStudents().size(), 10);
//  EXPECT_EQ(groups[2]->getStudents().size(), 13);
//}
//
// TEST(Deanery, GetStatisticsToCout) {
//  auto *deanery = new Deanery();
//  deanery->createGroups(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/data"));
//  std::vector<Group *> groups = deanery->getGroups();
//  deanery->hireStudents(groups[0],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/Озеро-Коррупция.csv"));
//  deanery->hireStudents(groups[1],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/ФБК-Антикоррупция.csv"));
//  deanery->hireStudents(groups[2],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/191ПИ-Клоуны.csv"));
//  deanery->addMarksToAll();
//  deanery->getStatistics();
//  EXPECT_EQ(groups[0]->getStudents().size(), 11);
//  EXPECT_EQ(groups[1]->getStudents().size(), 10);
//  EXPECT_EQ(groups[2]->getStudents().size(), 13);
//}
//
// TEST(Deanery, StudentMoving) {
//  auto *deanery = new Deanery();
//  deanery->createGroups(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/data"));
//  std::vector<Group *> groups = deanery->getGroups();
//  deanery->hireStudents(groups[0],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/Озеро-Коррупция.csv"));
//  deanery->hireStudents(groups[1],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/ФБК-Антикоррупция.csv"));
//  deanery->hireStudents(groups[2],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/191ПИ-Клоуны.csv"));
//  deanery->moveStudents(groups[1], groups[2]);
//  EXPECT_EQ(groups[2]->getStudents().size(), 23);
//  EXPECT_EQ(groups[1]->getStudents().size(), 0);
//}
//
// TEST(Deanery, StudentSave) {
//  auto *deanery = new Deanery();
//  deanery->createGroups(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/data"));
//  std::vector<Group *> groups = deanery->getGroups();
//  deanery->hireStudents(groups[0],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/Озеро-Коррупция.csv"));
//  deanery->hireStudents(groups[1],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/ФБК-Антикоррупция.csv"));
//  deanery->hireStudents(groups[2],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/191ПИ-Клоуны.csv"));
//  deanery->saveStaff(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/output"));
//  EXPECT_EQ(groups[0]->getStudents().size(), 11);
//  EXPECT_EQ(groups[1]->getStudents().size(), 10);
//  EXPECT_EQ(groups[2]->getStudents().size(), 13);
//}
//
// TEST(Deanery, StudentsFire) {
//  auto *deanery = new Deanery();
//  deanery->createGroups(
//      const_cast<char *>(
//          "/home/stanislav/CLionProjects/tp-lab-5/test/data"));
//  std::vector<Group *> groups = deanery->getGroups();
//  deanery->hireStudents(groups[0],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/Озеро-Коррупция.csv"));
//  deanery->hireStudents(groups[1],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/ФБК-Антикоррупция.csv"));
//  deanery->hireStudents(groups[2],
//                        const_cast<char *>(
//                            "/home/stanislav/CLionProjects/"
//                            "tp-lab-5/test/data/191ПИ-Клоуны.csv"));
//  deanery->addMarksToAll();
//  deanery->fireStudents(5);
//  EXPECT_NE(groups[0]->getStudents().size(), 11);
//  EXPECT_NE(groups[1]->getStudents().size(), 10);
//  EXPECT_NE(groups[2]->getStudents().size(), 13);
//}
