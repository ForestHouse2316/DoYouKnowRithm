#include <bits/stdc++.h>
using namespace std;
int F, S, G, U, D, click = 0;
bool checked[1000005] = {false};
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> F;
    cin >> S;
    cin >> G;
    cin >> U;
    cin >> D;

    q.push(S);
    checked[S] = true;
    while (!q.empty()) {
        int depth = q.size();
        for (int i = 0; i < depth; i++) {
            if (q.front() == G) {
                cout << click;
                return 0;
            }
            int upper = q.front() + U;
            int lower = q.front() - D;
            if (upper <= F && !checked[upper]) {
                q.push(upper);
                checked[upper] = true;
            }
            if (lower > 0 && !checked[lower]) {
                q.push(lower);
                checked[lower] = true;
            }
            q.pop();
        }

        click++;
    }
    cout << "use the stairs";
}