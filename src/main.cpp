#include "json.hpp"
#include "iostream"
#include "json.h"
#include "fstream"
#include "vector"
#include "Student.h"
#include "Deanary.h"

using json = nlohmann::json;

int main() {
	Deanary HSE;
	HSE.addMarksToAll(2);
	std::string str = "English Languages";
	HSE.moveStudents(1, str);
	HSE.fireStudents(1);
}