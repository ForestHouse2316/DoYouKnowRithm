#include <bits/stdc++.h>
using namespace std;
#define row first
#define col second
typedef pair<int, int> pii;
struct heater {
    heater(int r, int c, int d) : r(r), c(c), d(d) {}
    int r, c, d;
};

// cover tempBoard[22][22] with -1 borders. -1 temperature means the end of the board.
int R, C, K, tempBoard[22][22] = {}; // 1-indexed, border-safe
bool wallBoard[2][22][22] = {}; // wallBoard[dir][row][col], 1-indexed, border-safe, dir0 horizon-top, dir1 vertical-right
int dr[4] = {0, 0, -1, 1}, dc[4] = {1, -1, 0, 0};
vector<heater> heaters;
vector<pii> investPoints;

//void debug() {
//    for (int r = 0; r <= R+1; ++r) {
//        for (int c = 0; c <= C+1; ++c) {
//            if (tempBoard[r][c] == 0) cout << ". ";
//            else if (tempBoard[r][c] == -1) cout << "- ";
//            else cout << tempBoard[r][c] << ' ';
//        }
//        cout << '\n';
//    }
//    cout << endl;
//}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> K;
    int in;
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            cin >> in;
            if (in == 0) continue;
            if (in == 5) investPoints.emplace_back(r, c);
            else {
                heaters.emplace_back(r, c, in-1);
            }
        }
    }
    // border -1 wrapping
    for (int r = 0; r <= R+1; ++r) tempBoard[r][0] = tempBoard[r][C+1] = -1;
    for (int c = 0; c <= C+1; ++c) tempBoard[0][c] = tempBoard[R+1][c] = -1;

    int W, x, y, t;
    cin >> W;
    while(W--) {
        cin >> x >> y >> t;
        wallBoard[t][x][y] = true;
    }

    int choco;
    for (choco = 1; choco < 101; ++choco) {
        // 1. blow heater's hot wind
        int tempUp[22][22] = {};
        for(heater h : heaters) {
            int vis[22][22] = {}, loop;
            queue<pii> q;
            pii qf;
            q.emplace(h.r+dr[h.d], h.c+dc[h.d]);
            for (int hotLvl = 5; hotLvl > 0; --hotLvl) {
                loop = q.size();
                while (loop--) {
                    qf = q.front();
                    q.pop();
                    if (vis[qf.row][qf.col]) continue;

                    tempUp[qf.row][qf.col] += hotLvl;
                    vis[qf.row][qf.col] = true;

                    if (hotLvl == 1) continue;
                    switch(h.d) {
                        case 0:
                        case 1:
                            // LR direction -> top mid bot
                            if (tempBoard[qf.row - 1][qf.col + dc[h.d]] != -1 && !wallBoard[0][qf.row][qf.col] && !wallBoard[1][qf.row - 1][qf.col - (h.d==1)])
                                q.emplace(qf.row - 1, qf.col + dc[h.d]);
                            if (tempBoard[qf.row][qf.col + dc[h.d]] != -1 && !wallBoard[1][qf.row][qf.col - (h.d==1)])
                                q.emplace(qf.row, qf.col + dc[h.d]);
                            if (tempBoard[qf.row + 1][qf.col + dc[h.d]] != -1 && !wallBoard[0][qf.row + 1][qf.col] && !wallBoard[1][qf.row + 1][qf.col - (h.d==1)])
                                q.emplace(qf.row + 1, qf.col + dc[h.d]);
                            break;
                        case 2:
                        case 3:
                            // UD direction -> left mid right
                            if (tempBoard[qf.row + dr[h.d]][qf.col - 1] != -1 && !wallBoard[1][qf.row][qf.col - 1] && !wallBoard[0][qf.row + (h.d==3)][qf.col - 1])
                                q.emplace(qf.row + dr[h.d], qf.col - 1);
                            if (tempBoard[qf.row + dr[h.d]][qf.col] != -1 && !wallBoard[0][qf.row + (h.d==3)][qf.col])
                                q.emplace(qf.row + dr[h.d], qf.col);
                            if (tempBoard[qf.row + dr[h.d]][qf.col + 1] != -1 && !wallBoard[1][qf.row][qf.col] && !wallBoard[0][qf.row + (h.d==3)][qf.col + 1])
                                q.emplace(qf.row + dr[h.d], qf.col + 1);
                            break;
                    }
                }
            }
        }
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                tempBoard[r][c] += tempUp[r][c]; // apply temp increment by heaters
            }
        }

        // 2. heat spreading (std -> right & down)
        int diffuse[22][22] = {}, diff4;
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                if (c < C && !wallBoard[1][r][c]) { // L -> R
                    diff4 = (tempBoard[r][c] - tempBoard[r][c+1]) / 4;
                    diffuse[r][c] -= diff4;
                    diffuse[r][c+1] += diff4;
                }
                if (r < R && !wallBoard[0][r+1][c]) { // U -> D
                    diff4 = (tempBoard[r][c] - tempBoard[r+1][c]) / 4;
                    diffuse[r][c] -= diff4;
                    diffuse[r+1][c] += diff4;
                }
            }
        }
        for (int r = 1; r <= R; ++r) {
            for (int c = 1; c <= C; ++c) {
                tempBoard[r][c] += diffuse[r][c];
            }
        }

        // 3. edge temp -1
        for (int r = 1; r <= R; ++r) {
            if (tempBoard[r][1] > 0) --tempBoard[r][1];
            if (tempBoard[r][C] > 0) --tempBoard[r][C];
        }
        for (int c = 2; c < C; ++c) { // avoid duplicated calculation about corner [2,C)
            if (tempBoard[1][c] > 0) --tempBoard[1][c];
            if (tempBoard[R][c] > 0) --tempBoard[R][c];
        }

        // 4. choco yeah

        // 5. check temperature of investPoints
        bool complete = true;
        for(pii point : investPoints) if (tempBoard[point.row][point.col] < K) {
                complete = false;
                break;
        }
        if (complete) break;
    }

    cout << choco;
}