#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

// Function to measure running time of sorting algorithms
template<typename T>
long long measureTime(void (*sortingAlgorithm)(vector<T>&), vector<T>& arr) {
    auto start = high_resolution_clock::now();
    sortingAlgorithm(arr);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<milliseconds>(stop - start);
    return duration.count();
}

// Function to write sorting results to file
void writeToFile(const string& filename, const string& algorithmName, const Student* students, long long timeTaken) {
    ofstream file(filename, ios_base::app);
    file << "Algorithm: " << algorithmName << endl;
    file << "Running Time: " << timeTaken << " milliseconds" << endl;
    for (const auto& student : students) {
        file << student.name << endl;
        file << student.ID << endl;
        file << student.GPA << endl;
    }
    file << endl;
    file.close();
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
    Student* studentsByName = students;
     long long timeTaken;

    // Select and run sorting algorithms
    vector<string> sortingAlgorithms = {"Insertion Sort", "Selection Sort", "Bubble Sort", "Shell Sort", "Merge Sort", "Quick Sort", "Count Sort"};
    for (const auto& algorithm : sortingAlgorithms) {
        if (algorithm == "Quick Sort") {
            // Sort by name
            studentsByName = students;
            timeTaken = measureTime(&(quickSort)(students), studentsByName);
            writeToFile("SortedByName.txt", algorithm, studentsByName, timeTaken);

            // Sort by GPA
            Student* studentsByGPA = students;
            timeTaken = measureTime(&(quickSort)(students), studentsByGPA);
            writeToFile("SortedByGPA.txt", algorithm, studentsByGPA, timeTaken);
        } else {
            // Implement and call other sorting algorithms
            // You can reuse the existing code structure for other sorting algorithms
            // Just replace the quickSort function call with the corresponding sorting algorithm
        }
    }
    return 0;
}
