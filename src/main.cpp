// Copyright 2021 FOM

#include "Student.h"
#include "Deanary.h"
#include "Group.h"

int main() {
    Deanary FIMIKN;
    Student student_1(24, "Matsovkin Artem Demyanovich");
    Student student_2(12, "Greshnev Eduard Emilevich");
    Student student_3(10, "Efremova Yulia Vissarionovna");
    Student student_4(43, "Pudina Yunona Pakhomovna");
    FIMIKN.student_reading();
    FIMIKN.group_reading();
    FIMIKN.student_distribution();
    FIMIKN.student_hire(&student_1, "PI");
    FIMIKN.student_hire(&student_2, "PI");
    FIMIKN.student_hire(&student_3, "PMI");
    FIMIKN.student_hire(&student_4, "Math");
    FIMIKN.marks_adding();
    FIMIKN.student_head();
    FIMIKN.student_moving("Matsovkin Artem Demyanovich", "PMI");
    FIMIKN.student_moving("Efremova Yulia Vissarionovna", "PI");
    FIMIKN.student_moving("Greshnev Eduard Emilevich", "Math");
    FIMIKN.student_moving("Pudina Yunona Pakhomovna", "PI");
    FIMIKN.print();
    std::cout << "Group_statistic PI =  " 
        << FIMIKN.group_statistic("PI") << std::endl;
    std::cout << "Group_statistic PMI =  " 
        << FIMIKN.group_statistic("PMI") << std::endl;
    std::cout << "Group_statistic Math =  "
        << FIMIKN.group_statistic("Math") << std::endl;
    std::cout << "Statistic Matsovkin Artem Demyanovich  = " 
        << FIMIKN.student_statistic("Matsovkin Artem Demyanovich") << std::endl;
    std::cout << "Statistic Efremova Yulia Vissarionovna  = " 
        << FIMIKN.student_statistic("Efremova Yulia Vissarionovna") << std::endl;
    std::cout << "Statistic Greshnev Eduard Emilevich  = " 
        << FIMIKN.student_statistic("Greshnev Eduard Emilevich") << std::endl;
    std::cout << "Statistic Pudina Yunona Pakhomovna  = " 
        << FIMIKN.student_statistic("Pudina Yunona Pakhomovna") << std::endl;
    return 0;
}
