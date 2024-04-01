#include <bits/stdc++.h>
using namespace std;
#define x first.first
#define y first.second
#define d second.first
#define a second.second
#define f q.front()
typedef pair<int, int> pii;
int N, M, depth, board[502][502], sum = 0, nearSum;
vector<int> tAcc;
bool started[502][502] = {false}, vis[502][502];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
queue<pair<pii, pii>> q;
pair<pii, pii> t;


void dfs(int acc) {
    if (s.size() >= 4) {
        sum = max(sum, acc);
        return;
    }

    for (int i = 0; i < 4; ++i) {
        t.x = t.x + dx[i];
        t.y = t.y + dy[i];
        if (t.x < 0 || t.y < 0 || t.x >= M || t.y >= N || vis[t.y][t.x] || started[t.y][t.x]) continue;
        vis[t.y][t.x] = true;
        s.emplace(t.x, t.y);
        dfs(acc + board[t.y][t.x]);
        s.pop();
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    tAcc.reserve(4);
    cin >> N >> M;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> board[n][m];
        }
    }


    for (int sn = 0; sn < N; ++sn) {
        for (int sm = 0; sm < M; ++sm) {
            for (int init = 0; init < N; ++init) {
                fill(vis[init], vis[init]+M, false);
            }
            q.emplace(make_pair(sm, sn), make_pair(1, board[sn][sm]));
            started[sn][sm] = true;
            while (!q.empty()) {
                tAcc.clear();
                for (int i = 0; i < 4; ++i) {
                    t.x = f.x + dx[i];
                    t.y = f.y + dy[i];
                    t.d = f.d + 1; // Instead, we can use q.size() based loop to count depth of the queue.
                    t.a = f.a + board[t.y][t.x];
                    if (t.x < 0 || t.y < 0 || t.x >= M || t.y >= N || vis[t.y][t.x] || started[t.y][t.x]) continue;
                    vis[t.y][t.x] = true;

                    if (t.d == 4) {
                        sum = max(sum, t.a);
                        continue;
                    }
                    tAcc.push_back(t.a);
                    q.push(t);
                }
                if (tAcc.size() + f.d >= 4) {
                    sort(tAcc.begin(), tAcc.end());
                    nearSum = 0;


                }
                q.pop();
            }

        }
    }
    cout << sum;
}