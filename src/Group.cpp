// Copyright 2021 TimurZaytsev

#include "Group.h"
#include "Student.h"

#include <utility>
#include <algorithm>

Group::Group(std::string t) :
    title(std::move(t)),
    head(nullptr)
{}

double Group::get_average_mark() const {
    double result = 0;
    for (auto s : students)
        result += s->get_average_mark();

    return students.empty() ? 0 : result / students.size();
}

Student* Group::get_student(uint64_t _id) const {
    Student* result = nullptr;

    for (auto s : students)
        if (s->id == _id)
            result = s;

    return result;
}

bool Group::contains_student(uint64_t _id) const {
    return get_student(_id) != nullptr;
}

bool Group::is_empty() const {
    return students.empty();
}

Student* Group::create_student(uint64_t _id, const std::string& _name) {
    return students.emplace_back(new Student(_id, _name, this));
}

void Group::add_student(Student* s) {
    students.push_back(s);
    s->group = this;
}

void Group::choose_head() {
    if (!students.empty())
        head = students[(size_t)rand() % students.size()];
}

void Group::remove_student(Student* s) {
    auto pos = std::find(students.begin(), students.end(), s);

    if (pos != students.end())
        students.erase(pos);

    s->group = nullptr;
}
