#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
const int wall = -1;
int N, M, P, S[10], loop, tX, tY, sum[10] = {0};  // 1-indexed (S, sum)
int board[1005][1005];
string in;
queue<p> q[10];  // 1-indexed
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};

bool empty() {
    for (int i = 1; i <= P ; i++) {
        if (!q[i].empty()) return false;
    }
    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> P;
    for (int p = 1; p <= P; p++) {
        cin >> S[p];
        for (int n = 0; n < N; n++) {
        }
    }
    for (int n = 0; n < N; n++) {
        cin >> in;
        for (int m = 0; m < M; m++) {
            if (in[m] == '.') board[n][m] = 0;
            else if (in[m] == '#') board[n][m] = wall;
            else {
                board[n][m] = in[m]-'0';
                sum[board[n][m]]++;
                q[board[n][m]].emplace(m, n);  // push into each player's queue
            }
        }
    }
    // BFS
    while (!empty()) {
        for (int p = 1; p <= P; p++) {  // each player
            if (q[p].empty()) continue;
            for (int s = 1; s <= S[p] && !q[p].empty(); s++) {  // expanding process cycle
                loop = q[p].size();
                for (int l = 0; l < loop; l++) {  // current queue's one cycle in the single turn
                    for (int i = 0; i < 4; i++) {
                        tX = q[p].front().X + maskX[i];
                        tY = q[p].front().Y + maskY[i];
                        if (tX < 0 || tY < 0 || tX >= M || tY >= N || board[tY][tX] != 0) continue;
                        board[tY][tX] = p;
                        sum[p]++;
                        q[p].emplace(tX, tY);
                    }
                    q[p].pop();
                }
            }
        }
    }

    for (int p = 1; p <= P; p++) {
        cout << sum[p] << ' ';
    }
}