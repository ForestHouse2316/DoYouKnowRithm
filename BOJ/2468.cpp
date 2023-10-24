#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
int N, board[105][105] = {0}, maxArea = 1;
bool groundHeight[105] = {false};  // 1-indexed
string in;
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> in;
            int casted = 0;
            for (char c : in) {
                casted = casted*10 + c - '0';
            }
            board[row][col] = casted;
            groundHeight[casted] = true;
        }
    }

    for (int level = 1; level < 100; level++) {
        if (!groundHeight[level]) continue;
        int area = 0, visited[105][105] = {0};

        for (int y = 0; y < N; y++) {
            for (int x = 0; x < N; x++) {
                if (board[y][x] <= level || visited[y][x]) continue;

                visited[y][x] = 1;
                q.emplace(x, y);
                area++;

                while (!q.empty()) {
                    for (int i = 0; i < 4; i++) {
                        int tX = q.front().X + maskX[i];
                        int tY = q.front().Y + maskY[i];

                        if (tX < 0 || tY < 0 || tX >= N || tY >= N) continue;
                        if (!visited[tY][tX] && board[tY][tX] > level) {
                            visited[tY][tX] = 1;
                            q.emplace(tX, tY);
                        }
                    }
                    q.pop();
                }
            }
        }
        maxArea = max(maxArea, area);
    }
    cout << maxArea;
}