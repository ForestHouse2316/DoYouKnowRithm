#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define x first
#define y second
queue<p> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int R, C, tx, ty, loop, cycle, maxDist=0, minDist = -1, cars=0, pzones=0, dfsCycle = 0, board[52][52];  // both cars/pzones are the number of each item
int s, e, distLimit, carLink[102], pLink[102], dfsVis[102] = {0}, pDist[102][102]; // pDist[car num][pzone num] = distance
char in;
bool vis[52][52];
p carPos[102];

bool dfs(int car) {
    if (dfsVis[car] == dfsCycle) return false;
    dfsVis[car] = dfsCycle;

    for (int pzone = 0; pzone < pzones; ++pzone) {
        if (pDist[car][pzone] <= distLimit) {
            if (pLink[pzone] == -1 || dfs(pLink[pzone])) {
                carLink[car] = pzone;
                pLink[pzone] = car;
                return true;
            }
        }
    }
    return false;
}

bool bm() {
    fill(carLink, carLink+102, -1);
    fill(pLink, pLink+102, -1);
    for (int car = 0; car < cars; ++car) {
        dfsCycle++;
        if (!dfs(car)) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> in;
            switch (in) {
                case 'C':
                    carPos[cars++] = {c, r};
                    board[r][c] = -2;
                    break;
                case 'X':
                    board[r][c] = -1;
                    break;
                case '.':
                    board[r][c] = -2;
                    break;
                case 'P':
                    board[r][c] = pzones++;  // board arr gets pzone number on pzone's position
                    break;
            }
        }
    }
    if (cars > pzones) {
        cout << -1;
        return 0;
    }

    for (int car = 0; car < cars; ++car) {  // compose distance information
        fill(pDist[car], pDist[car]+pzones+1, INT_MAX);  // init pDist as maximum distance value
        for (int r = 0; r < R; ++r) {  // init vis
            fill(vis[r], vis[r]+C+1, false);
        }
        q.push(carPos[car]);
        cycle = 0;  // == distance
        while (!q.empty()) {  // BFS for pDist
            loop = q.size();
            cycle++;
            for (int l = 0; l < loop; ++l) {
                for (int i = 0; i < 4; ++i) {
                    tx = dx[i] + q.front().x;
                    ty = dy[i] + q.front().y;
                    if (tx < 0 || ty < 0 || tx >= C || ty >= R || board[ty][tx] == -1 || vis[ty][tx]) continue;
                    vis[ty][tx] = true;
                    q.emplace(tx, ty);
                    if (board[ty][tx] >= 0) {
                        pDist[car][board[ty][tx]] = cycle;
                        maxDist = max(cycle, maxDist);
                    }
                }
                q.pop();
            }
        }
    }

    s = 0, e = maxDist;
    while (s <= e) {
        distLimit = (s+e)/2;
        if (bm()) {
            minDist = distLimit;
            e = distLimit-1;
        }
        else {
            s = distLimit+1;
        }
    }
    cout << minDist;
}