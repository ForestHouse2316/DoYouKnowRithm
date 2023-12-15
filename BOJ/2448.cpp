#include <bits/stdc++.h>
using namespace std;
int N, H, K;
bool board[3100][6200] = {false};

void tri(int depth, int tx, int ty) {
    if (depth == 0) {
        board[ty][tx] = true;
        board[ty+1][tx-1] = true;
        board[ty+1][tx+1] = true;
        for (int b = -2; b <= 2; ++b) {
            board[ty+2][tx+b] = true;
        }
        return;
    }

    int b = 3*pow(2, depth-1);
    tri(depth-1, tx, ty);
    tri(depth-1, tx - b, ty + b);
    tri(depth-1, tx + b, ty + b);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    H = N/3;
    K = log2(H);
    tri(K, N-1, 0);
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < H*6-1; ++m) {
            cout << (board[n][m] ? "*" : " ");
        }
        if (n != N-1) cout << '\n';
    }
}