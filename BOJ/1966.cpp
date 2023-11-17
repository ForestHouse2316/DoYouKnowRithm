#include <bits/stdc++.h>
using namespace std;
int T, N, M, printed, front, docs[102], priority[12];  // 1-indexed (priority[10])

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        front = 0;
        printed = 0;
        fill(priority, priority+12, 0);
        cin >> N >> M;
        for (int n = 0; n < N; n++) {
            cin >> docs[n];
            priority[docs[n]]++;
        }

        for (int i = docs[M]+1; i <= 9; i++) {
            printed += priority[i];
        }

        for (int p = 9; p > docs[M]; p--) {
            while (priority[p]) {
                if (docs[front] == p) priority[p]--;
                front = (front+1)%N;
            }
        }
        for (int i = front; i != M; i = (i+1)%N) {
            if (docs[i] == docs[M]) printed++;
        }
        cout << printed+1 << '\n';
    }
}