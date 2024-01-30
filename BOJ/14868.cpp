#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int N, K, x, y, cx, cy, tx, ty, year = 0, loop, loopK, targetParent;
int civID = 0;
int board[2005][2005], parent[100005];
bool merged, registered[2005][2005] = {false};
vector<int> adjCiv(4);
queue<pii> q;
int dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};

void v() {
    for (int a = 1; a <= 10; a++) {
        for (int b = 1; b <= 10; b++) {
            cout << (board[a][b] == -1 ? "." : to_string(board[a][b])) << "\t";
        }
        cout << endl;
    }
    cout << "YEAR : " << year << endl;
    cout << K << endl;
    cout << "\n\n\n";
}

int getParent(int id) {
    if (parent[id] == -1 || parent[id] == id) return id;
    parent[id] = getParent(parent[id]);  // optimization
    return parent[id];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // init
    fill(parent, parent+100005, -1);
    for (int i = 0; i < 2005; ++i) {
        fill(board[i], board[i]+2005, -1);
    }

    cin >> N >> K;
    loopK = K;  // just for loop
    while (loopK--) {
        cin >> x >> y;
        q.emplace(x, y);
        registered[y][x] = true;
    }

    while (true) {
        v();

        loop = q.size();
        while (loop--) {
            adjCiv.clear();
            tie(cx, cy) = q.front();  // position arrived in this year
            q.pop();
            if (board[cy][cx] != -1) continue;  // already processed

            for (int i = 0; i < 4; ++i) {  // check next cells of BFS process & adjacent civ
                tx = cx + dx[i];
                ty = cy + dy[i];
                if (tx < 1 || ty < 1 || tx > N || ty > N) continue;
                if (board[ty][tx] != -1) {  // adjacent civ
                    adjCiv.push_back(board[ty][tx]);
                }
                else if (!registered[ty][tx]) {
                    q.emplace(tx, ty);  // set as next cell
                    registered[ty][tx] = true;
                }
            }

            // set civID to board
            if (adjCiv.empty()) board[cy][cx] = civID++;
            else {
                board[cy][cx] = adjCiv[0];  // No error should be occurred, because there's at least one path exist except when year is 0
                targetParent = getParent(adjCiv[0]);
                merged = false;
                for (int i = 1; i < adjCiv.size(); ++i) {
                    if (targetParent != getParent(adjCiv[i])) {
                        // Merge two civs
                        parent[adjCiv[i]] = targetParent;
                        K--;
                        merged = true;
                    }
                }
                if (K == 1) {
                    v();
                    cout << year;
                    return 0;
                }
                else if (!merged) ;
            }
        }
        year++;
    }
}