// Copyright 2021 TimurZaytsev

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <vector>
#include <string>
#include <fstream>

class Group;
class Student;

class Deanary {
public:
	Deanary() = default;
	Group* create_group(const std::string& str);
	Student* hire_student(uint64_t, const std::string&, const std::string&);
	std::string get_statistics() const;
	void add_marks_to_all(int);
	void move_student(uint64_t, const std::string&);
	void save_staff(const std::string&) const;
	void from_file(const std::string&);
	void init_heads();
	void fire_student(uint64_t);

private:
	Student* find_student(uint64_t);
	Group* find_group(const std::string&);
	std::vector<Group*> groups;
};

#endif  // INCLUDE_DEANARY_H_
