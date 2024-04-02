#include <bits/stdc++.h>
#define f q.front()
using namespace std;
// 1-indexed
unsigned short N, L, a, b, link[101][101], linkSize[101] = {0}, num = 0; // link[from][n] = link to (link destination)
bool vis[101] = {false};
queue<unsigned short> q;


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for (int l = 0; l < L; ++l) {
        cin >> a >> b;
        link[a][linkSize[a]++] = b;
        link[b][linkSize[b]++] = a;
    }

    q.push(1);
    vis[1] = true;
    while (!q.empty()) {
        for (int i = 0; i < linkSize[f]; ++i) {
            if (vis[link[f][i]]) continue;
            vis[link[f][i]] = true;
            num++;
            q.push(link[f][i]);
        }
        q.pop();
    }
    cout << num;
}