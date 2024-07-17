#include <bits/stdc++.h>
using namespace std;
#define NTH first
#define DIR second
typedef pair<int, bool> pib;

int K, score = 0, topIdx[8] = {0};
bool saw[4][8];
string in;

bool getPole(int nth, int offset) {
    if (offset < 0) offset += 8;
    return saw[nth][(topIdx[nth]+offset) % 8];
}

bool getLeft(int nth) { return getPole(nth, -2); }
bool getRight(int nth) { return getPole(nth, 2); }

void rotate(int nth, bool cw) {
    queue<pib> rotQ;
    rotQ.emplace(nth, cw);

    bool cDir = !cw;
    for (int n = nth-1; n >= 0; --n) { // <-----
        if (getRight(n) == getLeft(n+1)) break;

        rotQ.emplace(n, cDir);
        cDir = !cDir;
    }
    cDir = !cw;
    for (int n = nth+1; n < 4; ++n) { // ----->
        if (getRight(n-1) == getLeft(n)) break;

        rotQ.emplace(n, cDir);
        cDir = !cDir;
    }

    while (!rotQ.empty()) {
        pib f = rotQ.front();
        if (f.DIR) topIdx[f.NTH] = (topIdx[f.NTH] + 7) % 8; // cw
        else topIdx[f.NTH] = (topIdx[f.NTH] + 1) % 8; // ccw

        rotQ.pop();
    }
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    for (int n = 0; n < 4; ++n) {
        cin >> in;
        for (int i = 0; i < 8; ++i) {
            saw[n][i] = in[i] == '1';
        }
    }
    cin >> K;
    int nth, cw;
    while (K--) {
        cin >> nth >> cw;
        rotate(nth-1, cw==1);
    }

    for (int n = 0; n < 4; ++n) {
        if (saw[n][topIdx[n]]) score += (int) pow(2, n);
    }
    cout << score;
}