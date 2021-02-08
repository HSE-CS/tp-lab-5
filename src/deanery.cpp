//
// Created by Краюшкина Екатерина on 08/02/2021.
//
#include "deanery.h"
ofstream fout("/Users/artemaroslankin/Documents/Progacpp/deanary/output.txt");

Student::Student(unsigned int id, string fam){
    this->id = id;
    this->fio = fam;
    this->group = NULL;
    this->avg = -1;
}

Student::Student(unsigned int id, string fam, Group* group){
    this->id = id;
    this->fio = fam;
    this->group = group;
    group->add(this);
    this->avg = -1;
}

Student::Student(unsigned int id, string fam, Group* group, bool heading){
    this->id = id;
    this->fio = fam;
    this->group = group;
    this->heading = heading;
    group->add(this);
    this->avg = -1;
}

void Student::attend(Group* group){
    this->group = group;
    group->add(this);
}

void Student::addmark(unsigned int mark){
    marks.push_back(mark);
}

vector<unsigned int> Student::getmarks() const{
    vector<unsigned int> ans;
    ans = this->marks;
    return ans;
}
size_t Student::getnum() const{
    return this->marks.size();
}

void Student::calcavg() {
    if(marks.size()==0)
        this->avg = -1;
    else {
        double ans = 0;
        for (int i = 0; i < marks.size(); i++)
            ans = ans + marks[i];
        ans = ans / marks.size();
        this->avg = ans;
    }
}
Group* Student::getgroup() const {
    return this->group;
}
double Student::getavg() const {
    if(marks.size()==0)
        return -1;
    else {
        double ans = 0;
        for (int i = 0; i < marks.size(); i++)
            ans = ans + marks[i];
        ans = ans / marks.size();
        return ans;
    }
}

void Student::setd(unsigned int id) {
    this->id = id;
}

unsigned int Student::getd() const {
    return this->id;
}
string Student::getfio() const {
    return this->fio;
}







Group::Group(string title) {
    this->title = title;
}

void Group::add(Student *st) {
    for(int i=1; i < list.size(); i++){
        if(st->getd() == list[i]->getd())
            if(st->getfio() == list[i]->getfio()) {
                cout << "Probabilty of Student" << st->getfio() << "beeing already in group";
                cout << "Change id, if it is wrong";
                cout << endl;
                return;
            }
            else{
                unsigned int k = 1;

                while(k<1000000){
                    int p = 0;
                    for(int i=1; i < list.size(); i++)
                        if(list[i]->getd()!=k)
                            p++;
                    if(p == this->list.size()){
                        st->setd(k);
                        list.push_back(st);
                        return;
                    }
                    k++;

                }
                cout << "Error:The group is full!";
                cout << endl;
                return;
            }
    }
    list.push_back(st);
    return;
}

void Group::voting(){
    double avgmax = -1;
    head = list[0];
    for(int i=0; i < list.size(); i++)
        if(avgmax <= list[i]->getavg()) {
            avgmax = list[i]->getavg();
            head = list[i];
        }
    return;

}

void Group::print() const {
    for(int i=0; i < list.size(); i++){
        if(list[i]==head) cout <<"Head ";
        cout <<"id: "<<list[i]->getd() << "   ; FIO: " << list[i]->getfio();
        cout << endl;
    }
}

vector<Student*> Group::search(string fio) const {
    vector<Student*> res;
    for(int i=0; i < list.size(); i++){
       if(list[i]->getfio() == fio)
           res.push_back(list[i]);
    }
    return res;

}

Student* Group::search(unsigned int id) const {
    for(int i=0; i < list.size(); i++){
        if(list[i]->getd() == id)
            return list[i];
    }
    return NULL;
}

vector<int> Group::search_(string fio) const {
    vector<int> res;
    for(int i=0; i < list.size(); i++){
        if(list[i]->getfio() == fio)
            res.push_back(i);
    }
    return res;

}

string Group::get_tittle() const {
    return this->title;
}

int Group::search_(unsigned int id) const {
    for(int i=0; i < list.size(); i++){
        if(list[i]->getd() == id)
            return i;
    }
    return -1;
}


double Group::getavg() const {
    double sum = 0;
    int k = 0;
    for(int i=0; i < list.size(); i++) {
        if((list[i]->getmarks()).size() == 0)
            k++;
        else
            sum = sum + list[i]->getavg();
    }
    sum = sum / (list.size()-k);
    return sum;
}

