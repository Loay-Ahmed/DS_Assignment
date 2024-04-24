#include "Student.h"

#include <utility>

Student::Student(string Name, string ID, double GPA) : name(std::move(Name)), id(std::move(ID)), gpa(GPA) {}

bool Student::operator<(Student &s2) {
    return false;
}
