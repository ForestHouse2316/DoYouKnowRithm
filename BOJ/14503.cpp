#include <bits/stdc++.h>
using namespace std;
#define X pos.first
#define Y pos.second
typedef pair<int, int> pii;

int N, M, r, c, d, cleaned = 0;
bool wall[50][50], clean[50][50], sus = false;

void move(int dir) {
    dir %= 4;
    switch (dir) {
        case 0:
            r--;
            break;
        case 1:
            c++;
            break;
        case 2:
            r++;
            break;
        case 3:
            c--;
            break;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> r >> c >> d;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> wall[n][m];
            clean[n][m] = wall[n][m]; // set wall as clean
        }
    }

    while (!sus) {
        // 1
        if (!clean[r][c]) {
            clean[r][c] = true;
            cleaned++;
        }

        if (clean[r][c - 1] && clean[r][c + 1] && clean[r - 1][c] && clean[r + 1][c]) { // 2
            move(d+2); // 2-1
            if (wall[r][c]) { // 2-2
                cout << cleaned;
                return 0;
            }
        }
        else { // 3
            d = (d+3)%4; // 3-1
            move(d); // 3-2
            if (clean[r][c]) move(d + 2); // 3-2 rollback, all walls are clean.
        } // 3-3
    }
}