#include <bits/stdc++.h>
using namespace std;

int N, M, c[8] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    fill(c+M, c+8, 1);
    do {
        for (int i = 0; i < N; ++i) {
            if (!c[i]) cout << i+1 << " ";
        }
        cout << '\n';
    } while (next_permutation(c, c+N));
}