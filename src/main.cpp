// Copyright 2021 Tatsenko Ilya
#include<iostream>
#include"Deanary.h"
#include"Group.h"
#include"Student.h"

int main() {
    Deanary decanat;
    decanat.creative_groups_from_file("D:\\files\\groups.txt");
    decanat.create_students_from_file("D:\\files\\students.txt");
    // decanat.creative_groups_from_file("D:\\files\\groups.txt");
    decanat.add_marks_to_all();
    decanat.init_heads();
    decanat.get_statistic();
    // decanat.fire_student("Àêèìîâ Áîðèñ Àëåêñååâè÷");
    decanat.move_students("Tatsenko Ilya Michailovich", "19PI");
    decanat.get_statistic();
    return 0;
}
