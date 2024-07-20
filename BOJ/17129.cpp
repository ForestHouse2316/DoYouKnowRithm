#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

queue<pii> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int N, M, board[3000][3000], tx, ty, dist = 0, loop;
bool vis[3000][3000];
string in;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int n = 0; n < N; ++n) {
        cin >> in;
        for (int m = 0; m < M; ++m) {
            board[n][m] = in[m]-'0';
            if (board[n][m] == 2) {
                q.emplace(m, n);
                vis[n][m] = true;
            }
        }
    }

    while (!q.empty()) {
        loop = q.size();
        dist++;
        while (loop--) {
            for (int i = 0; i < 4; ++i) {
                tx = q.front().X + dx[i];
                ty = q.front().Y + dy[i];
                if (tx < 0 || ty < 0 || tx >= M || ty >= N || vis[ty][tx] || board[ty][tx] == 1) continue;

                if (board[ty][tx] != 0) {
                    cout << "TAK\n" << dist;
                    return 0;
                }
                vis[ty][tx] = true;
                q.emplace(tx, ty);
            }
            q.pop();
        }
    }
    cout << "NIE";
}