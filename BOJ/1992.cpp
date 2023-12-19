#include <bits/stdc++.h>
using namespace std;
int N, board[65][65];
string in;

void comp(int ax, int ay, int bx, int by) {
    int target = board[ay][ax];
    for (int r = ay; r < by; ++r) {
        for (int c = ax; c < bx; ++c) {
            if (target != board[r][c]) {
                int half = (bx-ax)/2;
                cout << '(';
                for (int ty : {ay, ay+half}) {
                    for (int tx : {ax, ax+half}) {
                        comp(tx, ty, tx+half, ty+half);
                    }
                }
                cout << ')';
                return;
            }
        }
    }
    cout << target;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int r = 0; r < N; ++r) {
        cin >> in;
        for (int c = 0; c < N; ++c) {
            board[r][c] = in[c]-'0';
        }
    }
    comp(0, 0, N, N);
}