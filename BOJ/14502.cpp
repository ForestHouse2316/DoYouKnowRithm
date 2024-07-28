#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N, M, board[8][8], maxEmt = 0, comb[64] = {0}, result = 0, tx, ty;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
vector<pii> candidates, virus;
bool vis[8][8];

int bfs() {
    for (auto & v : vis) fill(v, v + 8, false);
    int curEmt = maxEmt;
    queue<pii> q;
    for (auto p : virus) {
        q.push(p);
        vis[p.Y][p.X] = true;
    }

    while (!q.empty()) {
        for (int i = 0; i < 4; ++i) {
            tx = q.front().X + dx[i];
            ty = q.front().Y + dy[i];
            if (tx < 0 || ty < 0 || tx >= M || ty >= N || vis[ty][tx] || board[ty][tx] != 0) continue;

            vis[ty][tx] = true;
            curEmt--;
            q.emplace(tx, ty);
        }
        q.pop();
    }

    return curEmt;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> board[n][m];
            if (board[n][m] == 0) {
                maxEmt++;
                candidates.emplace_back(m, n);
            }
            else if (board[n][m] == 2) virus.emplace_back(m, n);
        }
    }
    maxEmt -= 3; // wall
    int numCand = candidates.size();
    fill(comb+3, comb + numCand, 1);
    do {
        for (int i = 0; i < numCand; ++i) if (comb[i] == 0) board[candidates[i].Y][candidates[i].X] = 1; // set wall
        result = max(result, bfs());
        for (int i = 0; i < numCand; ++i) if (comb[i] == 0) board[candidates[i].Y][candidates[i].X] = 0; // remove wall
    } while (next_permutation(comb, comb + numCand));

    cout << result;
}