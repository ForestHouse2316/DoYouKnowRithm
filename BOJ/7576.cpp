#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
#define row first
#define col second

int N, M, in, tomatoes, ripen=0, cycle=0;
int board[1005][1005];
queue<p> q;
p temp, splitter = {-1, -1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> M;  // X
    cin >> N;  // Y
    tomatoes = N*M;

    q.push(splitter);  // Add this to initially check (ripen == tomatoes) and print 0 if condition satisfied

    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> in;
            board[n][m] = in;
            if (in == 1) {
                ripen++;
                q.emplace(n, m);
            }
            else if (in == -1) {
                tomatoes--;
            }
        }
    }

    if (ripen == 0) {
        // Cannot ripe tomatoes in the box
        cout << -1;
        return 0;
    }

    while (!q.empty()) {
        if (tomatoes == ripen) {
            cout << cycle;
            break;
        }
        if (q.front().row == -1) {
            q.pop();
            if (!q.empty()) {
                q.push(splitter);
                cycle++;
            }
            else cout << -1;
        }
        else {
            temp = q.front();
            q.pop();

            // We can simplify the code below by using an array of pair {1 0 -1 0} {0 1 0 -1}
            if (temp.row > 0 && board[temp.row-1][temp.col] == 0) {
                board[temp.row-1][temp.col] = 1;
                q.emplace(temp.row-1, temp.col);
                ripen++;
            }
            if (temp.col > 0 && board[temp.row][temp.col-1] == 0) {
                board[temp.row][temp.col-1] = 1;
                q.emplace(temp.row, temp.col-1);
                ripen++;
            }
            if (temp.row < N-1 && board[temp.row+1][temp.col] == 0) {
                board[temp.row+1][temp.col] = 1;
                q.emplace(temp.row+1, temp.col);
                ripen++;
            }
            if (temp.col < M-1 && board[temp.row][temp.col+1] == 0) {
                board[temp.row][temp.col+1] = 1;
                q.emplace(temp.row, temp.col+1);
                ripen++;
            }
        }
    }
}