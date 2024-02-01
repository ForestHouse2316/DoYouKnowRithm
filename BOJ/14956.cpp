#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
#define x first
#define y second
int dx[] = {false, 0, 0, 1, 1}, dy[] = {false, 0, 1, 1, 0};  // 1-indexed

// Q number is:
// 2 3
// 1 4

// Quarter 1,2,3 : start from left bottom
// Quarter 4 : start from right top
// 47

int N, M;


// TODO All-renewal... They're all wrong! Parameter "reverse" should be separated into revX and revY
pii rec(int sx, int sy, int len, int offset, int reverse) {
    int quarter = (M-offset / (pow(len, 2)/4)) + 1;
    int half = len/2;
    if (len == 2) {
        return {sx+dx[quarter]*half, sy+dy[quarter]*half};
    }
    if (quarter == 4) {
        return rec(sx+reverse*dx[quarter]*half, sy+reverse*dy[quarter]*half, half, offset + (pow(half, 2) * (quarter-1)), )
    }
    else {
        return rec(sx+dx[quarter]*half, sy+dy[quarter]*half, half, offset + (pow(half, 2) * (quarter-1)), reverse);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N >> M;
    pii result = rec(M, 1, 1, N, 0);
    cout << result.x << " " << result.y;
}