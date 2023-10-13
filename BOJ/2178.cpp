#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
#define row first
#define col second

int board[105][105];  // 1-indexed
bool visited[105][105] = {false};  // 1-indexed
bool found = false;
int N, M;
int depth = 0;
string in;
queue<p> bfsQ;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;

    for (int n = 1; n <= N; n++) {
        cin >> in;
        for (int m = 1; m <= M; m++) {
            board[n][m] = in[m-1] - '0';
            if (board[n][m] == 0) visited[n][m] = true;
        }
    }

    p temp;
    bfsQ.emplace(1,1);
    bfsQ.emplace(0,0);
    visited[1][1] = true;
    while (true) {
        depth++;
        while(bfsQ.front().row != 0) {
            temp = bfsQ.front();
            bfsQ.pop();
            if (temp.row == N && temp.col == M) {
                found = true;
                break;
            }

            if (temp.row < N && !visited[temp.row+1][temp.col]) {
                bfsQ.emplace(temp.row+1, temp.col);
                visited[temp.row+1][temp.col] = true;
            }
            if (temp.row > 1 && !visited[temp.row-1][temp.col]) {
                bfsQ.emplace(temp.row-1, temp.col);
                visited[temp.row-1][temp.col] = true;
            }
            if (temp.col < M && !visited[temp.row][temp.col+1]) {
                bfsQ.emplace(temp.row, temp.col+1);
                visited[temp.row][temp.col+1] = true;
            }
            if (temp.col > 1 && !visited[temp.row][temp.col-1]) {
                bfsQ.emplace(temp.row, temp.col-1);
                visited[temp.row][temp.col-1] = true;
            }
        }

        if (found) break;

        bfsQ.pop();
        bfsQ.emplace(0,0);
    }

    cout << depth;
}