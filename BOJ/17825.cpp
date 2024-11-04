#include <bits/stdc++.h>
using namespace std;

int dice[10], maxScore = 0, pos[4]={}, junc[4]={-1,-1,-1,-1};
// Score is the unique ID of the position
// n(S to E) = index range[0, 21]
int scoreMap[22] = {0,2,4,6,8,10,12,14,16,18,20,22,24,26,28,30,32,34,36,38,40,0};
int scoreMapJ[3][9] = {
        {10, 13, 16, 19, 25, 30, 35, 40, 0},
        {20, 22, 24, 25, 30, 35, 40, 0, 0},
        {30, 28, 27, 26, 25, 30, 35, 40 ,0}
};

bool isSamePos(const int& ap, const int& aj, const int& bp, const int& bj) {
    int sa = aj == -1 ? scoreMap[ap] : scoreMapJ[aj][ap];
    int sb = bj == -1 ? scoreMap[bp] : scoreMapJ[bj][bp];

    // diff score == diff pos
    if (sa != sb) return false;
    // compare 40 score
    if (sa + sb == 80) return true;
    // compare p
    if (aj + bj == -2) return ap == bp;
    // compare j
    if (aj != -1 && bj != -1 && sa == sb) return true;

    return false; // same score diff tile
}

int move(int n, int time) {
    int &p = pos[n], &j = junc[n];
    if (j == -1 && p <= 15 && p % 5 == 0) { // junction tile
        j = p / 5 - 1;
        p = 0;
    }

    if (j == -1) {
        p = min(21, p + time);
        if (p != 21) {
            for (int i = 0; i < 4; ++i) { // lock
                if (i == n) continue;
                if (isSamePos(p, j, pos[i], junc[i])) return -1;
            }
        }

        return scoreMap[p];
    }
    else {
        p = min(8, p + time);
        if (j == 1 && p == 7 || p == 8) { // finish tile
            p = 21; j = -1;
            return 0;
        }
        for (int i = 0; i < 4; ++i) { // lock
            if (i == n) continue;
            if (isSamePos(p, j, pos[i], junc[i])) return -1;
        }

        return scoreMapJ[j][p];
    }
}

void backtrack(int depth, int score) {
    if (depth == 10) {
        maxScore = max(score, maxScore);
        return;
    }

    int prevPos, prevJunc, gained;
    for (int i = 0; i < 4; ++i) {
        if (pos[i] == 21) continue; // arrived piece
        prevPos = pos[i]; prevJunc = junc[i]; // ===== BACKUP
        gained = move(i, dice[depth]);
        if (gained != -1) backtrack(depth+1, score + gained);
        pos[i] = prevPos; junc[i] = prevJunc; // ===== RECOVER
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int i = 0; i < 10; ++i) {
        cin >> dice[i];
    }

    backtrack(0, 0);
    cout << maxScore;
}