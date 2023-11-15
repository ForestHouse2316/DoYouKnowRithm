#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
int C, H, W, tX, tY, docs;
char board[102][102];
bool visited[102][102], key[26];
vector<p> doors[26];
string in;
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> C;
    while (C--) {
        docs = 0;
        cin >> H >> W;
        for (int h = 0; h < H; h++) {
            fill(visited[h], visited[h]+W, false);  // init visited array
        }
        for (int h = 0; h < H; h++) {
            cin >> in;
            for (int w = 0; w < W; w++) {
                board[h][w] = in[w];
//                if ('A' <= board[h][w] && board[h][w] <= 'Z') doors[board[h][w]-'A'].emplace_back(w, h);
            }
        }
        // set starting position from doors can be opened by already possessing keys
        fill(key, key+26, false);
        cin >> in;
        for (char c : in) {
            key[c-'a'] = true;
        }
        // set starting position from edge
        for (int edge : {0, H-1}) {
            for (int w = 0; w < W; w++) {
                if (board[edge][w] == '.') {
                    q.emplace(w, edge);
                    visited[edge][w] = true;
                    // TODO 엣지쪽에서 여는거 가능한 애들은 열어서 emplace 해줘야함
                }
            }
        }
        for (int edge : {0, W-1}) {
            for (int h = 1; h < H-1; h++) {  // exclude duplicated coordinates
                if (board[h][edge] == '.') {
                    q.emplace(edge, h);
                    visited[h][edge] = true;
                }
            }
        }

        while (!q.empty()) {
            // TODO doors 에 왔다가 문 못 열고 돌아간거 추가해야함
            for (int i = 0; i < 4; i++) {
                tX = q.front().X + maskX[i];
                tY = q.front().Y + maskY[i];
                if (tX < 0 || tY < 0 || tX >= W || tY >= H || visited[tY][tX] || board[tY][tX] == '*') continue;


                if (board[tY][tX] == '$') docs++;
                if (board[tY][tX] != '*' && !('A' <= board[tY][tX] && board[tY][tX] <= 'Z')) {
                    q.emplace(tX, tY);
                    visited[tY][tX] = true;
                }
                if ('a' <= board[tY][tX] && board[tY][tX] <= 'z' && !key[board[tY][tX]-'a']) {
                    key[board[tY][tX]-'a'] = true;
                    for(p door : doors[board[tY][tX]-'a']) {
                        q.push(door);
                        visited[door.Y][door.X] = true;
                    }
                }
            }
            q.pop();
        }
        cout << docs << '\n';
    }
}