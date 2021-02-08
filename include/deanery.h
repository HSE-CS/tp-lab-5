//
// Created by Краюшкина Екатерина on 08/02/2021.
//

#ifndef DEANARY_DEANERY_H
#define DEANARY_DEANERY_H

#include <string>
#include <iostream>
#include <vector>
#include <fstream>
#include <iterator>
#include <random>

using namespace std;
class Group;

class Student{
private:
    unsigned int id;
    string fio;
    Group* group;
    vector<unsigned int> marks;
    double avg;
    bool heading;
public:
    Student(unsigned int id, string fam);
    Student(unsigned int id, string fam, Group* group);
    Student(unsigned int id, string fam, Group* group, bool heading);
    void attend(Group* group);
    Group* getgroup() const;
    void addmark(unsigned int mark);
    vector<unsigned int> getmarks() const;
    size_t getnum() const;
    void calcavg();
    double getavg() const;
    string getfio() const;
    void setd(unsigned int id);
    unsigned int getd() const;
};



class Group{
private:
    string title;
    vector<Student*> list;
    Student* head;
    vector<int> search_(string fio) const;
    int search_(unsigned int id) const;
public:
    Group(string title);
    void add(Student* st);
    string get_tittle() const;
    void voting();
    void print() const;
    vector<Student*> search(string fio) const;
    Student* search(unsigned int id) const;

    double getavg() const;
    double getavg2() const;
    void exclude(Student* st);
    Student* get_head() const;

};


class Deanery{
private:
    vector<Student*> students;
    vector<Group*> groups;
public:
    Deanery();
    Deanery(string input);
    void print_groups() const;
    void print_students() const;
    vector <unsigned int> get_marks(int id) const;
    vector <unsigned int> get_marks2(int num) const;
    void exclude(int id);
    void auto_exclude();
    void voting(string gr);
    void transfer(int id, string gr2);
    void refresh_file(string output) const;
    size_t get_numOFgroups() const;
    size_t get_numOFst() const;

    void add_random_marks() const;




};


int after_space( string buf, int space_num);
int after_space( string & buf,int cur_iter, int space_num);

bool check_fio(string & buf,int cur_iter);
bool check_group(string & buf,int cur_iter);
bool check_id(string & buf,int cur_iter);
bool check_marks(string & buf,int cur_iter);

vector<int> marks_pars(string &buf);
string name_pars(string & buf);
string group_pars(string & buf);
int id_pars(string & buf);
#endif //DEANARY_DEANERY_H