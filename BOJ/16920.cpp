#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
const int wall = -1;
int N, M, P, S[10], loop, isBoardFull = 0, depth = 0, turn = 0, tX, tY, sum[10] = {0}, stuck[10] = {0};  // 1-indexed (S, sum, stuck)
int board[1005][1005], dist[10][1005][1005];  // dist[i] is 1-indexed
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
            fill(dist[p][n], dist[p][n]+M, -1);  // init visited array
        }
    }
    for (int n = 0; n < N; n++) {
        cin >> in;
        for (int m = 0; m < M; m++) {
            if (in[m] == '.') board[n][m] = 0;
            else if (in[m] == '#') board[n][m] = wall;
            else {
                board[n][m] = in[m]-'0';
                dist[board[n][m]][n][m] = 0;
                q[board[n][m]].emplace(m, n);  // push into each player's queue
            }
        }
    }

    while (!empty()) {
        depth++;
        for (int p = 1; p <= P; p++) {  // each player
            loop = q[p].size();
            for (int l = 0; l < loop; l++) {  // current queue's one cycle in the single turn
                for (int i = 0; i < 4; i++) {
                    tX = q[p].front().X + maskX[i];
                    tY = q[p].front().Y + maskY[i];
                    if (tX < 0 || tY < 0 || tX >= M || tY >= N || board[tY][tX] != 0 || dist[p][tY][tX] != -1) continue;
                    dist[p][tY][tX] = depth;
                    q[p].emplace(tX, tY);
                }
                q[p].pop();
            }
        }
    }

//    while (!empty()) {
//        turn++;
//        for (int p = 1; p <= P; p++) {  // each player
//            for (int s = 1; s <= S[p]; s++) {  // expanding range
//                loop = q[p].size();
//                for (int l = 0; l < loop; l++) {  // current queue's one cycle in the single turn
//                    for (int i = 0; i < 4; i++) {
//                        tX = q[p].front().X + maskX[i];
//                        tY = q[p].front().Y + maskY[i];
//                        if (tX < 0 || tY < 0 || tX >= M || tY >= N || board[tY][tX] != 0) continue;
//                        board[tY][tX] = p;
//                        q[p].emplace(tX, tY);
//                    }
//                    q[p].pop();
//                }
//            }
//        }
//    }


    while (!isBoardFull) {
        turn++;
        isBoardFull = true;
        for (int p = 1; p <= P; p++) {
            if (stuck[p]) continue;  // There's no empty space to move from [p]'s positions
            stuck[p] = true;
            for (int n = 0; n < N; n++) {
                for (int m = 0; m < M; m++) {
                    if (board[n][m] != 0 || dist[p][n][m] > S[p]*turn || dist[p][n][m] < 0) continue;
                    board[n][m] = p;
                    isBoardFull = false;
                    stuck[p] = false;
                }
            }
        }
    }

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            if (board[n][m] != wall) sum[board[n][m]]++;
        }
    }
    for (int p = 1; p <= P; p++) {
        cout << sum[p] << ' ';
    }
}