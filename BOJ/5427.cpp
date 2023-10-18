#include <bits/stdc++.h>
using namespace std;


typedef pair<int, int> p;
#define X first
#define Y second

int N, w, h, qloop;
char board[1005][1005];
string in;
int maskY[] = {1, 0, -1, 0};
int maskX[] = {0, 1, 0, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; n++) {
        bool escaped = false;
        queue<p> fq, pq;
        int time = 0;
        cin >> w;
        cin >> h;

        // compose board
        for (int y = 0; y < h; y++) {
            cin >> in;
            for (int x = 0; x < w; x++) {
                board[y][x] = in[x];
                if (in[x] == '*') fq.emplace(x, y);
                else if (in[x] == '@') pq.emplace(x, y);
            }
        }
        while (!escaped) {
            if (pq.empty()) {
                cout << "IMPOSSIBLE" << "\n";
                break;
            }
            time++;

            // fire diffusion
            qloop = fq.size();
            for (int i = 0; i < qloop; i++) {
                for (int j = 0; j < 4; j++) {
                    int tX = fq.front().X + maskX[j];
                    int tY = fq.front().Y + maskY[j];
                    if (tX < 0 || tY < 0 || tX >= w || tY >= h) continue;
                    if (board[tY][tX] != '#' && board[tY][tX] != '*') {
                        board[tY][tX] = '*';
                        fq.emplace(tX, tY);
                    }
                }
                fq.pop();
            }

            // player diffusion
            qloop = pq.size();
            for (int i = 0; i < qloop && !escaped; i++) {
                for (int j = 0; j < 4; j++) {
                    int tX = pq.front().X + maskX[j];
                    int tY = pq.front().Y + maskY[j];
                    if (tX < 0 || tY < 0 || tX >= w || tY >= h) {
                        cout << time << "\n";
                        escaped = true;
                        break;
                    }
                    if (board[tY][tX] == '.') {
                        board[tY][tX] = '@';
                        pq.emplace(tX, tY);
                    }
                }
                pq.pop();
            }
        }
    }
}