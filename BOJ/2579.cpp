#include <bits/stdc++.h>
using namespace std;
int N;
int stair[301];
int sum[301][3] = {0};  // [stair num][is double?]

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    int in;
    for (int n = 1; n <= N; n++) {
        cin >> in;
        stair[n] = in;
    }
    sum[1][1] = sum[1][2] = stair[1];
    sum[2][1] = stair[2];
    sum[2][2] = stair[1] + stair[2];
    for (int s = 3; s <= N; s++) {
        sum[s][1] = max(sum[s-2][1], sum[s-2][2]) + stair[s];
        sum[s][2] = sum[s-1][1] + stair[s];
    }
    cout << max(sum[N][1], sum[N][2]);
}