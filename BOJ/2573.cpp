#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
#define X first
#define Y second
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
int N, M, tX, tY, year = 0, board[305][305] = {0}, visited[305][305] = {0}, meltAmount[305][305] = {0};
bool allMelted;

bool divided(int y) {
    bool aPiece = false;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (board[n][m] > 0 && visited[n][m] < y) {
                if (aPiece) return true;

                aPiece = true;
                visited[n][m] = y;
                q.emplace(m, n);
                while (!q.empty()) {
                    for (int i = 0; i < 4; i++) {
                        tX = maskX[i] + q.front().X;
                        tY = maskY[i] + q.front().Y;
                        if (tX < 0 || tY < 0 || tX >= M || tY >= N) continue;
                        if (board[tY][tX] == 0 || visited[tY][tX] == y) continue;

                        visited[tY][tX] = y;
                        q.emplace(tX, tY);
                    }
                    q.pop();
                }
            }
        }
    }
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> board[n][m];
        }
    }
    do {
        allMelted = true;
        year++;
        // calc melting speed
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                meltAmount[n][m] = 0;
                if (board[n][m]) {
                    allMelted = false;
                    for (int i = 0; i < 4; i++) {
                        tX = maskX[i] + m;
                        tY = maskY[i] + n;
                        if (tX >= 0 && tY >= 0 && tX < M && tY < N && board[tY][tX] == 0) meltAmount[n][m]++;
                    }
                }
            }
        }
        // apply melting
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                board[n][m] = max(0, board[n][m] - meltAmount[n][m]);
            }
        }
    } while(!divided(year) && !allMelted);
    if (allMelted) cout << 0;
    else cout << year;
}