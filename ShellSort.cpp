#include <bits/stdc++.h>

using namespace std;

template<class T>
void shellSort(T arr[], int, int size) {
    int n = size;

    for (int gap = n / 2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            T temp = arr[i];

            // swap if at j - gap less than at i and j (insertion sort for gapped elements)
            int j;
            for (j = i; j >= gap && temp < arr[j - gap]; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
        cout << endl;
    }
}
