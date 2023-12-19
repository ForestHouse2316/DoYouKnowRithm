#include <bits/stdc++.h>
using namespace std;
#define x first
#define y second
typedef pair<int, int> p;
queue<p> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int N, board[130][130], cnt[2] = {0};

void cutter(int ax, int ay, int bx, int by) {
    int target = board[ay][ax];
    for (int r = ay; r < by; ++r) {
        for (int c = ax; c < bx; ++c) {
            if (target != board[r][c]) {
                int half = (bx-ax)/2;
                if (!half) return;
                for (int ty : {ay, ay+half}) {
                    for (int tx : {ax, ax+half}) {
                        cutter(tx, ty, tx+half, ty+half);
                    }
                }
                return;
            }
        }
    }
    cnt[target]++;
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
    cout << cnt[0] << '\n' << cnt[1];
}