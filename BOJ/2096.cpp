#include <bits/stdc++.h>
using namespace std;

int N, dpmax[3], dpmin[3], temp[3], a, b, c;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 1; n <= N; ++n) {
        cin >> a >> b >> c;
        // max
        temp[0] = max(dpmax[0], dpmax[1]) + a;
        temp[1] = max(max(dpmax[0], dpmax[1]), dpmax[2]) + b;
        temp[2] = max(dpmax[1], dpmax[2]) + c;
        copy(temp, temp+3, dpmax);
        // min
        temp[0] = min(dpmin[0], dpmin[1]) + a;
        temp[1] = min(min(dpmin[0], dpmin[1]), dpmin[2]) + b;
        temp[2] = min(dpmin[1], dpmin[2]) + c;
        copy(temp, temp+3, dpmin);
    }

    cout << max(max(dpmax[0], dpmax[1]), dpmax[2]) << " " << min(min(dpmin[0], dpmin[1]), dpmin[2]);
}