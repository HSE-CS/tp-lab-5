#include <utility>
#include <fstream>
#include "Dinary.h"


void Dinary::addStudentFromFile(string f) {

    string line;
    f = "..\\"+f;
    ifstream file(f);

    if (file.is_open())
        while (getline(file, line))
            {
                students.push_back(new Student(id, line));
                id++;
            }
    file.close();

}

void Dinary::createGroupFromFile(string f){
    int prevId = id;

    addStudentFromFile(f);

    size_t lastindex = f.find_last_of('.');
    string rawname = f.substr(0, lastindex);
    groups.push_back(new Group(rawname));
    int n = groups.size()-1;

    for (int i = prevId; i<id; i++) {
        groups[n]->addStudent(students[i]);
    }
}

void Dinary::addRandomMarks() {
    srand(time(NULL));
    for (auto st : this->students) {
        int num = rand() % 3 + 3;
        for (int i = 0; i < num; i++)
        {
            int mark = rand()%10;
            st->addMark(mark);
        }
        st->setAvr(st->average());
    }
    //this->printGroup("19PMI");

}

void Dinary::printGroup(string f){
    cout << "\t\t" << f << endl;
    int k = findPos(move(f));
    groups[k]->printAll();
    cout << "\n";
}


int Dinary::findPos(string f){
    int i = 0;
    for (auto gr: groups)
    {
        if (gr->getGroup() == f)
            return i;
        i++;
    }

}


void Dinary::Statistics(){
    for (auto gr : groups) {
        cout << gr->getGroup() << endl;
            for (auto st : students)
                if (st->getGroup() == gr)
                {
                    st->show();
                }
        cout << "Group avr: "<< gr->groupAverage() << endl;
        cout << "Head: " << gr->getHead()->getFio() << endl << endl;
        }
    }


void Dinary::moveFromGroup(string st, string gr) {
    int index = findStudent(st);

    for (auto i : groups)
        if (i->getGroup() == gr)
            i->addStudent(students[index]);

    (students[index]->getGroup())->exclude(st);
}

int Dinary::findStudent(string st){
    int index = 0;
    for (auto i : students)
    {
        if (i->getFio() == st)
            return index;
        index++;
    }
    return -1;
}

void Dinary::moveFromGroup(int numId, string gr) {
    int index = findStudent(numId);
    Group* prev;
    prev = students[index]->getGroup();
    for (auto i : groups)
        if (i->getGroup() == gr)
            i->addStudent(students[index]);

    prev->exclude(numId);
}

int Dinary::findStudent(int numId){
    int index = 0;
    for (auto i : students) {
        if (i->id == numId) {
            cout << "founded\n";
            return index;
        }
        index++;
    }
    return -1;
}

void Dinary::removeDvoechnik(){
    int n = students.size();
    for (int i = 0; i < n; i++)
    {
        if (students[i]->getAvr()<4)
        {
            (students[i]->getGroup())->exclude(students[i]->id);
            students.erase(students.begin()+i);
            i--;
            n--;
        }
    }
}

void Dinary::writeToNewFile(string f){
    std::ofstream out;          // поток для записи
    string k = "../" + f;
    out.open(k);

    size_t lastindex = f.find_last_of('.');
    string rawname = f.substr(3, lastindex-3);
    cout << rawname << endl;
    if (out.is_open())
    {
        cout << "OK";

        for (auto gr : groups) {
            if (gr->getGroup() == rawname){
                for (auto st : students)
                    if (st->getGroup() == gr)
                    {
                        st->show();
                        out << st->getFio() << " -- " <<st->getAvr() << endl;
                    }

                break;
            }

        }

    }
}

void Dinary::makeHead(){
    for (auto i : groups)
    {
        i->election();
    }
}