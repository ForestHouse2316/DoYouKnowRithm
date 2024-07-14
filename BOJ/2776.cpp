#include <bits/stdc++.h>
using namespace std;

int T, N, M, in;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        unordered_map<int, bool> um;
        cin >> N;
        for (int n = 0; n < N; ++n) {
            cin >> in;
            um[in] = true;
        }
        cin >> M;
        for (int m = 0; m < M; ++m) {
            cin >> in;
            cout << (um.find(in) != um.end() ? 1 : 0) << '\n';
        }
    }
}