#include <bits/stdc++.h>
using namespace std;
int N, K, coin[10], scale, num = 0, sum = 0;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int n = 0; n < N; ++n) {
        cin >> coin[n];
    }

    scale = N - 1;
    while (sum != K) {
        while (K - sum < coin[scale]) scale--;
        sum += coin[scale];
        num++;
    }

    cout << num;
}