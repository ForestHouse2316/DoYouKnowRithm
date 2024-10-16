#include <bits/stdc++.h>
using namespace std;
struct sh {
    int id; // [0, M) range, -1 means dead shark.
    int r;
    int c;
    int s;
    int d;
    int z;
};

int R, C, M, result = 0, board[102][102], dx[5] = {0, 0, 0, 1, -1}, dy[5] = {0, -1, 1, 0, 0};
vector<sh> sharks;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> R >> C >> M;
    if (M == 0) {cout << 0; return 0;}

    for (int r = 0; r < R; ++r) fill(board[r], board[r]+C, -1);
    sharks.reserve(M+2);

    for (int m = 0; m < M; ++m) {
        sh s;
        s.id = m;
        cin >> s.r >> s.c >> s.s >> s.d >> s.z;
        s.r--; s.c--; // 0-indexed
        board[s.r][s.c] = m;
        sharks.push_back(s);
    }

    for (int sec = 0; sec < C; ++sec) {
        // fishing
        for (int row = 0; row < R; ++row) {
            if (board[row][sec] == -1) continue;

            sh& target = sharks[board[row][sec]];
            result += target.z;
            target.id = -1; board[row][sec] = -1;
            break;
        }

        // shark move
        for(sh& s : sharks) {
            if (s.id < 0) continue;

            int dist = s.s, avail;
            if (board[s.r][s.c] == s.id) board[s.r][s.c] = -1;

            if ((s.d == 1 || s.d == 2)) dist %= R*2 - 2;
            else if ((s.d == 3 || s.d == 4)) dist %= C*2 - 2;
            while (dist) {
                switch (s.d) {
                    case 1: // U
                        if (s.r == 0) {
                            s.d = 2;
                            continue;
                        }
                        avail = min(dist, s.r);
                        s.r -= avail;
                        break;
                    case 2: // D
                        if (s.r == R-1) {
                            s.d = 1;
                            continue;
                        }
                        avail = min(dist, R-1 - s.r);
                        s.r += avail;
                        break;
                    case 3: // R
                        if (s.c == C-1) {
                            s.d = 4;
                            continue;
                        }
                        avail = min(dist, C-1 - s.c);
                        s.c += avail;
                        break;
                    case 4: // L
                        if (s.c == 0) {
                            s.d = 3;
                            continue;
                        }
                        avail = min(dist, s.c);
                        s.c -= avail;
                        break;
                }
                dist -= avail;
            }
            // collision check
            if (board[s.r][s.c] == -1) board[s.r][s.c] = s.id;
            else {
                sh& enemy = sharks[board[s.r][s.c]];
                if (enemy.id > s.id && enemy.d > 0) board[s.r][s.c] = s.id; // pass
                else if (enemy.z > s.z) s.id = -1; // defeat
                else { // win
                    board[s.r][s.c] = s.id;
                    enemy.id = -1;
                }
            }
        }
    }
    cout << result;
}