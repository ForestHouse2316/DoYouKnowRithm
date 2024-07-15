#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

char in, board[15][10];
int cnt = 0;

void gravity() {
    for (int x = 0; x < 6; ++x) {
        vector<char> v;
        int bottomY = 0;

        while (board[bottomY][x] != '.') bottomY++; // stops on the first EMPTY cell
        for (int y = bottomY; y < 12; ++y) {
            if (board[y][x] == '.') continue;
            board[bottomY++][x] = board[y][x];
        }
        for (int y = bottomY; y < 12; ++y) board[y][x] = '.';
    }
}

bool pop() {
    bool hasPop = false, vis[12][6] = {false};
    for (int sy = 0; sy < 12; ++sy) {
        for (int sx = 0; sx < 6; ++sx) {
            if (board[sy][sx] == '.' || vis[sy][sx]) continue;

            int tx, ty;
            char target = board[sy][sx];
            queue<pii> q;
            vector<pii> group;
            q.emplace(sx, sy);
            vis[sy][sx] = true;
            group.emplace_back(sx, sy);
            while (!q.empty()) {
                for (int i = 0; i < 4; ++i) {
                    tx = q.front().X + dx[i];
                    ty = q.front().Y + dy[i];
                    if (tx < 0 || ty < 0 || tx >= 6 || ty >= 12 || vis[ty][tx] || board[ty][tx] != target) continue;

                    q.emplace(tx, ty);
                    vis[ty][tx] = true;
                    group.emplace_back(tx, ty);
                }
                q.pop();
            }

            if (group.size() < 4) continue; // pop threshold
            hasPop = true;
            for (auto xy : group) {
                board[xy.Y][xy.X] = '.';
            }
        }
    }
    return hasPop;
}

void visualize() {
    cout << endl;
    cout << endl;
    for (int y = 11; y >= 0; --y) {
        for (int x = 0; x < 6; ++x) {
            cout << board[y][x] << ' ';
        }
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int y = 11; y >= 0; --y) { // reverse Y axis
        for (int x = 0; x < 6; ++x) {
            cin >> board[y][x];
        }
    }

    while (pop()) {
        cnt++;
        gravity();
    }
    cout << cnt;
}