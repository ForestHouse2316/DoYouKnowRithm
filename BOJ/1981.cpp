#include <bits/stdc++.h>
using namespace std;
#define f q.front()
#define x first
#define y second
typedef pair<int, int> p;
int N, b, t, m, tx, ty, result, gap, board[102][102], s, e, hc, minGap = INT_MAX, mi = INT_MAX, mx = 0;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
bool vis[102][102];

bool bfs(int top, int bottom) {
    if (board[0][0] > top || board[0][0] < bottom) return false;
    if (board[N-1][N-1] > top || board[N-1][N-1] < bottom) return false;

    for (int i = 0; i < 102; ++i) {
        fill(vis[i], vis[i] + 102, false);
    }
    queue<p> q;
    q.emplace(0, 0);
    vis[0][0] = true;
    while (!q.empty()) {
        for (int i = 0; i < 4; ++i) {
            tx = f.x + dx[i];
            ty = f.y + dy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N || vis[ty][tx]) continue;
            vis[ty][tx] = true;
            if (board[ty][tx] > top || board[ty][tx] < bottom) continue;
            if (tx == N-1 && ty == N-1) return true;
            q.emplace(tx, ty);
        }
        q.pop();
    }
    return false;
}

int fixedBottom(int bottom) {  // returns tightened top
    b = bottom; t = mx;
    result = -1;
    while (b <= t) {
        m = (b + t) / 2;
        if (bfs(m, bottom)) {
            result = m;
            t = m - 1;
        }
        else b = m + 1;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cin >> board[row][col];
            mx = max(mx, board[row][col]);
            mi = min(mi, board[row][col]);
        }
    }

    minGap = mx-mi;
    for (int lc = mi; lc <= mx; ++lc) {
        hc = fixedBottom(lc);
        if (hc == -1) break;
        gap = hc - lc;
        if (gap < minGap) minGap = gap;
    }

    cout << minGap;
}