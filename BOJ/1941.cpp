#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

string in;
char board[5][5], perm[25];
int result=0, cx, cy, tx, ty;
bool vis[5][5];

void bfs(int x, int y) {
    queue<pii> q;
    q.emplace(x, y);
    int cntS=0, cntElem=0;
    for(auto & vLine : vis) {
        fill(vLine, vLine+5, false);
    }

    vis[y][x] = true;

    while (!q.empty()) {
        tie(cx, cy) = q.front();
        q.pop();
        cntElem++;
        if (board[cy][cx] == 'S') cntS++;

        for (int i = 0; i < 4; ++i) {
            tx = cx+dx[i];
            ty = cy+dy[i];
            if (tx < 0 || ty < 0 || tx >= 5 || ty >= 5 || perm[ty*5+tx] == 1 || vis[ty][tx]) continue;

            vis[ty][tx] = true;
            q.emplace(tx, ty);
        }
    }

    if (cntS >= 4 && cntElem == 7) result++;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    fill(perm+7, perm+25, true);

    for (int y = 0; y < 5; ++y) {
        cin >> in;
        for (int x = 0; x < 5; ++x) {
            board[y][x] = in[x];
        }
    }

    do {
        for (int i = 0; i < 25; ++i) {
            if (perm[i] == 1) continue;

            bfs(i%5, i/5);
            break;
        }
    } while(next_permutation(perm, perm+25));

    cout << result;
}