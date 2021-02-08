all:
	g++ include/Student.h include/Group.h include/Deanary.h src/Student.cpp src/Group.cpp src/Deanary.cpp src/main.cpp -o main -std=c++17;
	./main;