double Group::getavg2() const {
    double sum = 0;
    int n = 0;
    for(int i=0; i < list.size(); i++) {
        for (int j = 0; j < list[i]->getnum(); j++)
            sum = sum + (list[i]->getmarks())[j];
        n = n + (list[i]->getmarks()).size();
    }
    sum = sum / n;
    return sum;
}

void Group::exclude(Student* st) {
    int k = this->search_(st->getd());
    if(head != list[k]) {
        list.erase(list.begin() + k);
    }
    else
        list.erase(list.begin() + k);
        voting();
}

Student* Group::get_head() const{
    return head;

}




Deanery::Deanery(string input) {
    ifstream file(input);
    if (file.is_open()) {

        int id = 0;
        string group = "";
        string name = "";
        string buf = "";
        vector <int> marks;
        int len;
        int c = 0;
        while (getline(file, buf)) {
            len = buf.size();
            //cout << buf << endl;
            group = group_pars(buf);
            name = name_pars(buf);
            id = id_pars(buf);
            marks = marks_pars(buf);
            Group *tmp = new Group(group);
            int cur = -1;
            for (int i = 0; i < groups.size(); i++) {
                if (groups[i]->get_tittle() == group) {
                    tmp = groups[i];
                    cur = 0;
                    //cout << "fuck yeah";
                    break;
                }
            }
            if (cur == -1)
                groups.push_back(tmp);

            if (buf[0] == 'h' || buf[0] == 'H')
                students.push_back(new Student(id, name, tmp, 1));
            else
                students.push_back(new Student(id, name, tmp));
            for(int i = 0; i < marks.size(); i++)
            students[students.size()-1]->addmark(marks[i]);
            marks.clear();

        }

    }
    file.close();
}

void Deanery::print_groups() const {
    cout << "Groups:" << endl;
    for(int i =0; i < groups.size(); i++) {
        cout << groups[i]->get_tittle();
        cout << endl;
    }
    cout << endl;
}

void Deanery::print_students() const {
    cout << "Students:" << endl;
    for(int i =0; i < students.size(); i++) {
        cout << students[i]->getfio() << " ";
        cout << endl;
    }
    cout << endl;
}

size_t Deanery::get_numOFgroups() const {
    return groups.size();
}
size_t Deanery::get_numOFst() const {
    return students.size();
}

vector<unsigned int> Deanery::get_marks(int id) const {
    bool k = 1;
    int i = 0, count = 0;
    vector <unsigned int> ans;
    while(k){
        if(students[i]->getd()==id){
            return students[i]->getmarks();
        }
        i++;
    }
}

vector <unsigned int> Deanery::get_marks2(int num) const{
    return students[num]->getmarks();
}


void Deanery::exclude(int id) {
    for(int i = 0; i < students.size();i++){
        if(students[i]->getd()==id){
            students[i]->getgroup()->exclude(students[i]);
            delete students[i];
            students.erase(students.begin()+i);
        }
    }
}


void Deanery::auto_exclude() {
    for(int i = 0; i < students.size();i++){
            if(students[i]->getavg() < 4 && students[i]->getavg() != -1) {
                students[i]->getgroup()->exclude(students[i]);
                delete students[i];
                students.erase(students.begin() + i);
            }
    }
    for(int i = 0; i < students.size();i++){
        cout <<i<<": "<< students[i]->getfio()  << endl;
    }
}



void Deanery::voting(string gr) {
    for(int i = 0; i < groups.size();i++){
        if(groups[i]->get_tittle()==gr)
            groups[i]->voting();
    }
}

void Deanery::transfer(int id, string gr2) {
    for(int j = 0; j < groups.size();j++)
        if(groups[j]->get_tittle()==gr2)
            for(int k = 0; k < students.size(); k++)
                if(students[k]->getd()==id){
                    (students[k]->getgroup())->exclude(students[k]);
                            students[k]->attend(groups[j]);
                        }

}



void Deanery::refresh_file(string output) const {
    //ofstream file;
    string tmp ="";
    vector <unsigned int> marks;
    //file.open(output);
    fout.clear();
    for(int i = 0; i < students.size(); i++){
        marks = students[i]->getmarks();
        for(int j = 0; j < marks.size();j++){
            tmp = tmp + to_string(marks[j]) + " ";
        }
        fout << "Group: " << students[i]->getgroup()->get_tittle() << " id: " << students[i]->getd()
             << " FIO: " << students[i]->getfio() << " Marks: " <<tmp << "\n";
        tmp = "";
        cout << "written" <<i ;
    }
    for(int i = 0; i < groups.size(); i++) {
        groups[i]->voting();
        fout << "Head of group " << groups[i]->get_tittle() << ": " << groups[i]->get_head()->getfio() << "\n";
    }

    fout.close();
    //cout << "written";
}

