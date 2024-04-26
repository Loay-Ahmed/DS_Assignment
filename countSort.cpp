#include <bits/stdc++.h>

using namespace std;

template <class T>

void countSort(T arr[], int x, int n) {
    if (n == 0) return;

    map<T, int> count;

    for (int i = 0; i < n; ++i) {
        count[arr[i]]++;
    }
    int index = 0;
    for (auto& pair : count) {
        while (pair.second > 0) {
            arr[index++] = pair.first;
            pair.second--;
        }
    }
}
