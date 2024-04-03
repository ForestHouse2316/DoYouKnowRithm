// Not completed!

#include <bits/stdc++.h>
using namespace std;
//#define f q.front()
#define f q[s].front()
#define df door[s].front()
#define x first
#define y second
typedef pair<int, int> pii;
int T, H, W, times, tx, ty, phase[4] = {0}, vis[102][102], prisoner, source, escaped; // 1-indexed phase[4]
bool met;
char board[102][102];
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> T;
    while (T--) {
//        queue<pii> q;
        queue<pii> q[4]; // 1-indexed
        queue<pii> door[4]; // 1-indexed
        prisoner = 0;
        times = 0;
        escaped = 0;
        met = false;
        cin >> H >> W;
        for (int h = 0; h < H; ++h) {
            fill(vis[h], vis[h]+W, 0);
            for (int w = 0; w < W; ++w) {
                cin >> board[h][w];
                if (board[h][w] == '$') { // prisoner position
                    board[h][w] = '.';
                    q[++prisoner].emplace(w, h);
                    vis[h][w] = prisoner;
                }
                else if (h == 0 || h == H-1 || w == 0 || w == W-1) {
                    if (board[h][w] == '.') {
                        q[3].emplace(w, h);
                        vis[h][w] = 3;
                    }
                    else if (board[h][w] == '#') door[3].emplace(w, h);
                }
            }
        }

        while (escaped < 3) {
            for (int s = 3; s >= 1 && escaped < 3; --s) { // to handle doors on the edge of the board first

                // fluid fill
//                cout << "fill space : " << s << endl;
//                cout << "\t Q = " << q[s].size() << endl;
                while (!q[s].empty() && escaped < 3) {
                    for (int i = 0; i < 4 && escaped < 3; ++i) {
                        tx = f.x + dx[i];
                        ty = f.y + dy[i];
                        if (tx < 0 || ty < 0 || tx >= W || ty >= H || vis[ty][tx] == s || board[ty][tx] == '*') continue;
                        if (met && vis[ty][tx] * s == 2 || escaped > 0 && escaped * 3 == vis[ty][tx] * s) continue; // 1-2 or 3-(1,2) when met/escaped

                        if (vis[ty][tx] == 0) { // not visited
                            if (board[ty][tx] == '#') door[s].emplace(tx, ty); // door
                            else { // fill
                                vis[ty][tx] = s;
                                q[s].emplace(tx, ty);
                            }
                            continue;
                        }
                        // board == '.' & another visited cell
                        if (!met && vis[ty][tx] * s == 2) met = true; // 1 <-> 2
                        else if(s != escaped && vis[ty][tx] * s >= 3) escaped += s; // 3 <-> (1,2)
                        else continue;
                        times += phase[vis[ty][tx]] + phase[s];
                        if (met && escaped > 0) escaped = 3; // linking
                    }
                    q[s].pop();
                }

                // door open
//                cout << "open door : " << s << endl;
                while (!door[s].empty()) {
                    board[df.y][df.x] = '.';
                    vis[df.y][df.x] = s;
                    q[s].emplace(df.x, df.y);
                    door[s].pop();
                }
                phase[s]++;
            }
//            while (!q.empty()) {
//                source = vis[f.y][f.x];
//                if (source == 2 && met) source = 1; // first & second prisoners go together
//                for (int i = 0; i < 4; ++i) {
//                    tx = f.x + dx[i];
//                    ty = f.y + dy[i];
//                    if (tx < 0 || ty < 0 || tx >= W || ty >= H || vis[ty][tx] == source || board[ty][tx] == '*') continue;
//                    if (met && vis[ty][tx] * source == 2) continue;
//
//                    if (board[ty][tx] == '#') door[source].emplace(tx, ty);
//                    else if (vis[ty][tx] != 0) { // diff source
//                        if (!met && vis[ty][tx] * source == 2) {
//                            met = true;
//                            times += phase * 2;
//                        }
//                    }
//                }
//            }
//            // opening doors
//            for (int i = 1; i <= 3; ++i) {
//                while (!door[i].empty()) {
//                    board[df.y][df.x] = '.';
//                    if (vis[df.y][df.x] == 0) vis[df.y][df.x] = (met && i == 2 ? 1 : i);
//                    else {
//                        if (!met && i * vis[df.y][df.x] == 2) met = true;
//                    }
//                }
//            }
        }
        cout << times << "\n";
    }
}