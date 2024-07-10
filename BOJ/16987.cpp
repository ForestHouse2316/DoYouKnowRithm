#include <bits/stdc++.h>
using namespace std;

int N, dur[8], wei[8], maxSum = 0;

void rec(int holding) {

    if (holding == N) {
        int sum = 0;
        for (int n = 0; n < N; ++n) {
            sum += (dur[n] <= 0);
        }
        maxSum = max(sum, maxSum);
        return;
    }

    if (dur[holding] <= 0) { // holding egg is already broken
        rec(holding + 1);
        return;
    }

    bool hit = false;
    for (int target = 0; target < N; ++target) {
        if (dur[target] <= 0 || target == holding) continue; // if target is already broken || itself

        dur[holding] -= wei[target]; dur[target] -= wei[holding]; // hit
        hit = true;

        rec(holding + 1);

        dur[holding] += wei[target]; dur[target] += wei[holding]; // recover prev state
    }

    if (!hit) maxSum = max(N - 1, maxSum); // all eggs already broken, except holding one
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> dur[n] >> wei[n];
    }

    if (N > 1) rec(0);
    cout << maxSum;
}