#include <bits/stdc++.h>
using namespace std;
#define W 0
#define V 1

int N, K, loop, maxV=0, items[100][2], dp[100005] = {0}, temp[100005] = {0}; // dp[weight] = value
vector<int> existW;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    existW.reserve(100005); existW.push_back(0);
    cin >> N >> K;
    for (int n = 0; n < N; ++n) {
        cin >> items[n][W] >> items[n][V];
    }

    for (auto item: items) {
        if (item[V] == 0) continue; // trash
        loop = existW.size();
        for (int i = 0; i < loop; ++i) { // DO NOT USE ENHANCED FOR STATEMENT (internal update)
            int nextW = existW[i] + item[W];
            if (nextW > K) continue;

            if (dp[nextW] == 0) existW.push_back(nextW); // internal update
            temp[nextW] = max(dp[nextW], dp[existW[i]] + item[V]); // original V.S. nextV
        }
        copy(temp, temp+100005, dp);
    }

    for (auto w : existW) {
        maxV = max(maxV, dp[w]);
    }
    cout << maxV;
}