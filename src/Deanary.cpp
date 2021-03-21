// Copyright Mushka Nikita, 2021



#include "../include/Deanary.h"
#include <ctime>

// ВОЗВРАЩАЛКИ //

void Deanary::CreateGroup(std::string new_title, std::string new_spec) {
    groups.push_back(new Group(std::move(new_title), std::move(new_spec)));
}

void Deanary::CreateStudent(int new_id, std::string new_fio, Group *group) {
    group->AddStudent(new Student(new_id, std::move(new_fio)));
}

Group *Deanary::GroupByTitle(const std::string &title) {
    for (auto &group : groups) {
        if (group->GetTitle() == title) {
            return group;
        }
    }
    return nullptr;
}


void Deanary::ChooseLeaders() {
    for (Group *group : groups) {
        if (!group->students.empty()) {
            Student *newHead = group->students[0];
            for (Student *student : group->students) {
                if (student->CountAvgMark() > newHead->CountAvgMark())
                    newHead = student;
            }
            group->ChooseLeader(newHead);
        }
    }
}

void Deanary::FillMarks() {
    std::srand(static_cast<unsigned int>(time(nullptr)));
    for (Group *group : groups) {
        for (Student *student : group->students) {
            for (int i = 0; i < std::rand() % 6 + 3; i++) {
                student->AddMark(std::rand() % 10);
            }
        }
    }
}

void Deanary::MoveStudent(Student *student, Group *group) {
    group->AddStudent(student);
    student->group->RemoveStudent(student);
}

void Deanary::RemoveFailingStudents() {
    float F = 4;
    for (Group *group : groups) {
        for (Student *student : group->students) {
            if (student->CountAvgMark() < F)
                student->group->RemoveStudent(student);
        }
    }
}

std::string Deanary::GetStats() {
    std::string stats;
    for (Group *group : groups) {
        stats += ("Group: " + group->title + " ( " + group->spec + " )");
        stats += " - " + to_string(group->CountAvgMark()) + '\n';
        stats+= "Leader - " + to_string(group->GetLeader()->id)
                + ", " + group->GetLeader()->GetFio() + "\n\n";
    }
    return stats;
}


// РАБОТА С ФАЙЛАМИ //

bool Deanary::File_CreateGroups(const std::string &path) {
    std::ifstream data(path);
    if (!data) {
        std::cout << "\nfile is not found\n";
        return false;
    }

    std::string line;
    while (std::getline(data, line)) {
        int pos = line.find(',');
        CreateGroup(line.substr(0, pos), line.substr(pos + 2, line.size()));
    }

    return true;
}

bool Deanary::File_CreateStudents(const std::string &path) {
    std::ifstream data(path);
    if (!data) {
        std::cout << "\nfile is not found\n";
        return false;
    }

    std::string line;
    int i = 0;
    while (std::getline(data, line)) {
        i++;
        int pos1 = line.find(',');
        std::string sub_line = line.substr(pos1 + 1);
        int pos2 = sub_line.find(',');

        Group *group = GroupByTitle(sub_line.substr(pos2 + 2));
        if (!group) {
            std::cout << i << ' ' << "\ngroup is not found\n";
            return false;
        }

        CreateStudent(
                std::stoi(line.substr(0, pos1)),
                line.substr(pos1 + 2, pos2 - 1),
                group);
    }
}

bool Deanary::File_SaveDeanary(std::string path) {
    std::ofstream file(path);
    if (!file) {
        std::cout << "\nfile couldn't be created\n";
        return false;
    }

    for (Group *group : groups) {
        file << "Group: " << group->title << " ( " << group->spec << " )\n";

        for (Student *student : group->students) {
            file << " - " << student->id;
            if (group->leader == student) {
                file << " ( LEADER )";
            }
            file << ' ' << student->fio << ' ';
            for (int mark : student->marks) {
                file << mark << ' ';
            }


            file << '\n';
        }
        file << '\n';
    }
    file.close();
    return true;
}
