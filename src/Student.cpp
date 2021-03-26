// Copyright 2021 by Sid

#include "Student.h"

/*
 TODO:
 создание студента с указанием ИД и ФИО +
 зачисление в группу +
 добавление оценки +
 вычисление средней оценки +
 */

//Constructor
Student::Student(std::string id_and_fio, Group* group) {
    std::vector<std::string> arr = Group::split(id_and_fio, " ");
    id = std::stoi(arr[0]);
    last_name = arr[1];
    first_name = arr[2];
    second_name = arr[3];
    
    is_head = false;
    this->group = group;
}

//Destructor
Student::~Student() {
    last_name.clear();
    first_name.clear();
    second_name.clear();
    marks.clear();
    group = NULL;
}

//Public Methods
void Student::add_mark(unsigned int mark) {
    marks.push_back(mark);
    num = marks.size();
}

float Student::mean_marks() {
    mean_mark = std::accumulate(marks.begin(), marks.end(), 0.0) / marks.size();
	return mean_mark;
}

void Student::print_st_data_short() {
    print_fio();
    std::cout << "\tMean marks: " << get_mean() << std::endl;
}

void Student::print_fio() {
	std::cout << "\tID: " << id << ". " << last_name + " " << first_name + " " << second_name << std::endl;
}

//Private Methods

