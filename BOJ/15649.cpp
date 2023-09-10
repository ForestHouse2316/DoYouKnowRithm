#include <bits/stdc++.h>
using namespace std;

int N, M;
int accumulated[10] = {0};
bool isUsing[10] = {false};

void backtracking(int depth) {
    if (depth == M) {
        for (int i = 0; i < M; i++) {
            cout << accumulated[i] << ' ';
        }
        cout << '\n';
        return;
    }

    for (int i = 1; i <= N; i++) {
        if (!isUsing[i]) {
            accumulated[depth] = i;
            isUsing[i] = true;
            backtracking(depth+1);
            isUsing[i] = false;
        }
    }
}

int main() {
    cin >> N; cin >> M;
    backtracking(0);
}