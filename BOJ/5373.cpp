#include <bits/stdc++.h>
using namespace std;
typedef pair<char*, char> cc;

int T, N, fixAxis, fixOffset;
bool cw;
char in[3], cube[5][5][5]; // [x][y][z], vector direction is [right][top][forward]
vector<cc> changed;

char* fixedRotate(int fix, int i, int j) {
    switch (fixAxis) {
        case 0: // x
            if (cw) return &cube[fix][j][-i + 4];
            return &cube[fix][-j + 4][i];
        case 1: // y
            if (cw) return &cube[-i + 4][fix][j];
            return &cube[i][fix][-j + 4];
        case 2: // z
            if (cw) return &cube[j][-i + 4][fix];
            return &cube[-j + 4][i][fix];
    }
}

char query(int fix, int i, int j) {
    switch (fixAxis) {
        case 0: return cube[fix][i][j];
        case 1: return cube[j][fix][i];
        case 2: return cube[i][j][fix];
    }
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    changed.reserve(25);
    cin >> T;
    while (T--) {
        for (int i = 1; i <= 3; ++i) {
            for (int j = 1; j <= 3; ++j) {
                cube[i][4][j] = 'w';
                cube[i][0][j] = 'y';
                cube[i][j][0] = 'r';
                cube[i][j][4] = 'o';
                cube[0][i][j] = 'g';
                cube[4][i][j] = 'b';
                for (int k = 1; k <= 3; ++k) cube[i][j][k] = '.'; // debug
            }
        }

        cin >> N;
        for (int n = 0; n < N; ++n) {
            changed.clear();
            cin >> in;
            switch (in[0]) {
                case 'L':
                    fixAxis = 0;
                    fixOffset = 0;
                    cw = in[1] == '+';
                    break;
                case 'R':
                    fixAxis = 0;
                    fixOffset = 3;
                    cw = in[1] == '-';
                    break;
                case 'D':
                    fixAxis = 1;
                    fixOffset = 0;
                    cw = in[1] == '+';
                    break;
                case 'U':
                    fixAxis = 1;
                    fixOffset = 3;
                    cw = in[1] == '-';
                    break;
                case 'F':
                    fixAxis = 2;
                    fixOffset = 0;
                    cw = in[1] == '+';
                    break;
                case 'B':
                    fixAxis = 2;
                    fixOffset = 3;
                    cw = in[1] == '-';
                    break;
            }

            for (int fix = fixOffset; fix <= fixOffset+1 ; ++fix) {
                for (int i = 0; i < 5; ++i) {
                    for (int j = 0; j < 5; ++j) {
                        if(fix != 0 && fix != 4 && i != 0 && i != 4 && j != 0 && j != 4) continue; // fix*i*j == 0 simplify
                        changed.emplace_back(fixedRotate(fix, i, j), query(fix, i, j));
                    }
                }
            }
            for (cc i : changed) {
                *i.first = i.second;
            }
        }
        for (int z = 3; z >= 1; --z) {
            for (int x = 1; x <= 3; ++x) {
                cout << cube[x][4][z];
            }
            cout << '\n';
        }
    }
}