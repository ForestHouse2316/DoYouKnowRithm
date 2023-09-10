#include <bits/stdc++.h>
using namespace std;
int N;
int times[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    times[0] = 9;
    times[1] = 0;
    for (int n = 2; n <= N; n++) {
        times[n] = times[n-1];
        if (n%2 == 0) times[n] = min(times[n], times[n/2]);
        if (n%3 == 0) times[n] = min(times[n], times[n/3]);
        times[n]++;
    }
    cout << times[N];
}