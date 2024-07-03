#include <bits/stdc++.h>
using namespace std;

int K, nums[12], comb[6];

void rec(int start, int depth) {
    if (depth == 6) {
        for (int i : comb) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < K; ++i) {
        comb[depth] = nums[i];
        rec(i+1, depth+1);
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    while(true) {
        cin >> K;
        if (K == 0) break;

        for (int k = 0; k < K; ++k) {
            cin >> nums[k];
        }

        sort(nums, nums+K);
        rec(0, 0);
        cout << "\n";
    }
}