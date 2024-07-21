#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

vector<int> connection[200005];
int N, M, R, a, b, loop, depth = 0, dist[200005];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> R;
    fill(dist, dist+N+5, -1);
    for (int m = 0; m < M; ++m) {
        cin >> a >> b;
        connection[a].push_back(b);
        connection[b].push_back(a);
    }

    q.push(R);
    dist[R] = 0;
    while (!q.empty()) {
        loop = q.size();
        depth++;
        while (loop--) {
            for (int node : connection[q.front()]) {
                if (dist[node] != -1) continue;
                q.push(node);
                dist[node] = depth;
            }
            q.pop();
        }
    }

    for (int n = 1; n <= N; ++n) {
        cout << dist[n] << '\n';
    }
}