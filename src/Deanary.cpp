// Copyright 2021 by Sid

#include <fstream>
#include "Deanery.h"
#define BUF_SIZE 200

/*
 TODO:
 создание студентов на основе данных из файла +
 создание групп на основе данных из файла +
 добавление случайных оценок студентам +
 получение статистики по успеваемости студентов и групп
 перевод студентов из группы в группу +
 отчисление студентов за неуспеваемость +
 сохранение обновленных данных в файлах +
 инициация выборов старост в группах +
 вывод данных на консоль +
 */

//Constructor
Deanery::Deanery(std::string stud_file_name, std::string gr_file_name) {
    std::ifstream students_file(stud_file_name);
    if (!students_file.is_open()) {
        std::cout << "Students file does not exist" << std::endl;
        return;
    }
    
    std::ifstream group_file(gr_file_name);
    if (!group_file.is_open()) {
        std::cout << "Group file does not exist" << std::endl;
        return;
    }
    
    std::string str;
    while (std::getline(group_file, str)) {
        groups.insert(std::pair<std::string, Group*>(str, new Group(str)));
    }
    
    while (std::getline(students_file, str)) {
        size_t pos = str.find_last_of(NUMBERS_SET);
        std::string group_name = str.substr(pos - 1);
        groups[group_name]->create_student(str);
    }
	head_choices();
	students_file.close();
	group_file.close();
}

//Public Methods
void Deanery::add_marks_for_groups() {
    for (std::pair<std::string, Group*> pair : groups) {
        pair.second->add_marks();
    }
}

//void Deanery::calculate_means();

bool Deanery::student_transfer(id_t id, std::string from_group, std::string to_group) {
    if (!groups.count(from_group) || !groups.count(to_group)) {
        return false;
    }
    Group* group_start = groups[from_group];
    group_start->transfer_to_group(id, groups[to_group]);
    return true;
}

void Deanery::expell_students() {
    for (std::pair<std::string, Group*> pair : groups) {
        std::vector<id_t> ids = pair.second->choose_students_to_expell();
        for (id_t id : ids) {
            pair.second->expell_student(id);
        }
    }
	calculate_means();
}

bool Deanery::expell_one_student(id_t id) {
    Group* gr = NULL;
    for (std::pair<std::string, Group*> pair: groups) {
        if (pair.second->is_student_exist(id)) {
            gr = pair.second;
        }
    }
    if (gr == NULL) {
        return false;
    }
    gr->expell_by_id(id);
    return true;
}

void Deanery::head_choices() {
    for (std::pair<std::string, Group*> pair : groups) {
        pair.second->head_choice();
    }
}

void Deanery::head_choices_in_group(std::string group_name) {
	groups[group_name]->head_choice();
}

void Deanery::data_output() {
    for (std::pair<std::string, Group*> pair : groups) {
        pair.second->print_group_data();
		std::cout << std::endl;
    }
}

void Deanery::save_data(std::string file_name) {
    std::ofstream file_to_save(file_name);
    std::string buf;
    for (std::pair<std::string, Group*> pair : groups) {
        std::vector<Student*> students = pair.second->get_students();
        for (Student* st : students) {
            buf = std::to_string(st->get_id()) + " " + st->get_last_name() + " " + st->get_first_name() + " " + st->get_second_name() + ";" + pair.first + "\n";
            file_to_save << buf;
        }
    }
	file_to_save.close();
}

void Deanery::calculate_means() {
	for (std::pair<std::string, Group*> pair : groups) {
//		std::vector<Student*> arr = pair.second->get_students();
//		for (Student* st : arr) {
//			st->mean_marks();
//		}
        pair.second->mean_mark_group();
	}
}


//Private Methods
