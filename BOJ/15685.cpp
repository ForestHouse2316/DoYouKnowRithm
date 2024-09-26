#include <bits/stdc++.h>
using namespace std;
#define R 0
#define U 1
#define L 2
#define D 3

int N, x, y, d, g, result=0;
bool board[101][101] = {false};

void move(int dir) {
    switch (dir) {
        case R:
            x++;
            break;
        case U:
            y--;
            break;
        case L:
            x--;
            break;
        case D:
            y++;
            break;
    }
}

void draw() {
    vector<int> movedDir; movedDir.reserve(10);
    movedDir.push_back(d);
    board[y][x] = true;
    move(d); // 0th gen
    board[y][x] = true;

    for (int rot = 1; rot <= g; ++rot) {
        for (int i = movedDir.size()-1; i >= 0 ; --i) {
            int rotatedDir = (movedDir[i]+1)%4;
            move(rotatedDir);
            board[y][x] = true;
            movedDir.push_back(rotatedDir);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> x >> y >> d >> g;
        draw();
    }

    for (int a = 0; a < 100; ++a) {
        for (int b = 0; b < 100; ++b) {
            if (board[a][b] && board[a+1][b] && board[a][b+1] && board[a+1][b+1]) result++;
        }
    }

    cout << result;
}