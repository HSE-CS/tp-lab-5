// Copyright 2021 Drobot E.D.

#include <string>

#include "Deanary.h"
#include "Group.h"
#include "Student.h"
int main() {
    Student number1_student(63, "Makarov Denis Aleksandrovich");
    Student number2_student(65, "Ivanov Ivan Ivanovich");
    Deanary only;
    only.students_from_file();
    only.groups_from_file();
    only.distribution_of_students();
    only.add_student(&number1_student, "Economy");
    only.add_student(&number2_student, "Economy");
    only.add_marks();
    only.choice_head();
    only.student_transfer("Ivanov Ivan Ivanovich",
                          "Fundamental mathematics");
    only.save_to_file();
    only.print();
    std::cout << "Statistic_groups economy = "
              << only.get_statistic_groups("Economy")
              << std::endl;
    std::cout << "Statistic_students Ivanov = "
              << only.get_statistic_students("Ivanov Ivan Ivanovich")
        << std::endl;

    return 0;
}
