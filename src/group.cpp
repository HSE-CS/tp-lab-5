//
//  group.cpp
//  lab5
//
//  Created by Иван Сафронов on 03.11.2019.
//  Copyright © 2019 Иван Сафронов. All rights reserved.
//

#include <ctime>
#include <set>
#include "group.hpp"


/*
 TODO:
 создание группы с указанием названия +
 добавление студента +
 избрание старосты +
 поиск студента по ФИО или ИД +
 вычисление соеднего балла в группе +
 исключение студента из группы +
 */

//Constructor
Group::Group(std::string title) {
    this->title = title;
    this->spec = title.substr(title.find_first_not_of(NUMBERS_SET));
    students.clear();
    quantity = 0;
	group_mean = 0;
    head = NULL;
}

//Public Methods
bool Group::create_student(std::string str) {
    std::vector<std::string> student_info = split(str, ";");
    Student* student_to_add = new Student(student_info[0], this);
    
    for (Student* student : students) {
        if (student->get_id() == student_to_add->get_id()) {
            return false;
        }
    }
    
    students.push_back(student_to_add);
    quantity = students.size();
    return true;
}

bool Group::add_student(Student* student) {
	for (size_t i = 0; i < students.size(); i++) {
		if (student->get_id() == students[i]->get_id()) {
			return false;
		}
		if (student->get_id() < students[i]->get_id()) {
			_add_student_to_arr(student, i);
			return true;
		}
	}
	_add_student_to_arr(student, students.size());
	return true;
}

Student* Group::head_choice() {
    size_t rand_pos = rand() % students.size();
    students[rand_pos]->set_as_head();
	head = students[rand_pos];
    return students[rand_pos];
}

float Group::mean_mark_group() {
    unsigned long accum = 0;
    for (Student* student : students) {
        accum += student->get_mean();
    }
	group_mean = float(accum) / float(students.size());
    return group_mean;
}

void Group::add_marks() {
    for (Student* st : students) {
        for (int i = 0; i < 10; ++i) {
            st->add_mark(rand() % 11);
        }
		st->mean_marks();
    }
}

bool Group::transfer_to_group(id_t id, Group *group) {
    Student* st = NULL;
	for (int i = 0; i < students.size(); i++) {
		if (students[i]->get_id() == id) {
			st = students[i];
//			st->group_enroll(group);
			group->add_student(st);
			_del_student(students.begin() + i);
		}
	}
    return false;
}

bool Group::is_student_exist(id_t id) {
    for (Student* st : students) {
        if (st->get_id() == id) {
            return true;
        }
    }
    return false;
}

bool Group::expell_student(size_t index) {
	if (index < 0 || index >= students.size()) {
		return false;
	}
	_del_student(students.begin() + index);
	return true;
}

bool Group::expell_by_id(id_t id) {
	for (auto iter = students.begin(); iter != students.end(); iter++) {
		if ((*iter)->get_id() == id) {
			_del_student(iter);
			return true;
		}
	}
	return false;
}

Student* Group::search_student(id_t id) {
    for (Student* st : students) {
        if (st->get_id() == id) {
            return st;
        }
    }
    return NULL;
}

Student* Group::search_student(std::string fio) {
    std::vector<std::string> arr = split(fio, " ");
    for (Student* st : students) {
        if (_check_fio(arr, {st->get_first_name(), st->get_second_name(), st->get_last_name()})) {
            return st;
        }
    }
    return NULL;
}

std::vector<id_t> Group::choose_students_to_expell() {
    std::vector<id_t> arr;
	std::cout << "Indexes for expell in: " << title << " " << std::endl;
    for (int i = students.size() - 1; i >= 0; --i) {
        if (students[i]->get_mean() < 3.51) {
			std::cout <<"Index: " << std::to_string(i) << "\tMean: " << std::to_string(students[i]->get_mean()) << " ";
            arr.push_back(i);
        }
    }
	std::cout << std::endl;
    return arr;
}

void Group::print_group_data() {
    std::cout << title << ": " << quantity << " persons" << std::endl << "Middle mark: " << group_mean << std::endl;
    std::cout << "Headman: ";
    head->print_fio();
    for (Student* st : students) {
        st->print_st_data_short();
    }
}

//Private Methods
std::vector<std::string> Group::split(std::string str, std::string sep) {
    std::vector<std::string> res;
    
    size_t pos = str.find(sep);
    while (pos != std::string::npos) {
        std::string temp = str.substr(0, pos);
        res.push_back(temp);
        str = str.substr(pos + 1);
        pos = str.find(sep);
    }
    res.push_back(str);
    return res;
}

bool Group::_check_fio(std::vector<std::string> arr1, std::vector<std::string> arr2) {
    std::set<std::string> set1(arr1.begin(), arr1.end());
    std::set<std::string> set2(arr2.begin(), arr2.end());
    return set1 == set2;
}

void Group::_add_student_to_arr(Student *st, size_t pos) {
	if (pos > students.size()) {
		return;
	} else if (pos == students.size()) {
		students.push_back(st);
	} else {
		students.insert(students.begin() + pos, st);
	}
	quantity++;
}

void Group::_del_student(std::vector<Student *>::iterator iter, bool delete_student) {
	Student* st = (*iter);
	students.erase(iter);
	if (st->is_group_head()) {
		head_choice();
	}
	quantity--;
	if (delete_student) {
		delete st;
	}
}
