// Created by islam on 02.02.2021.

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "Reader.h"


void Reader::StudentsReader(std::string fileName) {
    std::string s = "";
    std::ifstream file(fileName);
    if (file.is_open()) {
        while (getline(file, s)) {
            if (s.find('*') == std::string::npos
                && s.find('#') == std::string::npos) {
                int i = 0;
                std::string nameBuf = "";
                std::string idBuf = "";
                bool two_dots = false;
                while (i < s.length()) {
                    while (s[i] != ':' && !two_dots) {
                        idBuf += s[i];
                        i++;
                    }
                    if (s[i] == ':') {
                        two_dots = true;
                        i++;
                    } else {
                        nameBuf += s[i];
                        i++;
                    }
                }
                std::pair<std::string, std::string> aPair;
                aPair.first = std::to_string(this->num_groups);
                aPair.second = nameBuf;
                this->names.push_back(aPair);
                aPair.second = idBuf;
                this->ids.push_back(aPair);
            } else if (s.find('*') == std::string::npos) {
                this->spec = s;
            } else {
                num_groups += 1;
            }
        }
    }
    file.close();
}

void Reader::GroupsReader(std::string fileName) {
    std::string s = "";
    std::ifstream file(fileName);
    if (file.is_open()) {
        std::string specBuf = "";
        while (getline(file, s)) {
            std::string titleBuf = "";
            if (s.find('#') == std::string::npos) {
                titleBuf = s;
                std::pair<std::string, std::string> aPair;
                aPair.first = specBuf;
                aPair.second = titleBuf;
                groups.push_back(aPair);
            } else {
                specBuf = s;
            }
        }
    }
}

void Reader::MarksReader(std::string fileName) {
    std::string s = "";
    std::ifstream file(fileName);
    if (file.is_open()) {
        while (getline(file, s)) {
            int i = 0;
            std::string markBuf = "";
            std::string idBuf = "";
            bool two_points = false;
            while (i < s.length() + 1) {
                while (s[i] != ':' && !two_points) {
                    idBuf += s[i];
                    i++;
                }
                if (s[i] == ':') {
                    two_points = true;
                    i++;
                } else {
                    markBuf += s[i];
                    i++;
                }
            }
            std::pair<std::string, std::string> aPair;
            aPair.first = idBuf;
            aPair.second = markBuf;
            this->marks.push_back(aPair);
        }
    }
    file.close();
}
