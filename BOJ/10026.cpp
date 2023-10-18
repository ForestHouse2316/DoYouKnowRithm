#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second

int N, section[2];
char board[105][105], color;
bool visited[2][105][105] = {false};
string in;
queue<p> q;
int maskY[4] = {1, 0, -1, 0};
int maskX[4] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> in;
        for (int i = 0; i < N; i++) {
            board[n][i] = in[i];
        }
    }

    // type - 0 : Normal , 1 : Abnormal
    for (int type = 0; type < 2; type++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (!visited[type][y][x]) {
                    visited[type][y][x] = true;
                    section[type]++;
                    color = board[y][x];
                    q.emplace(x, y);
                    while (!q.empty()) {
                        for (int i = 0; i < 4; i++) {
                            int tX = q.front().X + maskX[i];
                            int tY = q.front().Y + maskY[i];
                            if (tX < 0 || tX > N-1 || tY < 0 || tY > N-1) continue;
                            if ((board[tY][tX] == color || type==1 && color != 'B' && board[tY][tX] != 'B') && !visited[type][tY][tX]) {
                                visited[type][tY][tX] = true;
                                q.emplace(tX, tY);
                            }
                        }
                        q.pop();
                    }
                }
            }
        }
    }
    cout << section[0] << " " << section[1];
}