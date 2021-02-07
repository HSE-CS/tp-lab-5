// Copyright 2021 kostinandrey
#ifndef INCLUDE_STUDENT_H_
#define INCLUDE_STUDENT_H_

#include <string>
#include <vector>

class Group;
class Deanary;

class Student {
public:
    friend class Group;
    friend class Deanary;

    explicit Student(int id, std::string fio);

    void add_to_group(Group* group);
    void add_mark(int mark);
    double get_average_mark();
    [[nodiscard]] int get_id() const;
    std::string get_fio();

private:
    int id;
    std::string fio;
    Group* group;
    std::vector<int> marks;
};

#endif  // INCLUDE_STUDENT_H_
