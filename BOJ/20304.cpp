#include <bits/stdc++.h>
using namespace std;
int N, M, tPW, in, maxDist = 0, dist[1000005];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    fill(dist, dist+N+5, -1);

    for (int m = 0; m < M; m++) {
        cin >> in;
        q.push(in);
        dist[in] = 0;
    }

    while(!q.empty()) {  // BFS
        for (int shift = 0; shift <= 20; ++shift) {  // 2^19 < 1m < 2^20
            if (q.front() & 1<<shift) tPW = q.front() & ~(1<<shift);
            else tPW = q.front() | 1<<shift;

            if (tPW > N) continue;
            if (dist[tPW] >= 0) continue;

            dist[tPW] = dist[q.front()]+1;
            q.push(tPW);
        }
        q.pop();
    }

    for (int n = 0; n <= N; ++n) {
        maxDist = max(maxDist, dist[n]);
    }
    cout << maxDist;
}