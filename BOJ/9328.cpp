#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> p;
#define X first
#define Y second
int C, H, W, tX, tY, docs;
char board[102][102];
bool visited[102][102], key[26];
string in;
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> C;
    while (C--) {
        vector<p> doors[26];
        fill(key, key+26, false);
        docs = 0;
        cin >> H >> W;
        for (int h = 0; h < H; h++) {
            fill(visited[h], visited[h]+W, false);  // init visited array
        }
        for (int h = 0; h < H; h++) {
            cin >> in;
            for (int w = 0; w < W; w++) {
                board[h][w] = in[w];
                if (board[h][w] != '*' && (h == 0 || w == 0 || h == H-1 || w == W-1)) {  // if edge
                    visited[h][w] = true;
                    if ('A' <= board[h][w] && board[h][w] <= 'Z') doors[board[h][w]-'A'].emplace_back(w, h);
                    else {
                        q.emplace(w, h);
                        if (board[h][w] == '$') docs++;
                        else if ('a' <= board[h][w] && board[h][w] <= 'z') key[board[h][w]-'a'] = true;
                    }
                }
            }
        }
        // initial keys
        cin >> in;
        if (in != "0") {
            for (char c : in) {
                key[c-'a'] = true;
            }
        }
        // open the doors by initially possessing keys
        for (int i = 0; i < 26; i++) {
            if (!key[i]) continue;
            for(p door : doors[i]) {
                q.push(door);
                visited[door.Y][door.X] = true;
            }
        }

        while (!q.empty()) {
            for (int i = 0; i < 4; i++) {
                tX = q.front().X + maskX[i];
                tY = q.front().Y + maskY[i];
                if (tX < 0 || tY < 0 || tX >= W || tY >= H || visited[tY][tX] || board[tY][tX] == '*') continue;
                visited[tY][tX] = true;
                if ('A' <= board[tY][tX] && board[tY][tX] <= 'Z' && !key[board[tY][tX]-'A']) doors[board[tY][tX]-'A'].emplace_back(tX, tY);
                else {
                    q.emplace(tX, tY);
                    if (board[tY][tX] == '$') docs++;  // if document
                    else if ('a' <= board[tY][tX] && board[tY][tX] <= 'z' && !key[board[tY][tX]-'a']) {  // if key && first found
                        key[board[tY][tX]-'a'] = true;
                        for(p door : doors[board[tY][tX]-'a']) {
                            q.push(door);
                            visited[door.Y][door.X] = true;
                        }
                    }
                }
            }
            q.pop();
        }
        cout << docs << '\n';
    }
}