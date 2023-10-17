#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> p;
#define x first
#define y second

int N, l, in1, in2;
p from, to, temp, splitter={-1,-1};
int maskY[] = {2, 2, 1, 1, -1, -1, -2, -2};
int maskX[] = {-1, 1, -2, 2, -2, 2, -1, 1};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    for (int n = 0; n < N; n++) {
        cin >> l;
        cin >> in1;
        cin >> in2;
        from = {in1, in2};
        cin >> in1;
        cin >> in2;
        to = {in1, in2};

        int times = 0;
        queue<p> q;
        bool visited[305][305] = {false};
        visited[from.y][from.x] = true;
        q.push(from);
        q.push(splitter);

        while (true) {
            temp = q.front();
            q.pop();
            if (temp == splitter) {
                times++;
                q.push(splitter);
                continue;
            }
            if (temp == to) {
                cout << times << "\n";
                break;
            }
            for (int i = 0; i < 8; i++) {
                int tX = temp.x + maskX[i];
                int tY = temp.y + maskY[i];
                if (tY < 0 || tY >= l || tX < 0 || tX >= l) continue;
                if (!visited[tY][tX]) {
                    q.emplace(tX, tY);
                    visited[tY][tX] = true;
                }
            }
        }
    }
}