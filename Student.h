#ifndef STUDENT_H
#define STUDENT_H

#include <string>
using namespace std;

class Student {
private:
    string name;
    string studentId;

public:
    Student();
    Student(const string& name, const string& studentId);
    ~Student();

    void setDetails(const string& name, const string& studentId);
    string getName() const;
    string getStudentId() const;
    bool isEmpty() const;
    void display() const;
};

#endif
