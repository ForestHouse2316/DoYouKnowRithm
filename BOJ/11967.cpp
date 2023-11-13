#include <bits/stdc++.h>
using namespace std;
typedef pair<short, short> p;
#define X first
#define Y second
queue<p> q;
queue<p> linking;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
int N, M, x, y, a, b, tX, tY, lights = 0;
bool linkFound, unlinkFound;
short board[105][105] = {0};  // 1-indexed
// board value means:
// 0 - light off
// 1 - light on
// 2 - non-accessible room
vector<p> switches[105][105];  // switches[Y][X] pair<X, Y>

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    board[1][1] = 1;
    lights++;
    cin >> N >> M;
    for (int m = 0; m < M; m++) {
        cin >> x >> y >> a >> b;
        switches[y][x].emplace_back(a, b);
    }

    q.emplace(1, 1);
    while(!q.empty()) {
        for (p dest : switches[q.front().Y][q.front().X]) {  // turn on the switches respectively
            if (board[dest.Y][dest.X] != 0) continue;

            // turn on the switch & count light
            board[dest.Y][dest.X] = 2;
            lights++;

            // check accessibility
            linkFound = false, unlinkFound = false;
            for (int i = 0; i < 4; i++) {
                tX = dest.X + maskX[i];
                tY = dest.Y + maskY[i];
                if (tX <= 0 || tY <= 0 || tX > N || tY > N || board[tY][tX] == 0) continue;
                linkFound = linkFound || board[tY][tX] == 1;
                unlinkFound = unlinkFound || board[tY][tX] == 2;
            }

            if (!linkFound) continue;  // if there's no link
            board[dest.Y][dest.X] = 1;
            q.push(dest);

            if (!unlinkFound) continue;  // if there's no unlinked room

            linking.emplace(dest.X, dest.Y);
            while(!linking.empty()) {
                for (int i = 0; i < 4; i++) {
                    tX = linking.front().X + maskX[i];
                    tY = linking.front().Y + maskY[i];
                    if (tX <= 0 || tY <= 0 || tX > N || tY > N || board[tY][tX] != 2) continue;

                    board[tY][tX] = 1;
                    q.emplace(tX, tY);
                    linking.emplace(tX, tY);
                }
                linking.pop();
            }
        }
        q.pop();
    }
    cout << lights;
}