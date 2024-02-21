#include <bits/stdc++.h>
using namespace std;
int N, M, n[8], comb[8];
bool lockN[8] = {false};

void rec(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            cout << comb[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = 0; i < N && !lockN[i]; ++i) {
        if (lockN[i]) continue;
        comb[depth] = n[i];
        lockN[i] = true;
        rec(depth+1);
        lockN[i] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> n[i];
    }
    sort(n, n+N);
    rec(0);
}