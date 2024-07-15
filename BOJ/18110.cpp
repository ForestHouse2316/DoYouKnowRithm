#include <bits/stdc++.h>
using namespace std;

int N, lvl[300005], sum = 0, cut;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    if (N == 0) {
        cout << 0;
        return 0;
    }
    for (int n = 0; n < N; ++n) {
        cin >> lvl[n];
    }

    sort(lvl, lvl+N);
    cut = (int) round(N * 0.15);
    for (int n = cut; n < N-cut; ++n) {
        sum += lvl[n];
    }

    cout << (int) round(sum / (double) (N-cut-cut));
}