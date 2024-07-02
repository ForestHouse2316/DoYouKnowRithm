#include <bits/stdc++.h>
using namespace std;

int N, M, nums[8] = {}, np[8] = {};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M;

    for (int n = 0; n < N; ++n) {
        cin >> nums[n];
    }
    
    sort(nums, nums+N);
    for (int n = M; n < N; ++n) {
        np[n] = 1;
    }
    
    do {
        for (int n = 0; n < N; ++n) {
            if (np[n] == 0) cout << nums[n] << " ";
        }
        cout << "\n";
    } while (next_permutation(np, np+N));
}