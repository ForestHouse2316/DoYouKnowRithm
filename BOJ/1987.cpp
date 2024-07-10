#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define a first
#define b second
typedef pair<int, int> pii;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int R, C, board[20][20], maxDist = 0;
char in;
bool vis[26] = {false};

void rec(int x, int y, int depth) {
    maxDist = max(maxDist, depth);
    for (int i = 0; i < 4; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || ty < 0 || tx >= C || ty >= R || vis[board[ty][tx]]) continue;

        vis[board[ty][tx]] = true;
        rec(tx, ty, depth+1);
        vis[board[ty][tx]] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> in;
            board[r][c] = in - 'A';
        }
    }

    vis[board[0][0]] = true;
    rec(0, 0, 1);
    cout << maxDist;
}