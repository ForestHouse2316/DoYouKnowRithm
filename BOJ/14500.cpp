#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, M, board[502][502], sum = 0, lsum, tx, ty;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
int shapes[][3] = {{ 2,2,2},
                   {4,4,4},
                   {2,2,0},
                   {2,2,4},
                   {6,6,0},
                   {6,6,4},
                   {2,0,0},
                   {2,4,4},
                   {6,0,0},
                   {6,4,4},
                   {2,2,7},
                   {2,2,5},
                   {4,4,7},
                   {4,4,1},
                   {2,4,6},
                   {2,0,2},
                   {2,4,2},
                   {4,6,4},
                   {4,2,4}};
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> board[n][m];
        }
    }
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            for(auto shape : shapes) {
                tx = m; ty = n;
                lsum = board[n][m];
                for (int i = 0; i < 3; ++i) {
                    tx += dx[shape[i]]; ty += dy[shape[i]];
                    if (tx < 0 || ty < 0 || tx >= M || ty >= N) break;
                    lsum += board[ty][tx];
                }
                sum = max(lsum, sum);
            }
        }
    }

    cout << sum;
}