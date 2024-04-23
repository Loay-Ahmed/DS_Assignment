#include "iostream"
using namespace std;

#ifndef DS_ASSIGNMENT_STUDENT_H
#define DS_ASSIGNMENT_STUDENT_H

/*
 1. Implement the student class with its constructor. [ Done ]
 2. Overload the operator < such that it compares the names of two student objects.
 3. Read student objects from a file named students.txt
 */

class Student {
    string id;
    string name;
    double gpa;
public:
    Student(string id, string name, double gpa);
    bool operator<(Student& s2);
};


#endif //DS_ASSIGNMENT_STUDENT_H
