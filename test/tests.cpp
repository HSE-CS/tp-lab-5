#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "Student.h"
#include "Group.h"
#include "Deanary.h"


TEST(GroupTest, Test1) {
	Group group("19pi-1", "PI");
	EXPECT_EQ(0, group.getNumStudents());
}

TEST(GroupTest, Test2) {
	Group group("19pi-1", "PI");
	EXPECT_EQ(true, group.isEmpty());
}

TEST(GroupTest, Test3) {
	Group group("19pi-1", "PI");
	EXPECT_EQ(true, group.isEmpty());
}

TEST(GroupTest, Test4) {
	Group group("19pi-1", "PI");
	EXPECT_EQ("19pi-1", group.getTitle());
}

TEST(StudentT, Test5) {
	Student stud(101, "Osmanov Islam");
	EXPECT_EQ(101, stud.getId());
}

TEST(StudentT, Test6) {
	Student stud(101, "Osmanov Islam");
	EXPECT_EQ("Osmanov Islam", stud.getFIO());
}

TEST(DeanaryTest, Test7) {
	Deanary decanat;
	decanat.createGroups("Students.txt", "Groups.txt");
	EXPECT_EQ(3, decanat.getNumGroups());
}

TEST(DeanaryTest, Test8) {
	Deanary decanat;
	decanat.createGroups("Students.txt", "Groups.txt");
	EXPECT_EQ(false, decanat.getGroup(0).isEmpty());
}

TEST(DeanaryTest, Test9) {
	Deanary decanat;
	decanat.createGroups("Students.txt", "Groups.txt");
	decanat.addMarksToAll();
	EXPECT_TRUE(decanat.getGroup(0).getAverageMark() <=6 && decanat.getGroup(0).getAverageMark() > 0);
}

TEST(HeadTest, Test10) {
	Student stud(101, "Osmanov Islam");
	EXPECT_EQ(false,stud.isHeadOfGroup());
}
