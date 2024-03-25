#include <bits/stdc++.h>
#define P (-1)
#define G 0
#define MAX_ALT 1000000
#define X first
#define Y second
using namespace std;
typedef pair<int, int> pii;

int N, pkMax = 0, pkMin = MAX_ALT, gMax = 0, gMin = MAX_ALT, numK = 0, in, fatigue = MAX_ALT, numVisK, tx, ty, sB, eB, sT, eT, limB, limT;
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
    return numK == numVisK;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
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

    // TODO
    // limT와 limB의 BS 는 실패했다.
    // 그렇다면 limB와 range 에 대해 BS를 한다면?
    // range를 밖에 두고 limB에 대해 BS를 해가며 한 케이스라도 성공하면 바로 range 쪼임
    // 그리고 limB는 항상 gMin~pkMin 범위에 대해서 BS 할것
    sB = gMin;
    eB = pkMin;
    while (sB <= eB) {
        success = false;
        limB = (sB+eB)/2;

        sT = pkMax;
        eT = fatigue == MAX_ALT ? gMax : sT + fatigue;
        while (sT <= eT) {
            limT = (sT+eT)/2;

            if (bfs()) {
                eT = limT - 1;
                if (limT - limB < fatigue) {
                    success = true;
                    fatigue = limT - limB;
                }
            }
            else sT = limT + 1;
        }

        if (success) sB = limB + 1;
        else eB = limB - 1;
    }

    cout << fatigue;
}