void Deanery::add_random_marks() const {
    random_device ran;
    for(int i = 0; i < students.size();i++)
        for(int k=0; k < (ran() % 10 + 1 ); k++)
            students[i]->addmark(ran() % 10 + 1 );
}















int after_space( string & buf,int cur_iter, int space_num) {
    for (int i = 0; i < space_num; i++) {
        while (' ' != buf[cur_iter])
            cur_iter++;
        cur_iter++;
    }
    return cur_iter;
}

int after_space( string buf, int space_num) {
    int k = 0;
    for (int i = 0; i < space_num; i++) {
        while (' ' != buf[k])
            k++;
        k++;
    }
    return k;
}

string name_pars(string & buf){
        int k = 0;
        string name;
        for(int i = 0; i < buf.size(); i++)
            if(check_fio(buf,i)) {
                k = i;
                break;
            }
        if(buf[k+3]==':')
            k += 4;
        else
            k += 3;

        while (buf[k]==' ')
            k++;


        for(int i = k;i < buf.size(); i++)
            if(check_marks(buf,i+1) || (buf[i]==' ' && buf[i+1]==' ' && i < buf.size() -2))
                i = buf.size() - 1;
            else
                name += buf[i];
        return name;
}


string group_pars(string & buf){
    int k = 0;
    string name;
    for(int i = 0; i < buf.size(); i++)
        if(check_group(buf,i)) {
            k = i;
            break;
        }
    if(buf[k+5]==':')
        k += 6;
    else
        k += 5;

    while (buf[k]==' ')
        k++;


    for(int i = k;i < buf.size(); i++)
        if(check_fio(buf,i+1) || (check_id(buf, i+1)))
            i = buf.size() - 1;
        else
            name += buf[i];
    return name;
}



int id_pars(string & buf){
    int k = 0;
    string name;
    for(int i = 0; i < buf.size(); i++)
        if(check_id(buf,i)) {
            k = i;
            break;
        }
    if(buf[k+2]==':')
        k += 3;
    else
        k += 2;

    while (buf[k]==' ')
        k++;


    for(int i = k;i < buf.size(); i++)
        if(check_fio(buf,i+1) || (check_id(buf, i+1)))
            i = buf.size() - 1;
        else
            name += buf[i];
    k = 0;
    for( int i = 0; i < name.size(); i++)
         k = 10*k +((int)(name[i]) - '0');
    return k;
}


vector <int> marks_pars(string & buf){
    int k = 0, tmp;
    vector <int> ans;
    for(int i = 0; i < buf.size(); i++)
        if(check_marks(buf,i)) {
            k = i;
            break;
        }
    if(buf[k+5]==':')
        k += 6;
    else
        k += 5;

    while (buf[k]==' ')
        k++;


    for(int i = k;i < buf.size();){
        tmp =0;
        while (buf[i]!=' ' && i < buf.size()) {
            tmp = 10 * tmp + ((buf[i]) - '0');
            i++;
        }
            ans.push_back(tmp);
        while (buf[i]==' ')
            i++;

    }
    return ans;
}



bool check_fio(string & buf,int cur_iter){
    int i = cur_iter;
    if((buf[i]=='f' || buf[i]=='F') && (buf[i+1]=='i' || buf[i+1]=='I') && (buf[i+2]=='o' || buf[i+2]=='O'))
        return true;
    else
        return false;
}

bool check_id(string & buf,int cur_iter){
    int i = cur_iter;
    if((buf[i]=='I' || buf[i]=='i') && (buf[i+1]=='d' || buf[i+1]=='D'))
        return true;
    else
        return false;
}

bool check_group(string & buf,int cur_iter){
    int i = cur_iter;
    if((buf[i]=='g' || buf[i]=='G') && (buf[i+1]=='r' || buf[i+1]=='R')
    && (buf[i+2]=='o' || buf[i+2]=='O')&& (buf[i+3]=='u' || buf[i+3]=='U')
                                          && (buf[i+4]=='p' || buf[i+4]=='P'))
        return true;
    else
        return false;
}

bool check_marks(string & buf,int cur_iter){
    int i = cur_iter;
    if((buf[i]=='m' || buf[i]=='M') && (buf[i+1]=='a' || buf[i+1]=='A') && (buf[i+2]=='r' || buf[i+2]=='R')
    && (buf[i+3]=='k' || buf[i+3]=='K') && (buf[i+4]=='s' || buf[i+4]=='S'))
        return true;
    else
        return false;
}