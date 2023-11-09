// TODO 낮밤 바뀌며 제자리에 가만히 있는건 depth가 1 증가하면 되는 것이므로 pop 하고 다시 큐에 넣으면 되지 않을까? 한번 검토해보도록 하자.

#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t;  // X Y wallBreaking
#define X get<0>
#define Y get<1>
#define B get<2>
int N, M, K, tX, tY, cB, loop, depth = 1, breakingFailed = false, night = true, found = false, board[1005][1005], visited[11][1005][1005] = {0};  // 1-indexed X & Y, visited[TNoWallBreaking][Y][X]
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
        night = !night;  // day/night change
        for (int l = 0; l < loop && !found; l++) {
            cB = B(q.front());
            breakingFailed = false;
            for (int i = 0; i < 4; i++) {
                tX = X(q.front()) + maskX[i];
                tY = Y(q.front()) + maskY[i];
                if (tX <= 0 || tY <= 0 || tX > M || tY > N || visited[cB][tY][tX]) continue;
                if (board[tY][tX] == 1) {
                    if (cB >= K || visited[cB+1][tY][tX]) continue;
                    if (night) {
                        breakingFailed = true;
                        continue;
                    }
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
            if (breakingFailed) q.push(q.front());  // if player failed to break the wall due to time(night), then check again after an interval
            q.pop();
        }
    }
    cout << (found ? depth : -1);
}