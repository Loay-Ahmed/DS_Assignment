#include <iostream>
#include <fstream>
#include <string>
#include "Student.h"

using namespace std;

Student* readFromFile(basic_ifstream<char> &file) {
    string line, name, id;
    int n;
    double gpa;
    (file >> n) ? cout << n << endl : cout << "Can't read int";
    Student students[n];
    for (int i = 0; i < n; i++) {
        file.ignore();
        getline(file, name);
        getline(file, id);
        (file >> gpa) ? cout << "" : cout << "Can't read double";
        students[i] = Student(name, id, gpa);
    }
    return students;
}

int main() {
    string filePath;
    cout << "Enter absolute path for students.txt: ";
    cin >> filePath;
    ifstream file(filePath);
    if (!file.is_open()) {
        cerr << "Can't open the file\n";
        return -1;
    }
    Student* students = readFromFile(file);

    return 0;
}
