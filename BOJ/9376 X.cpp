// Not completed!
// Other algorithms needed
#include <bits/stdc++.h>
using namespace std;
#define f q.front()
#define df door.front()
#define x first
#define y second
typedef pair<int, int> pii;
int T, H, W, tx, ty, found, depth;
bool vis[102][102];
char board[102][102];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        queue<pii> q;
        queue<pii> door;
        depth = 0;
        found = 0;

        cin >> H >> W;
        for (int h = 0; h < H; ++h) {
            fill(vis[h], vis[h]+W, false);
            for (int w = 0; w < W; ++w) {
                cin >> board[h][w];
                if (h == 0 || h == H-1 || w == 0 || w == W-1) {
                    if (board[h][w] == '.') {
                        q.emplace(w, h);
                        vis[h][w] = true;
                    }
                    else if (board[h][w] == '#') door.emplace(w, h);
                }
            }
        }

        while (found < 2) {
            // fluid fill
            while (!q.empty() && found < 2) {
                for (int i = 0; i < 4 && found < 2; ++i) {
                    tx = f.x + dx[i];
                    ty = f.y + dy[i];
                    if (tx < 0 || ty < 0 || tx >= W || ty >= H || vis[ty][tx] || board[ty][tx] == '*') continue;

                    vis[ty][tx] = true;
                    switch (board[ty][tx]) {
                        case '$':
                            board[ty][tx] = '.';
                            found++;
                            q.emplace(tx, ty);
                            break;
                        case '#':
                            door.emplace(tx, ty);
                            break;
                        case '.':
                            q.emplace(tx, ty);
                            break;
                    }
                }
                q.pop();
            }

            // open door
            while (!door.empty() && found < 2) {
                board[df.y][df.x] = '.';
                vis[df.y][df.x] = true;
                q.push(df);
                door.pop();
            }
            if (found < 2) depth++;
        }
        cout << depth << "\n";
    }
}