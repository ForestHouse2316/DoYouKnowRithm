#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second

int N, M, minLength = 10000000, board[1005][1005], depth[2][1005][1005] = {0}; // depth[Start/End][ROW][COL]
string in;
queue<p> q, adjacencys;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
int maskDX[] = {1, 1, -1, -1};
int maskDY[] = {1, -1, -1, 11};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;
    depth[0][0][0] = 1;
    depth[1][N-1][M-1] = 1;

    for (int n = 0; n < N; n++) {
        cin >> in;
        for (int m = 0; m < M; m++) {
            board[n][m] = in[m] - '0';
        }
    }

    // Get depth
    for (int se = 0; se < 2; se++) {
        if (se == 0) q.emplace(0, 0);
        else q.emplace(M-1, N-1);

        while (!q.empty()) {
            bool adjacency = false;
            for (int i = 0; i < 4; i++) {
                int tX = q.front().X + maskX[i];
                int tY = q.front().Y + maskY[i];
                if (tX < 0 || tY < 0 || tX >= M || tY >= N) continue;  // OOB
                if (tX == 0 && tY == 0 || tX == M-1 && tY == N-1) continue;

                if (board[tY][tX] == 1) {  // If adjoin to wall
                    adjacency = true;
                    continue;
                }

                if (depth[se][tY][tX] == 0) {
                    depth[se][tY][tX] = depth[se][q.front().Y][q.front().X] + 1;
                    q.emplace(tX, tY);
                }
            }
            if (adjacency && se == 0) adjacencys.push(q.front());

            q.pop();
        }
    }

    if (depth[0][N-1][M-1] != 0) minLength = depth[0][N-1][M-1] + 1;  // if normalPath exist

    adjacencys.emplace(0, 0);
    while (!adjacencys.empty()) {
        // plus-shape search
        for (int i = 0; i < 4; i++) {
            int tX = adjacencys.front().X + maskX[i];
            int tY = adjacencys.front().Y + maskY[i];
            if (tX < 0 || tY < 0 || tX >= M || tY >= N) continue;

            if (board[tY][tX] == 1) {  // wall
                tX += maskX[i];
                tY += maskY[i];
                if (tX < 0 || tY < 0 || tX >= M || tY >= N) continue;

                if (depth[1][tY][tX] != 0) {  // accessible
                    minLength = min(minLength, depth[0][adjacencys.front().Y][adjacencys.front().X] + depth[1][tY][tX] + 1);
                }
            }
        }
        // diagonal search
        for (int i = 0; i < 4; i++) {
//            // wall a
//            int aX = adjacencys.front().X + maskX[i%4];
//            int aY = adjacencys.front().Y + maskY[i%4];
//            // wall b
//            int bX = adjacencys.front().X + maskX[(i+1)%4];
//            int bY = adjacencys.front().Y + maskY[(i+1)%4];
//            if (board[aY][aX] + board[bY][bX] != 2) continue;  // two walls muse exist, if not, breaking wall does not shorten the length

            int tX = adjacencys.front().X + maskDX[i];
            int tY = adjacencys.front().Y + maskDY[i];
            if (tX < 0 || tY < 0 || tX >= M || tY >= N) continue;

            if (depth[1][tY][tX] != 0) {  // accessible
                minLength = min(minLength, depth[0][adjacencys.front().Y][adjacencys.front().X] + depth[1][tY][tX] + 1);
            }
        }
        adjacencys.pop();
    }


//    for (int n = 0; n < N; n++) {
//        for (int m = 0; m < M; m++) {
//            cout << depth[1][n][m];
//        }
//        cout << "\n";
//    }
    cout << (minLength==10000000 ? -1 : minLength);
}