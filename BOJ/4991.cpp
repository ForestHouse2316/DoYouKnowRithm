#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int W, H, dist[11][11], dustCnt, tx, ty, minDist, depth, loop;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
char room[20][20];
vector<pii> pos; // [0] is robot's position
bool vis[20][20];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    pos.reserve(12);
    while (1) {
        cin >> W >> H;
        if (W == 0) return 0;

        pos.clear();
        pos.emplace_back(0, 0);

        for (int h = 0; h < H; ++h) {
            for (int w = 0; w < W; ++w) {
                cin >> room[h][w];
                switch(room[h][w]) {
                    case 'o':
                        pos[0] = {w, h}; // overwrite
                        room[h][w] = '.';
                        break;
                    case '*':
                        room[h][w] = '0' + (char) pos.size() - 1; // dustID [0, 10)
                        pos.emplace_back(w, h);
                        break;
                }
            }
        }

        // check reachability and calc dist
        for (int from = 0; from < pos.size() - 1; ++from) {
            queue<pii> q;
            dustCnt = 0;
            depth = 0;
            for (int i = 0; i < 20; ++i) fill(vis[i], vis[i]+20, false);

            q.push(pos[from]);
            vis[pos[from].Y][pos[from].X] = true;
            while (!q.empty()) {
                loop = q.size();
                depth++;
                while (loop--) {
                    for (int i = 0; i < 4; ++i) {
                        tx = q.front().X + dx[i];
                        ty = q.front().Y + dy[i];
                        if (tx < 0 || ty < 0 || tx >= W || ty >= H || vis[ty][tx] || room[ty][tx] == 'x') continue;

                        vis[ty][tx] = true;
                        q.emplace(tx, ty);
                        if (room[ty][tx] >= '0' + from && room[ty][tx] <= '9') {
                            dustCnt++;
                            dist[from][room[ty][tx] - '0' + 1] = dist[room[ty][tx] - '0' + 1][from] = depth; // calc A-B dist
                        }
                    }
                    q.pop();
                }
            }

            if (from == 0 && dustCnt != pos.size() - 1) {
                cout << -1 << '\n';
                dustCnt = -1;
                break;
            }
        }
        if (dustCnt == -1) continue; // jump

        // bruteforce
        minDist = INT_MAX;
        int perm[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
        do {
            int total = 0;
            for (int i = 0; i < pos.size() - 1; ++i) total += dist[perm[i]][perm[i+1]];
            minDist = min(minDist, total);
        } while (next_permutation(perm+1, perm+pos.size())); // perm[0] is fixed
        cout << minDist << '\n';
    }
}