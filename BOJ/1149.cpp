#include <bits/stdc++.h>
using namespace std;
int N;
int cost[1000][3];  // [house num][color]
int sum[1000][3];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; n++) {
        for (int c = 0; c < 3; c++) {
            cin >> cost[n][c];
        }
    }
    sum[0][0] = cost[0][0];
    sum[0][1] = cost[0][1];
    sum[0][2] = cost[0][2];
    for (int i = 1; i < N; i++) {
        for (int c = 0; c < 3; c++) {
            sum[i][c] = min(sum[i-1][(c+1)%3], sum[i-1][(c+2)%3]) + cost[i][c];
        }
    }
    cout << *min_element(sum[N-1], sum[N-1]+3);
}