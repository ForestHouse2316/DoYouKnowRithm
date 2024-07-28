#include <bits/stdc++.h>
using namespace std;
#define X get<0>(q.front())
#define Y get<1>(q.front())
#define Z get<2>(q.front())
typedef pair<int, int> pii;
typedef tuple<int, int, int> piii;

/*
 * s- ���λ�� cube�� ��ȸ�� ������ ���, rot() �Լ��� ���� z�࿡ ���� ������ ���� ����ؼ� �־����.
 * t- ���λ�� BFS �� ��ǥ���� �ǹ�. cube �迭 ������ ������ ��� �迭�� ����.
 *
 * ���� ���̾�(2d �̷�)�� ��� ������ ��ġ�� next_permutation ���� �ݺ���. 1������ 5������ �ִٰ� �� �� 12345 �� �غ��� 13245 �� �غ��� ����
 * �� �ڿ��� BFS �� �غ��� rot() �� ������. BFS �� ���� z�� 2���� ����ٸ�, z2���� z3�� ���̾ �������� ���Ѵٴ� ���̹Ƿ� z3�� ���̾ rot() ��.
 * �׸��� �� �Ʒ��� �ִ� ��� ���̾��� rotation ���� �ٽ� 0���� �ʱ�ȭ��. ��ġ 4���� ī���Ϳ� ����� ������.
 * ���� z0�� ���̾ �ѹ��� �� ���Ƽ� �ٽ� ��������(4�� ����)�� ���ƿԴٸ� ���� ���̾� ��ġ����(z�࿡ ����) �� �����ϰ� �ٽ� �ݺ�.
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