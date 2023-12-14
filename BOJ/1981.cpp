#include <bits/stdc++.h>
using namespace std;
#define x(a) get<0>(a)
#define y(a) get<1>(a)
#define h(a) get<2>(a)
#define l(a) get<3>(a)
#define f q.front()
typedef tuple<int, int, int, int> ti;
int N, s, e, m, tx, ty, th, tl, board[102][102], mx = 0, minGap, cycle;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int vis[102][102];

// 최대값과 최소값을 고정해보자! 그것도 bin search로
bool bfs(int limit) {
    for (int i = 0; i < 102; ++i) {
        fill(vis[i], vis[i] + 102, INT_MAX);
    }
    queue<ti> q;
    q.emplace(0, 0, board[0][0], board[0][0]);
    // TODO set visit on starting point as true
    while (!q.empty()) {
        cycle++;
        for (int i = 0; i < 4; ++i) {
            tx = x(f) + dx[i];
            ty = y(f) + dy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N) continue;
            th = max(h(f), board[ty][tx]);
            tl = min(l(f), board[ty][tx]);
            if (vis[ty][tx] <= th - tl) continue;
            vis[ty][tx] = th-tl;
//            cout << "On " << tx << "-" << ty << " : diff = " << th-tl << endl;
            if (th-tl > limit) continue;
            if (tx == N-1 && ty == N-1) return true;
            q.emplace(tx, ty, th, tl);
        }
        q.pop();
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int row = 0; row < N; ++row) {
        for (int col = 0; col < N; ++col) {
            cin >> board[row][col];
            mx = max(mx, board[row][col]);
        }
    }
    s = abs(board[0][0] - board[N-1][N-1]);
    e = mx;
    while (s <= e) {
        m = (s+e)/2;
        cout << "trying : " << m << endl;
        if (bfs(m)) {
            minGap = m;
            e = m-1;
        }
        else s = m+1;
    }
    cout << minGap;
}