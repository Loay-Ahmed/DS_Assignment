#include <bits/stdc++.h>

using namespace std;

template<class T>
void BubbleSort(T arr[], int, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j + 1] < arr[j]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}
