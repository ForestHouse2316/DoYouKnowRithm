#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef pair<int, int> pii;

int N, M, K, in, ax, ay, bx, by;
ull psum[1025][1025] = {0}; // 1-indexed

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int n = 1; n <= N; ++n) {
        for (int m = 1; m <= M; ++m) {
            cin >> in;
            psum[n][m] = in + psum[n-1][m] + psum[n][m-1] - psum[n-1][m-1];
        }
    }

    cin >> K;
    while (K--) {
        cin >> ay >> ax >> by >> bx;
        cout << psum[by][bx] + psum[ay-1][ax-1] - psum[ay-1][bx] - psum[by][ax-1] << "\n";
    }
}