// Copyright 2021 Igumnova Natasha
#include "Data.h"

std::vector<std::string> read_data(std::string filename) {
    std::string line;
    std::vector<std::string> buff;
    std::ifstream fin(filename);
    while (getline(fin, line)) {
        buff.push_back(line);
    }
    fin.close();
    return buff;
}
std::vector<int> getmarks(std::string buff) {
    std::vector<int> marks;
    int i = buff.find('-') + 2;
    std::cout << i << '\n';
    while (buff[i] != ';') {
        if (buff[i] != ',')
            marks.push_back((buff[i] - '0'));
        i += 1;
    }
    return marks;
}
std::string join(std::vector<int> mk) {
    std::string res;
    for (int i = 0; i < mk.size(); i++) {
        res = res + std::to_string(mk[i]) + ',';
    }
    return res + ';';
}
std::string getfio(std::string buff) {
    std::string fio;
    int ind = buff.find(" - ");
    fio = buff.substr(4, ind - 4);
    return fio;
}
int getid(std::string buff) {
    std::string id;
    int ind = 0;
    for (int i = 0; i < buff.size(); i++) {
        if (isspace(buff[i])) {
            ind = i;
            break;
        }
    }
    id = buff.substr(0, ind);
    return (std::stoi(id));
}
void write_data(std::string filename, std::string data) {
    std::ofstream out;
    out.open(filename);
    if (out.is_open()) {
        out << data << std::endl;
    }
}
