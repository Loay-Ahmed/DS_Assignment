#include <iostream>
#include <fstream>
#include <string>
#include "vector"
#include "Student.h"

using namespace std;

vector<Student *> readFromFile(basic_ifstream<char> &file) {
    string line, name, id;
    int n;
    double gpa;
    (file >> n) ? cout << n << endl : cout << "Can't read int";
    vector<Student *> students;
    for (int i = 0; i < n; i++) {
        file.ignore();
        getline(file, name);
        getline(file, id);
        (file >> gpa) ? cout << "" : cout << "Can't read double";
        students.push_back(new Student(name, id, gpa));
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
    vector<Student *> students = readFromFile(file);
    Student arr[students.size()] = [students]() { for (int i = 0; i < students.size(); i++){return students[i]}}();
    return 0;
}
