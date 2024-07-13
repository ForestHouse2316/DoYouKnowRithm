#include <bits/stdc++.h>
using namespace std;
#define X first
#define Y second
typedef pair<int, int> pii;

int N, result[2] = {0};
vector<pii> ableGroup[20]; // 1-valued cells on \ diagonal line
bool able, diagonalOccupation[20] = {false}; // occupation of / diagonal line

void rec(int start, int cnt, int r) {
    if (start >= N*2) {
        result[r] = max(result[r], cnt);
        return;
    }
    for (pii cell : ableGroup[start]) {
        if (diagonalOccupation[cell.X + cell.Y]) continue;
        diagonalOccupation[cell.X + cell.Y] = true;
        rec(start+2, cnt+1, r);
        diagonalOccupation[cell.X + cell.Y] = false;
    }
    rec(start+2, cnt, r);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> able;
            if (able) {
                ableGroup[N + y - x - 1].emplace_back(x, y);
            }
        }
    }

    rec(0, 0, 0);
    rec(1, 0, 1);
    cout << result[0] + result[1];
}