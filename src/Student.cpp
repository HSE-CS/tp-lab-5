// Copyright 2021 GN
#include <Student.h>
double Student::avMark() {
    double sum = 0;
    if (marks.empty()) {
        return sum;
    }
    for (auto const& element : marks)
        sum += element;
    double res = sum / marks.size();
    return res;
}
void Student::addMark(int m_) {
    marks.push_back(m_);
}
int Student::getId() {
    return id;
}
std::string Student::getName() {
    return fio;
}
