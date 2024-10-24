#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
#define px(K) pos[K].X
#define py(K) pos[K].Y
typedef pair<int, int> pii;


int N, K, dir[11], board[14][14], stk[13][13][10], len[13][13] = {}; // board[y][x], stk[y][x], len[k], dir[k]: 1-indexed
pii pos[11]; // pos[k]

pii posMove(pii curPos, int curDir) {
    switch (curDir) {
        case 1:
            curPos.X++;
            break;
        case 2:
            curPos.X--;
            break;
        case 3:
            curPos.Y--;
            break;
        case 4:
            curPos.Y++;
            break;
    }

    return curPos;
}

void moveTo(int fx, int fy, int tx, int ty, int nth, bool reverse = false) {
    for (int i = nth; i < len[fy][fx]; ++i) {
        // propagate new pos
        pos[stk[fy][fx][i]] = {tx, ty};
        // move
        if (!reverse) stk[ty][tx][len[ty][tx]++] = stk[fy][fx][i];
        else stk[ty][tx][len[ty][tx]++] = stk[fy][fx][len[fy][fx] - 1 - i + nth];
    }

    len[fy][fx] = nth;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int i = 1; i <= N; ++i) {
        board[i][0] = board[i][N+1] = 2;
        for (int j = 1; j <= N; ++j) {
            board[0][j] = board[N+1][j] = 2;
            cin >> board[i][j];
        }
    }
    for (int k = 1; k <= K; ++k) {
        cin >> py(k) >> px(k) >> dir[k];
        stk[py(k)][px(k)][0] = k;
        len[py(k)][px(k)] = 1;
    }

    for (int turn = 1; turn <= 1000; ++turn) {
        for (int k = 1; k <= K; ++k) {
            pii nPos = posMove(pos[k], dir[k]);

            if (board[nPos.Y][nPos.X] == 2) { // out of board or blue
                // rev dir for current piece
                if (dir[k] == 1 || dir[k] == 3) dir[k]++;
                else dir[k]--;

                // check whether the next cell color is out of board or blue
                nPos = posMove(pos[k], dir[k]);
                if (board[nPos.Y][nPos.X] == 2) continue; // stay, don't move
            }
            int nth = -1;
            for (int i = 0; i < len[py(k)][px(k)]; ++i) { // indexOf(k)
                if (stk[py(k)][px(k)][i] == k) {
                    nth = i;
                    break;
                }
            }

            moveTo(px(k), py(k), nPos.X, nPos.Y, nth,board[nPos.Y][nPos.X] == 1);
            if (len[nPos.Y][nPos.X] >= 4) {
                cout << turn;
                return 0;
            }
        }
    }

    cout << -1;
}