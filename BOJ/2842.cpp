#include <bits/stdc++.h>
#define P (-1)
#define G 0
#define MAX_ALT 1000000
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

int N, pkMax = 0, pkMin = MAX_ALT, gMax = 0, gMin = MAX_ALT, numK = 0, in, fatigue, numVisK, tx, ty, limB, limT, lastLim, tightResultB;
int board[53][53] = {0}, alt[53][53];
char inC;
bool vis[53][53], success;
int dx[] = {0, 1, 1, 1, 0, -1, -1, -1}, dy[] = {1, 1, 0, -1, -1, -1, 0, 1};
queue<pii> q;
pii posP;

bool bfs() {
    numVisK = 0;
    for (int i = 0; i < N; ++i) {
        fill(vis[i], vis[i]+N, false);
    }
    while (!q.empty()) q.pop();

    q.emplace(posP);
    vis[posP.Y][posP.X] = true;
    while (!q.empty() && numK != numVisK) {
        for (int i = 0; i < 8; ++i) {
            tx = q.front().X + dx[i];
            ty = q.front().Y + dy[i];
            if (tx < 0 || ty < 0 || tx >= N || ty >= N || vis[ty][tx] || alt[ty][tx] < limB || alt[ty][tx] > limT) continue;

            vis[ty][tx] = true;
            q.emplace(tx, ty);
            if (board[ty][tx] != G) numVisK++;
        }
        q.pop();
    }
    return numVisK == numK;
}

int tight(int s, int e, bool upward) {
    lastLim = -1;
    int& lim = upward ? limB : limT;

    while (s <= e) {
        lim = (s+e)/2;
        success = bfs();
        if (success) lastLim = lim;
        if (success == upward) s = lim+1;
        else e = lim-1;
    }

    return lastLim;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> inC;
            if (inC == 'P') {
                board[y][x] = P;
                posP = {x, y};
            }
            else if (inC == 'K') board[y][x] = ++numK;
        }
    }

    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < N; ++x) {
            cin >> in;
            alt[y][x] = in;
            gMax = max(gMax, in);
            gMin = min(gMin, in);
            if (board[y][x] != G) {
                pkMax = max(pkMax, in);
                pkMin = min(pkMin, in);
            }
        }
    }

    fatigue = gMax - gMin;
    limB = gMin;
    limT = pkMax;
    while (limB <= pkMin) {
        limT = tight(pkMax, gMax, false); // tight top
        if (limT == -1) break;

        tightResultB = tight(limT - fatigue, pkMin, true); // tight bottom, starts with current minimum altitude range ( = limT - fatigue)
        if (tightResultB != -1) {
            // new minimum fatigue
            fatigue = limT - tightResultB;
            limB = tightResultB + 1;
        }
        else limB = limT - fatigue + 1; // not a new minimum fatigue
    }

    cout << fatigue;
}