#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> tiii;
queue<tiii> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int N, M, K, sx, sy, ex, ey, vis[1002][1002], ty, tx, cx, cy, ct, interval;
bool wall[1003][1003];
char in;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> K;

    for (int n = 0; n < N; ++n) {
        fill(vis[n], vis[n]+M, -1);
        for (int m = 0; m < M; ++m) {
            cin >> in;
            wall[n][m] = in == '#';
        }
    }


    cin >> sy >> sx >> ey >> ex; // because X is a row in this problem, swap the position of X and Y. [N->Y] [M->X]
    sy--; sx--; ey--; ex--; // for 0-indexed array
    q.emplace(sx, sy, 0);
    vis[sy][sx] = 0;
    while (!q.empty()) {
        tie(cx, cy, ct) = q.front();
        q.pop();
        if (ct != vis[cy][cx]) continue; // Replaced by the faster route, so discard this route. But not a necessary job, just for an optimization.

        for (int i = 0; i < 4; ++i) {
            for (int k = 1; k <= K; ++k) {
                tx = cx + dx[i] * k;
                ty = cy + dy[i] * k;
                if (tx < 0 || ty < 0 || tx >= M || ty >= N || wall[ty][tx]) break; // next direction
                if (vis[ty][tx] != -1) {
                    interval = vis[cy][cx]+1 - vis[ty][tx];
                    if (interval == 0) continue; // next multiple (next tile)
                    else if (interval > 0) break; // next direction
                }

                vis[ty][tx] = vis[cy][cx] + 1;
                q.emplace(tx, ty, ct + 1);
            }
        }
    }

    cout << vis[ey][ex];
}