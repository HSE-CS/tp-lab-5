// Copyright [2021] <Ziganshin Nikita>
#include <Student.h>

Student::Student(int id, std::string fio) {
    this->id = id;
    this->fio = fio;
}

Student::Student(Student *student) {
    id = student->id;
    fio = student->fio;
}

void Student::AddGroup(Group *group) {
    bool error = false;
    for (auto &student : group->students) {
        if (student.id != this->id) {
            continue;
        } else {
            error = true;
            std::cout
            << "There is a student with the same ID. Change student's ID";
        }
    }
    if (!error) {
        this->group = group;
        group->students.emplace_back(this);
    }
}

void Student::AddMark(int mark) {
    marks.push_back(mark);
}

double Student::CalcAverageMark() {
    double average = 0;
    for (int mark : marks) {
        average += mark;
    }
    average = average / marks.size();
    return average;
}

int Student::getId() const {
    return id;
}

const std::string &Student::getFio() const {
    return fio;
}

Group *Student::getGroup() const {
    return group;
}

void Student::setId(int id) {
    this->id = id;
}

void Student::setFio(const std::string &fio) {
    this->fio = fio;
}

Student::~Student() {
    marks.clear();
}

const std::vector<int> &Student::getMarks() const {
    return marks;
}
