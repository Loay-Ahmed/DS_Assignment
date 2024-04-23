#include <bits/stdc++.h>

using namespace std;

template<class T>
void SelectionSort(T arr[], const int n) {
    for (int i = 0; i < n - 1; i++) {
        int min = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        if (min != i) swap(arr[min], arr[i]);
    }
}
