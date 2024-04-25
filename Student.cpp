#include "Student.h"

#include <utility>

Student::Student(string Name, string ID, double GPA) : name(std::move(Name)), id(std::move(ID)), gpa(GPA) {}

bool Student::operator<(const Student &other) const {
    return false;
}

string Student::Name() const {
    return this->name;
}

string Student::ID() const {
    return id;
}

double Student::GPA() const {
    return gpa;
}
