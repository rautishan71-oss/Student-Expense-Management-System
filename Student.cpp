#include "Student.h"
#include <iostream>
using namespace std;

Student::Student() : name(""), studentId("") {}
Student::Student(const string& n, const string& id) : name(n), studentId(id) {}
Student::~Student() {}

void Student::setDetails(const string& n, const string& id) {
    name = n;
    studentId = id;
}
string Student::getName() const { return name; }
string Student::getStudentId() const { return studentId; }
bool Student::isEmpty() const { return name.empty() || studentId.empty(); }

void Student::display() const {
    if (isEmpty()) {
        cout << "Student details have not been saved yet.\n";
        return;
    }
    cout << "\n--- Student Information ---\n";
    cout << "Name      : " << name << "\n";
    cout << "Student ID: " << studentId << "\n";
}
