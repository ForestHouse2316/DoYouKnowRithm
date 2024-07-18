#include <bits/stdc++.h>
#define diceT diceV[top]
#define diceB diceV[bot()]
using namespace std;

int N, M, x, y, K, cmd, board[20][20], top = 0, diceV[4] = {0}, diceL = 0, diceR = 0; // diveV[topIdx + 2] is bottom.

int bot() { return (top + 2) % 4; }

void roll(int dir) {
    int temp;
    switch (dir) {
        case 1:
            temp = diceT;
            diceT = diceL;
            diceL = diceB;
            diceB = diceR;
            diceR = temp;
            break;
        case 2:
            temp = diceT;
            diceT = diceR;
            diceR = diceB;
            diceB = diceL;
            diceL = temp;
            break;
        case 3:
            top = (top+1)%4;
            break;
        case 4:
            top = (top+3)%4;
            break;
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> y >> x >> K;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> board[n][m];
        }
    }

    while (K--) {
        cin >> cmd;
        if (cmd == 1 && x < M-1) x++;
        else if (cmd == 2 && x > 0) x--;
        else if (cmd == 3 && y > 0) y--;
        else if (cmd == 4 && y < N-1) y++;
        else continue;

        roll(cmd);
        if (board[y][x] == 0) board[y][x] = diceB;
        else {
            diceB = board[y][x];
            board[y][x] = 0;
        }
        cout << diceT << '\n';
    }
}