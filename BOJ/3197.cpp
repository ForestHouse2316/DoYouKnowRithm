#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
int R, C, cX, cY, tX, tY, loop, day = 0, L = 0;
bool vis[3][1502][1502] = {false};  // visited[swan number/water][Y][X]
int board[1502][1502];  // -1 glacier / 0,1 swan area / 2 water
string in;
deque<p> d[3];  // q[swan number/water]
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> R >> C;
    for (int r = 0; r < R; r++) {
        cin >> in;
        for (int c = 0; c < C; c++) {
            if (in[c] == 'L') {
                d[L].emplace_front(c, r);
                board[r][c] = L;
                vis[L][r][c] = true;
                L++;
            }
            else if (in[c] == 'X') {
                board[r][c] = -1;
            }
            else {
                d[2].emplace_front(c, r);
                vis[2][r][c] = true;
                board[r][c] = 2;
            }
        }
    }

    // multi BFS (fluid fill + waiting)
    while (true) {
        for (int cL = 2; cL >= 0; cL--) {  // CL 2 is deque for water tiles
            loop = d[cL].size();
            while (loop--) {
                tie(cX, cY) = d[cL].front();
                d[cL].pop_front();
                if (board[cY][cX] == -1 || board[cY][cX] == 2) board[cY][cX] = cL;

                for (int i = 0; i < 4; i++) {
                    tX = cX + maskX[i];
                    tY = cY + maskY[i];
                    if (tX < 0 || tY < 0 || tX >= C || tY >= R || vis[cL][tY][tX]) continue;
                    vis[cL][tY][tX] = true;
                    if (cL == 2 && (vis[0][tY][tX] || vis[1][tY][tX])) continue;  // swans already visited here, so just check as visited
                    switch (board[tY][tX]) {
                        case -1:  // #
                            d[cL].emplace_back(tX, tY);
                            break;
                        case 2:  // .
                            d[cL].emplace_front(tX, tY);
                            board[tY][tX] = cL;
                            loop++;
                            break;
                        case 0:
                        case 1:  // L
                            if (cL != 2) {
                                cout << day;
                                return 0;
                            }
                            // else do nothing
                            break;
                    }
                }
            }
        }
        day++;
    }
}