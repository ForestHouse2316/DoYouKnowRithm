#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second

int M, N, K, board[105][105] = {0}, ax, ay, bx, by;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
vector<int> sizes;
queue<p> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;  // ROW !!
    cin >> N;  // COL !!
    cin >> K;

    for (int k = 0; k < K; k++) {
        cin >> ax;
        cin >> ay;
        cin >> bx;
        cin >> by;

        for (int x = ax; x < bx; x++) {
            for (int y = ay; y < by; y++) {
                board[y][x] = 1;
            }
        }
    }

    for (int row = 0; row < M; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 0) {
                int size = 1;
                board[row][col] = 1;
                q.emplace(col, row);
                while (!q.empty()) {
                    board[q.front().Y][q.front().X] = 1;
                    for (int i = 0; i < 4; i++) {
                        int tX = maskX[i] + q.front().X;
                        int tY = maskY[i] + q.front().Y;

                        if (tX < 0 || tY < 0 || tX >= N || tY >= M) continue;

                        if (board[tY][tX] == 0) {
                            board[tY][tX] = 1;
                            q.emplace(tX, tY);
                            size++;
                        }
                    }
                    q.pop();
                }
                sizes.push_back(size);
            }
        }
    }

    cout << sizes.size() << "\n";
    std::sort(sizes.begin(), sizes.end());
    for (int size : sizes) {
        cout << size << " ";
    }
}