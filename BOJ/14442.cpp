#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t;  // X Y wallBreaking
#define X get<0>
#define Y get<1>
#define B get<2>
int N, M, K, tX, tY, cB, loop, depth = 1, found = false, board[1005][1005], visited[11][1005][1005] = {0};  // 1-indexed X & Y, visited[TNoWallBreaking][Y][X]
string in;
queue<t> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> K;  // Cheese, N is col and M is row now! It's sucks;

    if (N + M == 2) {
        cout << 1;
        return 0;
    }

    for (int n = 1; n <= N; n++) {
        cin >> in;
        for (int m = 1; m <= M; m++) {
            board[n][m] = in[m-1] - '0';
        }
    }

    q.emplace(1, 1, 0);
    visited[0][1][1] = 1;
    while(!q.empty() && !found) {
        depth++;
        loop = q.size();
        for (int l = 0; l < loop && !found; l++) {
            cB = B(q.front());
            for (int i = 0; i < 4; i++) {
                tX = X(q.front()) + maskX[i];
                tY = Y(q.front()) + maskY[i];
                if (tX <= 0 || tY <= 0 || tX > M || tY > N || visited[cB][tY][tX]) continue;
                if (board[tY][tX] == 1) {
                    if (cB >= K || visited[cB+1][tY][tX]) continue;
                    q.emplace(tX, tY, cB + 1);
                    visited[cB + 1][tY][tX] = depth;
                } else {
                    q.emplace(tX, tY, cB);
                    visited[cB][tY][tX] = depth;
                }
                if (tX == M && tY == N) {
                    found = true;
                    break;
                }
            }
            q.pop();
        }
    }
    cout << (found ? depth : -1);
}