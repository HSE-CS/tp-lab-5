#include<iostream>
#include"Deanary.h"
#include"Group.h"
// Copyright 2021 Tatsenko Ilya
#include"Student.h"
#include<time.h>

int main() {
    Deanary decanat;
    decanat.creative_groups_from_file("D:\\files\\groups.txt");
    decanat.create_students_from_file("D:\\files\\students.txt");
    // decanat.creative_groups_from_file("D:\\files\\groups.txt");
    decanat.add_marks_to_all();
    decanat.init_heads();
    decanat.get_statistic();
    // decanat.fire_student("Акимов Борис Алексеевич");
    // decanat.save_data_in_file("D:\\files\\students.txt", "D:\\files\\groups.txt");
    decanat.move_students("Акимов Борис Сергеевич", "19PI");
    decanat.get_statistic();
    return 0;
}
