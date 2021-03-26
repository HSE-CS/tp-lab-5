// Copyright 2021 Shaidi
#include "Deanary.h"

std::vector<std::string> split(const std::string& s, char del) {
  std::vector<std::string> words;
  std::string word;
  std::istringstream wordStream(s);
  while (getline(wordStream, word, del)) words.push_back(word);
  return words;
}

Deanary::Deanary() {
  dean_id = 0;
  std::vector<Group*> groups;
}

void Deanary::add_groups(std::string fios_input, std::string groups_input) {
  std::ifstream file;
  file.open(groups_input, std::ios::in);
  std::string buf;
  std::vector<std::string> current_str;
  while (getline(file, buf)) {
    current_str = split(buf, ':');
    groups.push_back(new Group(current_str[0], current_str[1]));
  }
  file.close();
  //
  file.open(fios_input, std::ios::in);
  while (getline(file, buf)) {
    current_str = split(buf, ':');
    Student* student = new Student(current_str[0], dean_id);
    bool is_constructed = 0;
    int group_num = -1;
    for (unsigned int i = 0; i < groups.size(); i++) {
      if (groups[i]->get_title() == current_str[1]) {
        is_constructed = 1;
        group_num = i;
      }
    }
    if (!is_constructed) {
      Group* group = new Group(current_str[1], "");
      groups.push_back(group);
      group_num = groups.size() - 1;
    }
    groups[group_num]->add_student(student);
    student->add_to_group(groups[group_num]);
    dean_id++;
  }
  file.close();
}

void Deanary::change_group(std::string fio, std::string old_group,
                           std::string new_group) {
  Group* group1 = nullptr;
  Group* group2 = nullptr;
  for (Group* group : groups) {
    if (group->get_title() == old_group) group1 = group;
    if (group->get_title() == new_group) group2 = group;
  }
  Student* student = group1->search_by_fio(fio);
  if ((group1 == nullptr) || (group2 == nullptr)) {
    std::cout << "Error. Try again" << std::endl;
    return;
  } else {
    group1->remove_student(student);
    group2->add_student(student);
  }
}

void Deanary::heads_choice() {
  for (Group* group : groups) {
    group->head_choice();
  }
}

void Deanary::set_random_marks(unsigned int number) {
  int random_mark = 0;
  unsigned seed = time(NULL);
  for (Group* group : this->groups) {
    for (Student* student : group->get_students()) {
      for (unsigned int i = 0; i < number; i++) {
        random_mark = std::rand() % 10 + 1;
        student->add_mark(random_mark);
      }
    }
  }
}

void Deanary::get_statistics() const {
  for (Group* group : groups) {
    group->average_group_mark();
    std::vector<Student*> students = group->get_students();
    unsigned int best_mark = 0;
    unsigned int index;
    for (unsigned int i = 0; i < students.size(); i++) {
      if ((students[i]->get_average_mark()) > best_mark) {
        index = i;
      }
    }
    std::cout << "Best student : " << students[index]->get_fio() << std::endl;
  }
}

void Deanary::remove_students() {
  for (Group* group : groups) {
    for (Student* student : group->get_students()) {
      if (student->get_average_mark() < 4) {
        group->remove_student(student);
      }
    }
  }
}

void Deanary::new_data(std::string names_output,
                          std::string groups_output) const {
  std::ofstream file;
  file.open(names_output, std::ios::out);
  if (file.is_open()) {
    for (Group* group : groups) {
      for (Student* student : group->get_students()) {
        std::cout << student->get_fio() << " : " << group->get_title()
                  << std::endl;
      }
    }
  } else {
    std::cout << "File can't be opened" << std::endl;
  }
  file.close();
  file.open(groups_output, std::ios::out);
  if (file.is_open()) {
    for (Group* group : groups) {
      std::cout << group->get_title() << " : " << group->get_spec()
                << std::endl;
    }
  } else {
    std::cout << "File can't be opened" << std::endl;
  }
  file.close();
}
