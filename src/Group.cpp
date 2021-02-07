#include "Group.h"
#include "Student.h"
#include <utility>
#include <random>
#include <algorithm>


Group::Group(std::string title) {
    this->title = std::move(title);
}

void Group::addStudent(Student *student) {
    this->students.push_back(student);
}

double Group::getAverageGroupMark() {
    double sum = 0;
    for (auto & student : this->students) {
        sum += student->getAverageMark();
    }
    return !this->students.empty() ? sum / this->students.size() : 0;
}

void Group::removeStudent(Student *student) {
    auto stud = std::find(this->students.begin(), this->students.end(), student);
    this->students.erase(stud);
}

Student* Group::searchStudentById(int id) {
    for (auto & student : this->students){
        if (student->getId() == id) return student;
    }
    return new Student(0, "ERROR");
}

Student* Group::searchStudentByName(std::string name) {
    for (auto & student : this->students) {
        if (student->getName() == name) return student;
    }
    return new Student(0, "ERROR");
}

void Group::chooseHead() {
    std::random_device randomDevice;
    std::mt19937 generator(randomDevice());
    std::uniform_int_distribution<> distribution(0, this->students.size() - 1);
    int headIdx = distribution(generator);
    this->head = this->students[headIdx];
}

std::string Group::getTitle() {
    return this->title;
}
