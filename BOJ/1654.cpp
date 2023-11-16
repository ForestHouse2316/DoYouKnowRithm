#include <bits/stdc++.h>
using namespace std;
int K, N, sum, maxLen = 0, maxCutLen = 0, len[10002];
unsigned int s, m, e;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> K >> N;
    for (int k = 0; k < K; k++) {
        cin >> len[k];
        maxLen = max(maxLen, len[k]);
    }
    s = 1;
    e = maxLen;
    while (s <= e) {
        sum = 0;
        m = (s+e)/2;
        for (int k = 0; k < K; k++) {
            sum += len[k]/m;
        }
        if (sum >= N) {
            maxCutLen = m;
            s = m+1;
        }
        else e = m-1;
    }
    cout << maxCutLen;
}