#include "iostream"

using namespace std;

#ifndef DS_ASSIGNMENT_STUDENT_H
#define DS_ASSIGNMENT_STUDENT_H

class Student {
    string id;
    string name;
    double gpa;
public:
    Student(string id, string name, double gpa);

    bool operator<(Student &s2);
};


#endif //DS_ASSIGNMENT_STUDENT_H
