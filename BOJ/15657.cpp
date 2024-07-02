#include <bits/stdc++.h>
using namespace std;

int N, M, nums[8], comb[8];

void rec(int start, int depth) {
    if (depth == M) {
        for (int m = 0; m < M; ++m) {
            cout << comb[m] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < N; ++i) {
        comb[depth] = nums[i];
        rec(i, depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;
    for (int n = 0; n < N; ++n) {
        cin >> nums[n];
    }

    sort(nums, nums+N);
    rec(0, 0);
}