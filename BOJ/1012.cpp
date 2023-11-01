#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
int T, M, N, K, board[55][55] = {0}, tX, tY;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> M;
        cin >> N;
        cin >> K;
        for (int k = 0; k < K; k++) {
            cin >> tX;
            cin >> tY;
            board[tY][tX] = t;  // marked with current T value, but you may use just 1 to mark the position
        }

        int section = 0;
        for (int n = 0; n < N; n++) {
            for (int m = 0; m < M; m++) {
                if (board[n][m] == t) {
                    section++;
                    board[n][m] = 0;
                    q.emplace(m, n);

                    while (!q.empty()) {
                        for (int i = 0; i < 4; i++) {
                            tX = q.front().X + maskX[i];
                            tY = q.front().Y + maskY[i];
                            if (tX < 0 || tY < 0 || tX >= M || tY >= N) continue;
                            if (board[tY][tX] != t) continue;

                            board[tY][tX] = 0;
                            q.emplace(tX, tY);
                        }
                        q.pop();
                    }
                }
            }
        }
        cout << section << '\n';
    }
}