#include <bits/stdc++.h>
#define DEPTH_LIMIT 6
using namespace std;

int N;
int board[6][20][20] = {0};  // [Moved Time][Row][Col]
int maxBlock = 0;
int boardHis[5][20][20] = {0};

void debug(int n) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << board[n][i][j] << " ";
        }
        cout << "\n";
    }
    cout << "--------------\n";
}

void rotateBoard(int boardNum) {
    // Rotate selected board for 90deg(CW)
    int temp[20][20];
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            temp[j][N-1-i] = board[boardNum][i][j];
        }
    }
    swap(temp, board[boardNum]);
}

void swipe(int nthSwipe) {
    if (nthSwipe == DEPTH_LIMIT) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                maxBlock = max(maxBlock, board[nthSwipe-1][i][j]);
            }
        }
        return;
    }

    for (int dir = 0; dir < 4; dir++) {

        // Copy
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                board[nthSwipe][i][j] = board[nthSwipe-1][i][j];
            }
        }

        // Assemble "Once" to leftward
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N-1; j++) {
                if (board[nthSwipe][i][j] == 0) {
                    for (int k = j+1; k < N; k++) {
                        if (board[nthSwipe][i][k] != 0) {
                            // If [j] == 0, pull leftest block
                            swap(board[nthSwipe][i][j], board[nthSwipe][i][k]);
                            j--;  // IMPORTANT : Because [j] was 0, we need to check whether swapped [j] is combinable with next [k]
                            break;  // j++
                        }
                    }
                }
                else {
                    for (int k = j+1; k < N; k++) {
                        if (board[nthSwipe][i][k] == 0) continue;  // k++
                        if (board[nthSwipe][i][k] == board[nthSwipe][i][j]) {
                            // If [j] != 0 && [j] == [k] assemble!
                            board[nthSwipe][i][j] *= 2;
                            board[nthSwipe][i][k] = 0;
                            break;  // j++
                        }
                        // If [j] != 0 && [j] != [k], pull [k] to [j+1]
                        swap(board[nthSwipe][i][board[nthSwipe][i][j] == 0 ? j : j+1], board[nthSwipe][i][k]);
                        // Else, we don't have to move the block. It's already sorted well.
                        break;  // j++
                    }
                }
            }

        }

        swipe(nthSwipe+1);

        rotateBoard(nthSwipe-1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[0][i][j];
        }
    }

    swipe(1);

    cout << maxBlock << "\n";
}