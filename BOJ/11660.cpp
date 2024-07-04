#include <bits/stdc++.h>
using namespace std;

short board[1025][1025]; // 1-indexed
unsigned int sum[1025][1025] = {0}; // 1-indexed
int N, M, X1, Y1, X2, Y2;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int x = 1; x <= N; ++x) { // x = row
        for (int y = 1; y <= N; ++y) { // y = col
            cin >> board[y][x];
            sum[y][x] = board[y][x] + sum[y-1][x] + sum[y][x-1] - sum[y-1][x-1];
        }
    }

    while (M--) {
        cin >> X1 >> Y1 >> X2 >> Y2;
        cout << sum[Y2][X2] - sum[Y1-1][X2] - sum[Y2][X1-1] + sum[Y1-1][X1-1] << "\n";
    }
}