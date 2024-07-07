#include <bits/stdc++.h>
using namespace std;
#define a first
#define b second
typedef pair<int, int> pii;

int T, N, board[2][100'000], dp[3], temp[3]; // Top / Bottom / None


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
        cin >> N;
        for (int i = 0; i < 2; ++i) {
            for (int n = 0; n < N; ++n) {
                cin >> board[i][n];
            }
        }

        dp[0] = board[0][0];
        dp[1] = board[1][0];
        dp[2] = 0;
        for (int n = 1; n < N; ++n) {
            temp[0] = max(dp[1], dp[2]) + board[0][n];
            temp[1] = max(dp[0], dp[2]) + board[1][n];
            temp[2] = max(max(dp[0], dp[1]), dp[2]);
            copy(temp, temp+3, dp);
        }

        cout << max(max(dp[0], dp[1]), dp[2]) << "\n";
    }
}