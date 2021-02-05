// Copyright (c) 2021 Alexey Klimov
//
// Created by Alexey on 29.01.2021.
//

#include <iostream>
#include <algorithm>
#include "Deanary.h"
#include "Group.h"
#include "Student.h"

Group* Deanary::create_group(const std::string& title) {
  return groups.emplace_back(new Group(title));
}

Student* Deanary::hire_student(uint64_t id, const std::string& name,
                           const std::string& g_title) {
  auto g = find_group(g_title);
  if (g == nullptr)
    g = create_group(g_title);

  return g->create_student(id, name);
}

void Deanary::add_marks_to_all(int mark) {
  for (auto g : groups)
    for (auto s : g->students)
      s->add_mark(mark);
}

std::string Deanary::get_statistics() const {
  std::string buf;
  buf += "Overall statistics:\n";
  for (auto g : groups) {
    buf += g->title + ' '
        + '(' + std::to_string(g->students.size()) + " students" + ')' + '\n';
    for (auto s : g->students) {
      buf += std::to_string(s->id)
          + '\t'
          + s->name
          + "\t"
          + std::to_string(s->get_average_mark())
          +'\n';
    }
    buf += '\n';
  }

  return buf;
}

void Deanary::move_student(uint64_t id, const std::string& g_title) {
  auto g = find_group(g_title);
  auto s = find_student(id);
  if (g != nullptr && s != nullptr) {
    s->group->remove_student(s);
    g->add_student(s);
  }
}

void Deanary::save_staff(const std::string& filename) const {
  std::ofstream f(filename);
  f << get_statistics();
  f.close();
}

void Deanary::init_heads() {
  for (auto g : groups)
    g->choose_head();
}

void Deanary::fire_student(uint64_t id) {
  if (auto s = find_student(id); s != nullptr)
    s->group->remove_student(s);
}

Group* Deanary::find_group(const std::string& g_title) {
  for (auto g : groups)
    if (g->title == g_title)
      return g;

  return nullptr;
}

Student* Deanary::find_student(uint64_t _id) {
  for (auto g : groups)
    for (auto s : g->students)
      if (s->id == _id)
        return s;

  return nullptr;
}

void Deanary::from_file(const std::string& filename) {
  std::ifstream f(filename, std::ios::binary);
  std::string buf;

  if (!f.is_open()) return;

  while (std::getline(f, buf)) {
    if (auto pos = buf.find("Group"); pos != std::string::npos) {
      size_t p1 = buf.find('\"'), p2 = buf.find('\"', p1 + 1);
      auto g = create_group(buf.substr(p1 + 1, p2 - p1 - 1));

      int n;
      f >> n;
      std::getline(f, buf);
      for (int i = 0; i < n; i++, std::getline(f, buf)) {
        std::string name;
        uint64_t id;
        std::getline(f, name, ',');
        f >> id;

        g->create_student(id, name);
      }
    }
  }

  f.close();
}
