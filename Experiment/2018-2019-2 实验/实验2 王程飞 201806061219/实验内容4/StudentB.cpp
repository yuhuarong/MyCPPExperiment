#include "StudentB.h"
#include<iostream>
using namespace std;

StudentB::StudentB() {
	name = new char[100];
	name[0] = '\0';
}

StudentB::StudentB(const char n[]) {
	name = new char[100];
	int i;
	for (i = 0; n[i] != '\0'; i++) {
		name[i] = n[i];
	}
	name[i] = '\0';
}

StudentB::StudentB(const StudentB & stu) {
	name = new char[100];
	int i;
	char *n = stu.getName();
	for (i = 0; n[i] != '\0'; i++) {
		name[i] = n[i];
	}
	name[i] = '\0';
}

char* StudentB::getName() const {
	return name;
}

void StudentB::operator=(const StudentB& stu) {
	int i;
	char *n = stu.getName();
	for (i = 0; n[i] != '\0'; i++) {
		name[i] = n[i];
	}
	name[i] = '\0';
}

void StudentB::changeName(const char n[]) {
	int i;
	for (i = 0; n[i] != '\0'; i++) {
		name[i] = n[i];
	}
	name[i] = '\0';
}

StudentB::~StudentB() {
	cout << "Îö¹¹ " << getName() << endl;
	delete[]name;
}
