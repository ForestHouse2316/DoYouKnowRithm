#include <bits/stdc++.h>
using namespace std;

int N;
int arr[1000000];
int merged[1000000];

void merge(int s, int e) {  // s <= iA < m, m <= iB < e
    int m = (s+e)/2;
    int iA = s, iB = m;
    for (int i = 0; i < e-s; i++) {
        if (arr[iA] < arr[iB]) merged[i] = arr[iA++];
        else merged[i] = arr[iB++];
        if (iA == m) {
            while (i < e-s) {
                merged[++i] = arr[iB++];
            }
        }
        else if (iB == e) {
            while (i < e-s) {
                merged[++i] = arr[iA++];
            }
        }
    }
    for (int i = 0; i < e-s; i++) {
        arr[s+i] = merged[i];
    }
}

void mergeSort(int s, int e) {  // s <= ARR < e
    switch (e-s) {
        case 2:
            merge(s, e);
        case 1:
            return;
    }
    int m = (s+e)/2;
    mergeSort(s, m);
    mergeSort(m, e);
    merge(s, e);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int i;
    for (int n = 0; n < N; n++) {
        cin >> i;
        arr[n] = i;
    }
    mergeSort(0, N);

    for (int n = 0; n < N; n++) {
        cout << arr[n] << " ";
    }
}