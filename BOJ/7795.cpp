#include <bits/stdc++.h>
using namespace std;

int T, N, M, A[20000], B[20000], total, compIdx;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N >> M;
        for (int n = 0; n < N; ++n) {
            cin >> A[n];
        }
        for (int m = 0; m < M; ++m) {
            cin >> B[m];
        }

        total = 0; compIdx = 0;
        sort(A, A+N); sort(B, B+M);
        for (int n = 0; n < N; ++n) {
            while (A[n] > B[compIdx] && compIdx < M) {
                total += N-n;
                compIdx++;
            }
        }
        cout << total << '\n';
    }
}