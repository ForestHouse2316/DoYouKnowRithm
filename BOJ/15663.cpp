#include <bits/stdc++.h>
using namespace std;

int N, M, nums[8], comb[8];
bool occupy[8] = {false}; // occupy[index]

void rec(int depth) {
    if (depth == M) {
        for (int m = 0; m < M; ++m) {
            cout << comb[m] << " ";
        }
        cout << "\n";
        return;
    }

    int prev = -1;
    for (int n = 0; n < N; ++n) {
        if (prev == nums[n] || occupy[n]) continue;

        occupy[n] = true;
        prev = nums[n];
        comb[depth] = nums[n];
        rec(depth+1);
        occupy[n] = false;
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int n = 0; n < N; ++n) {
        cin >> nums[n];
    }

    sort(nums, nums+N);
    rec(0);
}