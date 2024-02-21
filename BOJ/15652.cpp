#include <bits/stdc++.h>
using namespace std;
int N, M, comb[8];

void rec(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; ++i) {
            cout << comb[i] << " ";
        }
        cout << '\n';
        return;
    }
    for (int i = (depth==0 ? 1 : comb[depth-1]); i <= N; ++i) {
        comb[depth] = i;
        rec(depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    rec(0);
}