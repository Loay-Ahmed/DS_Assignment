#include <bits/stdc++.h>

using namespace std;

template<class T>
void InsertionSort(T arr[], int s, int n) {
    for (int i = s+1; i < n; i++) {
        T temp = arr[i];
        for (int j = i - 1; j >= 0; j--) {
            if (temp < arr[j]) {
                swap(arr[j + 1], arr[j]);
            }
        }
    }
}
