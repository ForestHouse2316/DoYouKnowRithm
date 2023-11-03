#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t;  // X Y Jump_times
#define X get<0>
#define Y get<1>
#define J get<2>
queue<t> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
int maskKX[] = {-1, 1, 2, 2, 1, -1, -2, -2};  // start : 11'o clock direction
int maskKY[] = {2, 2, 1, -1, -2, -2, -1, 1};
int K, W, H, cX, cY, cJ, tX, tY, loop, found = false, dist = 0, board[205][205], visited[35][205][205] = {0};


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> W >> H;
    for (int h = 0; h < H; h++) {
        for (int w = 0; w < W; w++) {
            cin >> board[h][w];
        }
    }

    visited[0][0][0] = 1;
    q.emplace(0,0,0);
    while(!q.empty() && !found) {
        dist++;
        loop = q.size();
        for (int l = 0; l < loop; l++) {
            tie(cX, cY, cJ) = q.front();
            if (cX == W-1 && cY == H-1) {
                found = true;
                break;
            }
            q.pop();

            // UDLR
            for (int i = 0; i < 4; i++) {
                tX = cX + maskX[i];
                tY = cY + maskY[i];
                if (tX < 0 || tY < 0 || tX >= W || tY >= H || board[tY][tX] == 1) continue;
                if (visited[cJ][tY][tX]) continue;

                visited[cJ][tY][tX] = 1;
                q.emplace(tX, tY, cJ);
            }
            // Knight jump
            if (cJ >= K) continue;
            for (int i = 0; i < 8; i++) {
                tX = cX + maskKX[i];
                tY = cY + maskKY[i];
                if (tX < 0 || tY < 0 || tX >= W || tY >= H || board[tY][tX] == 1) continue;
                if (visited[cJ+1][tY][tX]) continue;

                visited[cJ+1][tY][tX] = 1;
                q.emplace(tX, tY, cJ+1);
            }
        }
    }
    if (found) cout << dist-1;
    else cout << -1;
}