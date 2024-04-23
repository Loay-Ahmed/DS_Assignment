#include "Student.h"

Student::Student(string name, string id, double gpa) {
    this->id = id;
    this->name = name;
    this->gpa = gpa;
}

bool Student::operator<(Student &s2) {
    return false;
}
