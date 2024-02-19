#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
#define T 0
#define R 1
#define B 2
#define L 3
#define CW 0
#define CCW 1
pii walk[][4] = {{{0,0}, {0,1}, {1,1}, {1,0}},
                 {{0,0}, {1,0}, {1,1}, {0,1}},
                 {{0,0}, {0,-1}, {-1,-1}, {-1,0}},
                 {{0,0}, {-1,0}, {-1,-1}, {0,-1}}};
int rotateH[][4] = {{1, 0, 0, 3},
                    {3, 0, 0, 1}};
int N, M;
int n, H = T, sX = 1, sY = 1, sM = 1;  // using global vars to reduce memory utilization

pii rec() {
    if (n == 1) return {sX, sY};
    n /= 2;
    int qAmount = (int) pow(n, 2);
    int quarter = (M-sM) / qAmount;

    // update parameter
    // BE CAREFUL about the order of the code lines
    sM += quarter * qAmount;
    sX += walk[H][quarter].x * n;
    sY += walk[H][quarter].y * n;
    if (quarter == 3) {  // move sX and sY to opposite site in this quarter, which is next to 2-quarter's end point
        sX += walk[H][2].x * (n-1);
        sY += walk[H][2].y * (n-1);
    }
    H = (H + rotateH[(H%2) ? CCW : CW][quarter]) % 4;
    return rec();
}



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    n = N;  // just because we want to regard N as a constant
    pii result = rec();
    cout << result.x << " " << result.y;
}