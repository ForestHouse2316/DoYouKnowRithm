#include <bits/stdc++.h>
using namespace std;
typedef tuple<int, int, int> t;
#define X get<0>
#define Y get<1>
#define Z get<2>
int L, R, C;
char board[35][35][35];
string in;
int maskX[] = {0, 1, 0, -1, 0, 0};
int maskY[] = {1, 0, -1, 0, 0, 0};
int maskZ[] = {0, 0, 0, 0, 1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> L;
        cin >> R;
        cin >> C;
        if (L == 0) break;
        queue<t> q;

        // input
        for (int l = 0; l < L; l++) {
            for (int row = 0; row < R; row++) {
                cin >> in;
                for (int col = 0; col < C; col++) {
                    board[l][row][col] = in[col];
                    if (in[col] == 'S') {
                        q.emplace(col, row, l);
                    }
                }
            }
        }

        int time = 0;
        bool escaped = false;
        while (!q.empty() && !escaped) {
            int loop = q.size();
            time++;
            for (int l = 0; l < loop && !escaped; l++) {
                for (int i = 0; i < 6 && !escaped; i++) {
                    int tX = X(q.front()) + maskX[i];
                    int tY = Y(q.front()) + maskY[i];
                    int tZ = Z(q.front()) + maskZ[i];
                    if (tX < 0 || tY < 0 || tZ < 0 || tX >= C || tY >= R || tZ >= L) continue;

                    switch (board[tZ][tY][tX]) {
                        case '.':
                            board[tZ][tY][tX] = '|';
                            q.emplace(tX, tY, tZ);
                            break;
                        case 'E':
                            cout << "Escaped in " << time << " minute(s)." << "\n";
                            escaped = true;
                            break;
                    }
                }
                q.pop();
            }
        }
        if (!escaped) cout << "Trapped!" << "\n";
    }
}