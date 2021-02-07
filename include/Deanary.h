// Copyright 2021 dmitrycvetkov2000

#ifndef INCLUDE_DEANARY_H_
#define INCLUDE_DEANARY_H_

#include <Student.h>
#include <Group.h>

#include <string>
#include <vector>

class Deanary {
   public:
    ~Deanary();

    void createGroups(std::ifstream& ifs);
    void hireStudents(std::ifstream& ifs);
    void addMarksToAll();
    void getStatistics() const;
    void moveStudent(const std::string& groupName, const int studentId,
        const std::string& targetGroupName);
    void saveStaff(std::ofstream& ofs) const;
    void initHeads();
    void fireStudent(const std::string& groupName, const int studentId);

    private:
    std::vector<Group*> groups;

    std::vector<Group*>::const_iterator findGroup(const std::string& name);
};

#endif  // INCLUDE_DEANARY_H_
