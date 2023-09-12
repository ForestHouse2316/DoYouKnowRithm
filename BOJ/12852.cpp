#include <bits/stdc++.h>
using namespace std;
int N;
int dp[1000001];
int history[1000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 1;
    history[1] = 0;
    history[2] = 2;
    history[3] = 3;
    for (int i = 4; i <= N; i++) {
        dp[i] = dp[i-1]+1;
        history[i] = 1;
        if (i%2==0) {
            if (dp[i] > dp[i/2]+1) {
                dp[i] = dp[i/2]+1;
                history[i] = 2;
            }
        }
        if (i%3==0) {
            if (dp[i] > dp[i/3]+1) {
                dp[i] = dp[i/3]+1;
                history[i] = 3;
            }
        }
    }
    cout << dp[N] << "\n";
    int n = N;
    while (history[n] > 0) {
        cout << n << " ";
        if (history[n] == 1) n--;
        else n /= history[n];
    }
    cout << 1;
}