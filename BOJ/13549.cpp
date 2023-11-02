#include <bits/stdc++.h>
#define MAX 200000
using namespace std;
int N, K, f, dist[MAX + 5], mask[2] = {1, -1};
deque<int> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> K;
    fill(dist, dist+MAX+5+1, -1);
    dist[N] = 0;

    if (N >= K) {  // There's no way to move faster than this if (N > K)
        cout << N - K;
        return 0;
    }

    d.push_front(N);
    while (!d.empty()) {
        f = d.front();
        d.pop_front();

        // *2
        if (f*2 < MAX && dist[f*2] == -1) {
            dist[f*2] = dist[f];
            d.push_front(f*2);
        }
        // +-1
        for (int tf : {f+1, f-1}) {
            if (0 > tf || tf > MAX) continue;
            if (dist[tf] != -1 && dist[tf] <= dist[f]+1) continue;
            dist[tf] = dist[f]+1;
            d.push_back(tf);
        }
    }
    cout << dist[K];
}