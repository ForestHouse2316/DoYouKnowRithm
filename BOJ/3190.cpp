#include <bits/stdc++.h>
#define EMT 0
#define SNK 1
#define APL 2
#define hx head.first
#define hy head.second
#define fx order.front().first
#define fy order.front().second
using namespace std;
typedef pair<int, int> pii;

int N, K, r, c, L, X, sec = 0, cd = 1; // cd : 0 1 2 3 => U L D R
int board[105][105] = {0};// 1-indexed
int dx[] = {0, 1, 0, -1}, dy[] = {-1, 0, 1, 0};
char C;
queue<pii> order;
pii head;
unordered_map<int, int> rot;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> K;
    for (int k = 0; k < K; ++k) {
        cin >> r >> c;
        board[r][c] = APL;
    }
    cin >> L;
    for (int l = 0; l < L; ++l) {
        cin >> X >> C;
        rot[X] = C == 'D' ? 1 : 3;
    }

    head = {1, 1};
    order.push(head);
    board[1][1] = SNK;
    while (true) {
        sec++;
        // expand head
        head = {hx + dx[cd], hy + dy[cd]};
        order.push(head);

        // board check
        if (hx <= 0 || hy <= 0 || hx > N || hy > N || board[hy][hx] == SNK) break; // game over
        if (board[hy][hx] != APL) { // shrink tail
            board[fy][fx] = EMT;
            order.pop();
        }
        board[hy][hx] = SNK; // set head pos as SNK

        // rotate
        if (rot.find(sec) != rot.end())
            cd = (cd + rot[sec]) % 4;
    }

    cout << sec;
}