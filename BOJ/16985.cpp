#include <bits/stdc++.h>
using namespace std;
#define X get<0>(q.front())
#define Y get<1>(q.front())
#define Z get<2>(q.front())
typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;

/*
 * s- 접두사는 cube를 조회할 때에만 사용, rot() 함수를 통해 z축에 대해 돌려진 값을 계산해서 넣어야함.
 * t- 접두사는 BFS 용 좌표값을 의미. cube 배열 접근을 제외한 모든 배열에 사용됨.
 *
 * 먼저 레이어(2d 미로)의 모든 가능한 배치를 next_permutation 으로 반복함. 1번부터 5번까지 있다고 할 때 12345 도 해보고 13245 도 해보는 것임
 * 그 뒤에는 BFS 를 해보며 rot() 을 실행함. BFS 시 만약 z축 2에서 멈췄다면, z2에서 z3쪽 레이어를 접근하지 못한다는 뜻이므로 z3의 레이어를 rot() 함.
 * 그리고 그 아래에 있는 모든 레이어의 rotation 값은 다시 0으로 초기화함. 마치 4진수 카운터와 비슷한 느낌임.
 * 만약 z0의 레이어가 한바퀴 다 돌아서 다시 원래상태(4번 돌림)로 돌아왔다면 다음 레이어 배치순서(z축에 대해) 를 적용하고 다시 반복.
 * */
bool cube[5][5][5]; // plate[nth][y][x], (*cube[h])[y][x]
int sx, sy, sz[] = {0, 1, 2, 3, 4}, loop, tx, ty, tz, rotation[5] = {0}, result = -1;
int dx[] = {0, 1, 0, -1, 0, 0}, dy[] = {1, 0, -1, 0, 0, 0}, dz[] = {0, 0, 0, 0, 1 ,-1};



pii rot(int x, int y, int rotateTime) { // rotated x & y coord
    switch (rotateTime) {
        case 0: return {x, y}; // 0
        case 1: return {y, 4-x}; // 90
        case 2: return {4-x, 4-y}; // 180
        case 3: return {4-y, x}; // 270
        default : return {0, 0};
    }
}

bool nextRot(int target) { // rotate target layer based on Z-axis
    rotation[target]++;
    for (int h = 4; h > target && target != 4; --h) rotation[h] = 0; // init the under layers when 4 > target inputted.

    while (rotation[target] == 4 && target > 0) {
        rotation[target] = 0;
        rotation[--target]++; // upper layer +1 rot
    }

    if (rotation[0] != 4) return true;

    fill(rotation, rotation+4, 0);
    return false;
}

int bfs() { // returns maximum reached Z-axis (but if maxH is 4, returns 3 exceptionally)
    int depth = 0, maxH = 0;
    bool vis[5][5][5] = {false};
    queue<piii> q;
    tie(sx, sy) = rot(0, 0, rotation[0]);
    if (!cube[sz[0]][sy][sx]) return -1;

    vis[0][0][0] = true;
    q.emplace(0, 0, 0);

    while(!q.empty()) {
        loop = q.size();
        depth++;
        while (loop--) {
            for (int i = 0; i < 6; ++i) {
                tx = X + dx[i];
                ty = Y + dy[i];
                tz = Z + dz[i];
                tie(sx, sy) = rot(X + dx[i], Y + dy[i], rotation[tz]);
                if (tx < 0 || ty < 0 || tz < 0 || tx >= 5 || ty >= 5 || tz >= 5 || vis[tz][ty][tx] || !cube[sz[tz]][sy][sx]) continue;
                if (tx == ty && tx == tz && tx == 4) {
                    if (result == -1) result = depth;
                    else result = min(result, depth);
                    return 3;
                }

                vis[tz][ty][tx] = true;
                q.emplace(tx, ty, tz);
                maxH = max(maxH, tz);
            }
            q.pop();
        }
    }
    return min(3, maxH);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int n = 0; n < 5; ++n) {
        for (int y = 0; y < 5; ++y) {
            for (int x = 0; x < 5; ++x) {
                cin >> cube[n][y][x];
            }
        }
    }

    do {
        while (nextRot(bfs()+1)) {
            if (result == 12) { // global minimum, early stop
                cout << result;
                return 0;
            }
        }
    } while (next_permutation(sz, sz + 5)); // layer order shuffle

    cout << result;
}