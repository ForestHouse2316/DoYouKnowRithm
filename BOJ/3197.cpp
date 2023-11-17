#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
int R, C, cX, cY, tX, tY, loop, day = 0, L = 0;
bool vis[2][1502][1502] = {false};  // visited[swan number][Y][X]
int board[1502][1502];
string in;
deque<p> d[2];  // q[swan number]
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
            else board[r][c] = in[c] == 'X' ? -1 : 7;
        }
    }

    // multi BFS (fluid fill + waiting)
    while (true) {

//        cout << "> Day " << day << endl;
//        for (int r = 0; r < R; r++) {
//            for (int c = 0; c < C; c++) {
//                cout << board[r][c] << '\t';
//            }
//            cout << endl;
//        }

        for (int cL = 0; cL < 2; cL++) {
            loop = d[cL].size();
            while (loop--) {
                tie(cX, cY) = d[cL].front();
                d[cL].pop_front();
                if (board[cY][cX] == -1) board[cY][cX] = cL;

                for (int i = 0; i < 4; i++) {
                    tX = cX + maskX[i];
                    tY = cY + maskY[i];
                    if (tX < 0 || tY < 0 || tX >= C || tY >= R || vis[cL][tY][tX]) continue;
                    vis[cL][tY][tX] = true;
                    switch (board[tY][tX]) {
                        case -1:
                            d[cL].emplace_back(tX, tY);
                            break;
                        case 7:
                            d[cL].emplace_front(tX, tY);
                            board[tY][tX] = cL;
                            loop++;
                            break;
                        case 0:
                        case 1:
                            cout << day;
                            return 0;
                    }
                }
            }
        }
        day++;
    }
}