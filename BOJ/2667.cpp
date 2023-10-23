#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
#define X first
#define Y second

int N, board[30][30] = {0};
string in;
queue<p> q;
int maskX[] = {0, 1, 0, -1};
int maskY[] = {1, 0, -1, 0};
vector<int> sizes;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> in;
        for (int j = 0; j < N; j++) {
            board[i][j] = in[j] - '0';
        }
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j]) {
                int size = 1;
                board[i][j] = 0;
                q.emplace(j, i);

                while (!q.empty()) {
                    for (int k = 0; k < 4; k++) {
                        int tX = q.front().X + maskX[k];
                        int tY = q.front().Y + maskY[k];

                        if (tX < 0 || tY < 0 || tX >= N || tY >= N) continue;

                        if (board[tY][tX]) {
                            size++;
                            board[tY][tX] = 0;
                            q.emplace(tX, tY);
                        }
                    }
                    q.pop();
                }
                sizes.push_back(size);
            }
        }
    }

    cout << sizes.size() << "\n";
    std::sort(sizes.begin(), sizes.end());
    for (int size : sizes) {
        cout << size << "\n";
    }
}