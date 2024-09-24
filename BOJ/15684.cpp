#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, H, a, b, minimum = 4;
bool hLine[35][15] = {false};// [row][col] and 1-indexed
vector<pii> availables;

bool available(int row, int col) {
    if (hLine[row][col]) return false;

    // horizontal continuity
    if (1 < col && hLine[row][col - 1]) return false; // L
    if (col < N && hLine[row][col + 1]) return false; // R

    return true;
}

bool check() {
    for (int col = 1; col <= N; ++col) {
        int curCol = col;
        for (int row = 1; row <= H; ++row) {
            if (curCol < N && hLine[row][curCol]) curCol++;
            else if (curCol > 1 && hLine[row][curCol - 1]) curCol--;
        }
        if (curCol != col) return false;
    }
    return true;
}

void backtrack(int depth, int startIndex) {
    if (depth >= minimum) return;

    int row, col;
    for (int i = startIndex; i < availables.size(); ++i) {
        tie(col, row) = availables[i];
        if (row > H || col > N || !available(row, col)) continue;

        hLine[row][col] = true;
        if (check()) {
            minimum = depth; // depth is always smaller than minimum because of if-statement at the top of f(x).
            hLine[row][col] = false;
            return; // reduce depth
        }
        backtrack(depth+1, i+1);
        hLine[row][col] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> H;
    for (int m = 0; m < M; ++m) {
        cin >> a >> b;
        hLine[a][b] = true;
    }

    if (check()) minimum = 0;
    else {
        // initial available
        for (int row = 1; row <= H; ++row) {
            for (int col = 1; col <= N - 1; ++col) {
                if (available(row, col)) availables.emplace_back(col, row);
            }
        }
        backtrack(1, 0);
    }

    cout << (minimum > 3 ? -1 : minimum);
}