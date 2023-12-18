#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef pair<int, int> p;
queue<p> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int N, target, board[2200][2200], cnt[3] = {0};  // 3^7 = 2187

void cutter(int ax, int ay, int bx, int by) {
    target = board[ay][ax];
    for (int r = ay; r < by; ++r) {
        for (int c = ax; c < bx; ++c) {
            if (board[r][c] != target) {
                if (bx - ax < 3) return;
                int cutSize = (bx-ax)/3;
                for (int v = ay; v < by; v += cutSize) {
                    for (int h = ax; h < bx; h += cutSize) {
                        cutter(h, v, h+cutSize, v+cutSize);
                    }
                }
                return;
            }
        }
    }
    cnt[target+1]++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> board[r][c];
        }
    }
    cutter(0, 0, N, N);
    for (int i : cnt) {
        cout << i << '\n';
    }
}