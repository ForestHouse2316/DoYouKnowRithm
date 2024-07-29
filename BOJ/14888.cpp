#include <bits/stdc++.h>
using namespace std;

int N, nums[11], in, numOps = 0, op[10] = {0}, M = INT_MIN, m = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) cin >> nums[n];
    for (int i = 0; i < 4; ++i) {
        cin >> in;
        while (in--) op[numOps++] = i;
    }

    do {
        int result = nums[0];
        for (int n = 1; n < N; ++n) {
            switch (op[n-1]) {
                case 0: result += nums[n];
                    break;
                case 1: result -= nums[n];
                    break;
                case 2: result *= nums[n];
                    break;
                case 3: result /= nums[n];
                    break;
            }
        }

        M = max(result, M);
        m = min(result, m);
    } while (next_permutation(op, op + N - 1));

    cout << M << '\n' << m;
}