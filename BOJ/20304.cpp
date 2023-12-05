#include <bits/stdc++.h>
using namespace std;
int N, M, P[100000], amp, sum, shift, minSec, maxSec = -1, cSL, tPW;
bool vis[1000001] = {false};
queue<int> q;

int XOR(int a, int b) {  // equal to security distance
    shift = 20;
    sum = 0;
    amp = a ^ b;
    while(shift-- > 0) {
        sum += (amp>>shift)&1;
    }
    return sum;
}

int securityLevel(int pw) {
    minSec = INT_MAX;
    for (int m = 0; m < M; m++) {
        minSec = min(minSec, XOR(pw, P[m]));
    }
    return minSec;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    for (int m = 0; m < M; m++) {
        cin >> P[m];
    }

    for (int p = 0; p < 20; p++) {
        tPW = 1 << p;
        if (tPW > N) break;
        q.push(tPW);
        vis[tPW] = true;
    }
    while(!q.empty()) {  // start BFS about each bit of integer from 0 to 1
        cSL = securityLevel(q.front());
//        cout << "front | cSL > " << q.front() << " " << cSL << endl;
        if (cSL > maxSec) {  // TODO = 인 경우라도 추후에 뒷쪽 비트가 바뀌면서 global minmum에 영향을 미치는 비트가 바뀔 수도 있음
            maxSec = cSL;
            for (int pos = 0; pos < 20; pos++) {
                tPW = q.front() | (1<<pos);
                if (tPW > N) break;
                if (vis[tPW]) continue;  // if tPW == q.front(), it'll be passed by vis[tPW]
                vis[tPW] = true;
                q.push(tPW);
            }
        }
        q.pop();
    }
    cSL = securityLevel(0);
    maxSec = max(cSL, maxSec);

    cout << maxSec;
}