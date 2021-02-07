#pragma once

#include <Student.h>
#include <Group.h>

class Deanary {
public:
    ~Deanary();

    void createGroups(std::ifstream& ifs);
    void hireStudents(std::ifstream& ifs);
    void addMarksToAll();
    void getStatistics() const;
    void moveStudent(const std::string& groupName, const int studentId, const std::string& targetGroupName);
    void saveStaff(std::ofstream& ofs) const;
    void initHeads();
    void fireStudent(const std::string& groupName, const int studentId);

private:
    std::vector<Group*> groups;

    std::vector<Group*>::const_iterator findGroup(const std::string& name);
};
