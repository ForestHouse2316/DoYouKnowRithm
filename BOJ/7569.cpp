#include <bits/stdc++.h>
using namespace std;
#define x get<0>(q.front())
#define y get<1>(q.front())
#define z get<2>(q.front())
typedef tuple<int, int, int> piii;
int M, N, H, num = 0, ripen = 0, board[102][102][102], loop, times = 0, tx, ty, tz;
queue<piii> q;
int dx[] = {0, 1, 0, -1, 0, 0},
    dy[] = {1, 0, -1, 0, 0, 0},
    dz[] = {0, 0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N >> H;
    for (int h = 0; h < H; ++h) {
        for (int n = 0; n < N; ++n) {
            for (int m = 0; m < M; ++m) {
                cin >> board[h][n][m];
                if (board[h][n][m] != -1) {
                    num++;
                    if (board[h][n][m] == 1) {
                        ripen++;
                        q.emplace(m, n, h);
                    }
                }
            }
        }
    }

    while (num != ripen && !q.empty()) {
        times++;
        loop = q.size();
        while (loop--) {
            for (int i = 0; i < 6; ++i) {
                tx = x + dx[i]; ty = y + dy[i]; tz = z + dz[i];
                if (tx < 0 || ty < 0 || tz < 0 || tx >= M || ty >= N || tz >= H || board[tz][ty][tx] != 0) continue;

                board[tz][ty][tx] = 1;
                ripen++;
                q.emplace(tx, ty, tz);
            }
            q.pop();
        }
    }

    cout << (num == ripen ? times : -1);
}