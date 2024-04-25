#include "iostream"

using namespace std;

#ifndef DS_ASSIGNMENT_STUDENT_H
#define DS_ASSIGNMENT_STUDENT_H

class Student {
    string id;
    string name;
    double gpa;
public:
    explicit Student(string Name = "", string ID = "", double GPA = 0);

    string Name() const;

    string ID() const;

    double GPA() const;

    bool operator<(const Student &other) const;
};


#endif //DS_ASSIGNMENT_STUDENT_H
