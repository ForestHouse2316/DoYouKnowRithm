#include <bits/stdc++.h>
using namespace std;

int N, M, K;  // Row Col StickerNum
int board[40][40] = {false};  // [Row][Col]
int sticker[10][10] = {false};
int RI;
int CI;

void rotateSticker() {
    int temp[10][10] = {0};
    for (int r = 0; r < RI; r++) {
        for (int c = 0; c < CI; c++) {
            temp[r][c] = sticker[r][c];
        }
    }
    for (int r = 0; r < RI; r++) {
        for (int c = 0; c < CI; c++) {
            sticker[c][RI-1-r] = temp[r][c];
        }
    }
    swap(RI, CI);
}

bool tryPutting(int stdR, int stdC) {
    if (!(stdR + RI > N || stdC + CI > M)) {
        for (int r = 0; r < RI; r++) {
            for (int c = 0; c < CI; c++) {
                if (sticker[r][c] == 1 && board[stdR+r][stdC+c] == 1) return false;
            }
        }
        for (int r = 0; r < RI; r++) {
            for (int c = 0; c < CI; c++) {
                if (sticker[r][c] == 1) board[stdR+r][stdC+c] = 1;
            }
        }
        return true;
    }
    return false;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;
    cin >> K;
    bool put;

    for (int k = 0; k < K; k++) {
        cin >> RI;
        cin >> CI;
        for (int ri = 0; ri < RI; ri++) {
            for (int ci = 0; ci < CI; ci++) {
                cin >> sticker[ri][ci];
            }
        }
        put = false;
        for (int rotation = 0; rotation < 4; rotation++) {
            if (put) break;
            for (int r = 0; r < N; r++) {
                if (put) break;
                for (int c = 0; c < M; c++) {
                    if (tryPutting(r, c)) {
                        put = true;
                        break;
                    }
                }
            }
            rotateSticker();
        }
//        for (int y = 0; y < N; y++) {
//            for (int x = 0; x < M; x++) {
//                cout << (board[y][x] ? "■" : "·") << " ";
//            }
//            cout << "\n";
//        }
//        cout << "------------\n";
    }

    int sum=0;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < M; c++) {
            sum += board[r][c];
        }
    }
    cout << sum << "\n";
}