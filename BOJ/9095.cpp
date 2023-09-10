#include <bits/stdc++.h>
using namespace std;
int T;
int N;
int times[12];
int calculated = 2;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    times[0] = times[1] = 1;
    for (int t = 0; t < T; t++) {
        cin >> N;
        for (int n = calculated; n <= N; n++) {
            times[n] = times[n-1];
            if (n >= 2) times[n] += times[n-2];
            if (n >= 3) times[n] += times[n-3];
        }
        cout << times[N] << "\n";
        calculated = max(calculated, N);
    }
}