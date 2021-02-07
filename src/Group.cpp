//  Copyright 2021 dmitrycvetkov2000

#include "Group.h"
#include "Student.h"

#include <algorithm>
#include <cstdint>
#include <numeric>

Group::Group(const std::string& name) : title(name) {
}

Group::~Group() {
    for (const auto& s : students)
        delete s;
}

void Group::addStudent(Student* student) {
    students.push_back(student);
}

void Group::chooseHead(int id) {
    headId = id;
}

double Group::getAverageMark() const {
    size_t marksCount = 0;
    int sum = std::accumulate(std::begin(students), std::end(students),
        0.0, [&marksCount](unsigned short a, Student* const student) {
        const std::vector<int> marks = student->marks;
        marksCount += marks.size();
        return  a + std::accumulate(std::begin(marks), std::end(marks), 0.0);
        });
    return sum / static_cast<double>(marksCount);
}

std::vector<Student*>::const_iterator Group::findStudent(int id) const {
    return std::find_if(std::begin(students), std::end(students),
        [&id](Student* const student) {
        return student->id == id;
        });
}

Student* Group::getStudent(int id) const {
    auto it = findStudent(id);
    return (it != std::end(students)) ? *it : nullptr;
}

bool Group::containsStudent(int id) const {
    return findStudent(id) != std::end(students);
}

void Group::removeStudent(int id) {
    auto it = findStudent(id);
    (*it)->group = nullptr;
    students.erase(it);
}

bool Group::isEmpty() const {
    return students.empty();
}

