#include <bits/stdc++.h>
using namespace std;
#define C q.front().first
#define PX q.front().second.first
#define PY q.front().second.second
#define X first
#define Y second
typedef pair<int, int> pii;
typedef pair<int, pii> pipii;

int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
int N, M, G, R, maxF=0, flower, depth, loop, tx, ty, grd2Num=0, comb[10], board[50][50], diffuse[50][50], timestamp[50][50];
pii grd2Pos[10];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> G >> R;
    for (int n = 0; n < N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> board[n][m];
            if (board[n][m] == 2) grd2Pos[grd2Num++] = {m, n};
        }
    }

    // make comb -> e.g.) gggrr11111 == 0001122222
    // green = 0 / red = 1 / empty = 2 / flower = 3
    fill(comb, comb+G, 0);
    fill(comb+G, comb+G+R, 1);
    fill(comb+G+R, comb + grd2Num, 2); // G+R <= numGrd2 <= 10
    do {
        flower = 0; depth = 0;
        for (int n = 0; n < N; ++n) {
            fill(diffuse[n], diffuse[n] + M, -1);
            fill(timestamp[n], timestamp[n] + M, -1);
        }
        queue<pipii> q;
        for (int i = 0; i < grd2Num; ++i) {
            if (comb[i] != 2) {
                diffuse[grd2Pos[i].Y][grd2Pos[i].X] = comb[i];
                timestamp[grd2Pos[i].Y][grd2Pos[i].X] = 0;
                q.emplace(comb[i], grd2Pos[i]);
            }
        }

        while (!q.empty()) {
            depth++;
            loop = q.size();
            while (loop--) {
                if (diffuse[PY][PX] == 3) { // if current position changed to flower, skip
                    q.pop();
                    continue;
                }
                for (int i = 0; i < 4; ++i) {
                    tx = PX + dx[i];
                    ty = PY + dy[i];
                    if (tx < 0 || ty < 0 || tx >= M || ty >= N || board[ty][tx] == 0 || diffuse[ty][tx] == C) continue;
                    if (diffuse[ty][tx] == -1) { // empty place
                        diffuse[ty][tx] = C;
                        timestamp[ty][tx] = depth;
                        q.emplace(C, make_pair(tx, ty));
                    }
                    else if (diffuse[ty][tx] != 3 && timestamp[ty][tx] == depth) { // different color exist and same turn
                        diffuse[ty][tx] = 3; // set as flower
                        flower++;
                    }
                }
                q.pop();
            }
        }
        maxF = max(maxF, flower);
    } while(next_permutation(comb, comb + grd2Num));

    cout << maxF;
}

/*
 * diffuse[][] Ȯ������� �⺻�� -1, �ʷϾ� 0, ������ 1, �� 3�� ������ ��� ����
 *
 * timestamp[][] diffuse �� -1�� �ƴ� ���� �� ��° BFS �������� �����Ǿ������� ������ ����
 *
 * comb[] �ʷϾ� 0, ������ 1, ���� ���� 2 �� �����Ͽ� ��Ʈ��ŷ�� combination ������ ���� �迭��
 * 2�� ���� ���� �ʷϾ� �������� �״� ��� ��츦 ��Ÿ�� �� ����
 */