#include <bits/stdc++.h>
using namespace std;

int countArr[2000001] = {0};
const int M = 1000000;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;

    int i;
    for (int n = 0; n < N; n++) {
        cin >> i;
        countArr[M+i]++;
    }
    for (int n = 0; n < 2000001; n++) {
        for (int p = 0; p < countArr[n]; p++) {
            cout << n-M << "\n";
        }
    }
}