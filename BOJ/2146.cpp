#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
int N, tX, tY, minDist = 200, board[105][105] = {0}, visited[105][105] = {0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            cin >> board[row][col];
        }
    }

    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            if (board[row][col] == 1) {
                int islandNumber = -(row*1000) - col - 1;  // I added -1 offset to make this numbering system can handle (0,0) island
                queue<p> bridge;
                visited[row][col] = islandNumber;
                board[row][col] = islandNumber;
                q.emplace(col, row);

                // BFS to island tile
                while (!q.empty()) {
                    for (int i = 0; i < 4; i++) {
                        tX = q.front().X + maskX[i];
                        tY = q.front().Y + maskY[i];
                        if (tX < 0 || tY < 0 || tX >= N || tY >= N || board[tY][tX] < 0) continue;

                        visited[tY][tX] = islandNumber;
                        if (board[tY][tX] == 0) {
                            bridge.emplace(tX, tY);
                            continue;
                        }
                        q.emplace(tX, tY);
                        board[tY][tX] = islandNumber;  // visited value
                    }
                    q.pop();
                }

                // BFS to sea tile
                int dist = 0;
                bool exit = false;
                while (!exit) {
                    if (++dist >= minDist) break;  // halt meaningless loop

                    int loop = bridge.size();
                    for (int l = 0; l < loop && !exit; l++) {
                        for (int i = 0; i < 4; i++) {
                            tX = bridge.front().X + maskX[i];
                            tY = bridge.front().Y + maskY[i];
                            if (tX < 0 || tY < 0 || tX >= N || tY >= N || visited[tY][tX] == islandNumber) continue;  // if [OOB/visited/self]
                            if (board[tY][tX] < 0) {  // previously calculated island tile, this is not the shortest BFS!!! (or already calculated one)
                                exit = true;
                                break;
                            }
                            if (board[tY][tX] == 0) {  // sea tile
                                visited[tY][tX] = islandNumber;
                                bridge.emplace(tX, tY);
                            }
                            else if (board[tY][tX] == 1) {  // not-calculated island's border
                                minDist = dist;
                                exit = true;
                                break;
                            }
                        }
                        bridge.pop();
                    }
                }
            }
        }
    }
    cout << minDist;
}