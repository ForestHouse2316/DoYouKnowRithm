#include <bits/stdc++.h>
using namespace std;
int N, T, X, Y, point=0;
int boards[2][6][4] = {}; // boards[gb][long-edge][short-edge]

int checkOverflow(int gb) {
    int (&board)[6][4] = boards[gb];
    for (int tile : board[0]) if (tile > 0) return 2;
    for (int tile : board[1]) if (tile > 0) return 1;
    return 0;
}

void _gravity(int gb) {
    int (&board)[6][4] = boards[gb];
    for (int a = 4; a >= 0; --a) {
        for (int b = 0; b < 4; ++b) {
            if (board[a][b] == 0) continue;
            else if (board[a][b] == 1) { // single block
                int push = 0;
                while (board[a + push + 1][b] == 0 && a + push < 5) push++;
                board[a][b] = 0;
                board[a + push][b] = 1;
            }
            else { // linked block, cannot enter when b == 3
                int push[2] = {};
                for (int i = 0; i < 2; ++i) while (board[a + push[i] + 1][b+i] == 0 && a + push[i] < 5) push[i]++;
                int pushMin = min(push[0], push[1]);
                board[a][b] = board[a][b+1] = 0;
                board[a + pushMin][b] = board[a + pushMin][b+1] = 2;

                b++; // JUMP
            }
        }
    }
}

void _score(int gb) {
    bool cleared = false;
    int (&board)[6][4] = boards[gb];
    for (int a = 2; a < 6; ++a) {
        bool complete = true;
        for (int b = 0; b < 4; ++b) {
            complete &= board[a][b] > 0; // >
        }
        if (complete) {
            cleared = true;
            point++;
            for (int b = 0; b < 4; ++b) board[a][b] = 0;
        }
    }

    if (cleared) { // if scored, calculate gravity and score again
        _gravity(gb);
        _score(gb);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    while (N--) {
        cin >> T >> Y >> X; // X is column when the board is green
        switch (T) {
            case 1:
                boards[0][1][X] = boards[1][1][Y] = 1;
                break;
            case 2:
                boards[0][1][X] = boards[0][1][X+1] = 2;
                boards[1][0][Y] = boards[1][1][Y] = 1;
                break;
            case 3:
                boards[0][0][X] = boards[0][1][X] = 1;
                boards[1][1][Y] = boards[1][1][Y+1] = 2;
                break;
        }
        for (int gb = 0; gb < 2; ++gb) {
            _gravity(gb);
            _score(gb);
            int overflow = checkOverflow(gb);
            if (overflow > 0) { // overflow cutoff
                for (int i = 5; i > 1; --i) {
                    memcpy(boards[gb][i], boards[gb][i-overflow], sizeof(int[4]));
                }
                fill(boards[gb][0], boards[gb][0] + 4, 0);
                fill(boards[gb][1], boards[gb][1] + 4, 0);
            }
        }
    }

    // count tiles
    int tileNum = 0;
    for (int gb = 0; gb < 2; ++gb) {
        for (int a = 2; a < 6; ++a) {
            for (int b = 0; b < 4; ++b) {
                tileNum += boards[gb][a][b] > 0;
            }
        }
    }
    cout << point << '\n' << tileNum;
}