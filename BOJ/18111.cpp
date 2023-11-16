#include <bits/stdc++.h>
using namespace std;
int N, M, B, tH, tS, height[502][502], minH = 256, maxH = 0, minSec = INT_MAX, heightAtMinSec, require[260] = {0};  // 1-indexed (require[260])
// cuz blocks don't be changed in realtime, we may just use prefix sum array (require[260])
// require[height] : required blocks to fully fill up to 'height'

int empty(int h) {  // return the number of the empty spaces btw [minH+1, h]
    return require[h];
}
int blocks(int h) {  // return the number of the blocks placed btw [h,maxH]
    if (h > maxH) return 0;
    return (maxH - h + 1)*N*M - (require[maxH] - require[h-1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M >> B;
    for (int n = 0; n < N; n++) {
        for (int m = 0; m < M; m++) {
            cin >> height[n][m];
            require[height[n][m]+1]++;
            minH = min(minH, height[n][m]);
            maxH = max(maxH, height[n][m]);
        }
    }

    // make prefix sum structure
    int empties = 0;
    for (int i = minH+1; i <= maxH; i++) {
        if (require[i] != 0) {
            empties += require[i];
            require[i] = require[i-1] + empties;
        }
        else require[i] += require[i-1] + empties;
    }

    // based on B, calculate the maximum height we can do flatten process
    tH = maxH;
    while (B + blocks(tH+1) < empty(tH)) {
        tH--;
    }
    while (tH >= 0) {
        tS = empty(tH) + blocks(tH+1)*2;
        if (tS >= minSec) {
            tH--;
            continue;
        }
        minSec = tS;
        heightAtMinSec = tH;
        tH--;
    }
    cout << minSec << " " << heightAtMinSec;
}