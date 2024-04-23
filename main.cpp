#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string readFromFile(basic_ifstream<char>& file);

int main() {
    ifstream file("G:student.txt");
    if (!file.is_open()) {
        cerr << "Can't open the file\n";
        return -1;
    }
    readFromFile(file);
    return 0;
}

string readFromFile(basic_ifstream<char>& file) {
    string line, name, id;
    int n;
    double gpa;
    (file >> n) ? cout << n << endl : cout << "Can't read double";
    for (int i = 0; i < n; i++) {
        file.ignore();
        getline(file, name);
        cout << name << " ";
        getline(file, id);
        cout << id << " ";
        (file >> gpa) ? cout << gpa : cout << "Can't read double";
        cout << endl;
    }
    return "";
}

