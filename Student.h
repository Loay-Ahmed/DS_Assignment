#include "iostream"

using namespace std;

#ifndef DS_ASSIGNMENT_STUDENT_H
#define DS_ASSIGNMENT_STUDENT_H

class Student {
    string id;
    string name;
    double gpa;
public:
    explicit Student(string Name="", string ID="", double GPA=0);

    bool operator<(Student &s2);
};


#endif //DS_ASSIGNMENT_STUDENT_H
