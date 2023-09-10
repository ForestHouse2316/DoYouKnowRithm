#include <bits/stdc++.h>
#define isPicture first
#define visited second

using namespace std;

pair<int, bool> board[502][502];
const pair<int, bool> SEARCHABLE = {1, false};
int pictureNum = 0;
int maxSize = 0;

void bfs(int iX, int iY) {
    // By considering "SPEED" and time complexity, I attached /visited=ture/ after queue.emplace
    // If we not consider those, we may use (pop -> check visited) process. But this will execute redundant queue operations.

    pictureNum++;
    int size = 0;
    queue<pair<int, int>> bfsQueue;  // x & y
    bfsQueue.emplace(iX, iY);
    board[iY][iX].visited = true;

    do {
        int x = bfsQueue.front().first;
        int y = bfsQueue.front().second;
        bfsQueue.pop();
        size++;

        // upward
        if (y-1>=0 && board[y-1][x] == SEARCHABLE) {
            bfsQueue.emplace(x, y - 1);
            board[y-1][x].visited = true;
        }
        // leftward
        if (x-1>=0 && board[y][x-1] == SEARCHABLE) {
            bfsQueue.emplace(x - 1, y);
            board[y][x-1].visited = true;
        }
        // downward - since stack size is bigger than input limit, we don't have to consider null check
        if (board[y+1][x] == SEARCHABLE) {
            bfsQueue.emplace(x, y + 1);
            board[y+1][x].visited = true;
        }
        // rightward - since stack size is bigger than input limit, we don't have to consider null check
        if (board[y][x+1] == SEARCHABLE) {
            bfsQueue.emplace(x + 1, y);
            board[y][x+1].visited = true;
        }

    } while (!bfsQueue.empty());

    maxSize = max(size, maxSize);
}

int main() {
    int row, col;
    cin >> row; cin >> col;

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            cin >> board[y][x].isPicture;
        }
    }

    for (int y = 0; y < row; y++) {
        for (int x = 0; x < col; x++) {
            if (board[y][x] == SEARCHABLE) {
                bfs(x, y);
            }
        }
    }

    cout << pictureNum << endl;
    cout << maxSize << endl;
}