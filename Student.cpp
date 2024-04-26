#include "Student.h"

#include <utility>

Student::Student(string name, string id, double gpa) : name(std::move(name)), id(std::move(id)), gpa(gpa) {}

bool Student::operator<(const Student &other) const {
    return this->name < other.name;
}

string Student::Name() {
    return this->name;
}

string Student::ID() {
    return id;
}

double Student::GPA() const {
    return gpa;
}
