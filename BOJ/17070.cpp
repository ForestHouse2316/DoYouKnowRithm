#include <bits/stdc++.h>
#define H 0
#define V 1
#define D 2
using namespace std;

int N, result=0;
bool wall[17][17]; // 1-indexed

void rec(int x, int y, int dir) {
    if (x == N && y == N) {
        result++;
        return;
    }

    if (dir != V && x < N && !wall[y][x+1]) rec(x+1, y, H);
    if (dir != H && y < N && !wall[y+1][x]) rec(x, y+1, V);
    if (x < N && y < N && !wall[y+1][x+1] && !wall[y][x+1] && !wall[y+1][x]) rec(x+1, y+1, D);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int y = 1; y <= N; ++y) {
        for (int x = 1; x <= N; ++x) {
            cin >> wall[y][x];
        }
    }

    rec(2, 1, H);
    cout << result;
}