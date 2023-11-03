#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
int N, K, tP, lMAX, loop, tracker, times = 0, dist[MAX], previous[MAX];
queue<int> q;


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;

    if (N > K) {
        cout << N-K << '\n';
        for (int i = N; i >= K; i--) {
            cout << i << " ";
        }
        return 0;
    }

    lMAX = max(N, K) *2;
    fill(dist, dist + lMAX, -1);
    dist[N] = 0;
    q.push(N);
    while (!q.empty()) {
        times++;
        loop = q.size();
        for (int l = 0; l < loop; l++) {
            for (int i : {-1, 1, q.front()}) {
                tP = q.front() + i;
                if (tP < 0 || tP > lMAX || dist[tP] != -1) continue;

                dist[tP] = times;
                previous[tP] = q.front();
                q.push(tP);
            }
            q.pop();
        }
    }

    tracker = K;
    for (int i = dist[K]; i >= 0; i--) {
        dist[i] = tracker;
        tracker = previous[tracker];
    }

    cout << dist[K] << '\n';
    for (int i = 0; i <= dist[K]; i++) {
        cout << dist[i] << " ";
    }
}