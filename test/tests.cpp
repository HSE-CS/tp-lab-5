// Copyright 2020 GHA Test Team

#include <gtest/gtest.h>
#include <Deanary.h>
#include <string>

TEST(StudentTest, test1) {
	std::string name = "Name_test";
	Student test(10, name);
	EXPECT_EQ(10, test.getId());
}

TEST(StudentTest, test2) {
	std::string name = "Name_test";
	Student test(10, name);
	EXPECT_EQ(name, test.getName());
}

TEST(StudentTest, test3) {
	std::string name = "Name_test";
	Student test(10, name);
	EXPECT_NEAR(0.00, test.getAverageMark, 0.01)
}

TEST(GroupTest, test4) {
	std::string title = "Name_of_Group";
	std::string spec = "Spec_of_Group";
	Group test{ title, spec };
	EXPECT_EQ(title, test.getTitle());
}

TEST(GroupTest, test5) {
	std::string title = "Name_of_Group";
	std::string spec = "Spec_of_Group";
	Group test{ title, spec };
	EXPECT_EQ(0, test.getGroupStudents()->size());
}

TEST(GroupTest, test6) {
	std::string title = "Name_of_Group";
	std::string spec = "Spec_of_Group";
	Group test{ title, spec };
	EXPECT_EQ(1, static_cast<int>(test.isEmpty()));
}

TEST(GroupTest, test7) {
	std::vector<std::string> students_name{ "test_1", "test_2.", "test_3" };
	std::string title = "Name_of_Group";
	std::string spec = "Spec_of_Group";
	Group test{ title, spec };
	test.getGroupStudents()->push_back(new Student(1, students_name[0]));
	test.getGroupStudents()->push_back(new Student(2, students_name[1]));
	test.getGroupStudents()->push_back(new Student(3, students_name[2]));
	EXPECT_EQ(3, test.getGroupStudents()->size());
}

TEST(GroupTest, test8) {
	std::vector<std::string> students_name{ "test_1", "test_2.", "test_3" };
	std::string title = "Name_of_Group";
	std::string spec = "Spec_of_Group";
	Group test{ title, spec };
	test.getGroupStudents()->push_back(new Student(1, students_name[0]));
	test.getGroupStudents()->push_back(new Student(2, students_name[1]));
	test.getGroupStudents()->push_back(new Student(3, students_name[2]));
	EXPECT_EQ(students_name[0], test.getStudent(1).getName());
}

TEST(DeanaryTest, test9) {
	Deanary test{};
	EXPECT_EQ(44, test.get_st_num());
}

TEST(DeanaryTest, test10) {
	Deanary test{};
	EXPECT_EQ(4, test.get_gr_num());
}

TEST(DeanaryTest, test11) {
	Deanary test{};
	std::string str = "Business Informatics";
	test.moveStudents(1, str);
	test.moveStudents(2, str);
	EXPECT_EQ(2, test.get_mv_num());
}

TEST(DeanaryTest, test12) {
	Deanary test{};
	std::string str = "Business Informatics";
	test.fireStudents(1);
	test.fireStudents(2);
	test.fireStudents(3);
	EXPECT_EQ(3, test.get_fi_num());
}
