#include <bits/stdc++.h>
#define UP 1
#define DOWN (-1)
#define SUS 0
#define prev P[i-1]
#define cur P[i]
using namespace std;

int N, dir=UP, P[50005]; // 1-indexed
vector<int> explosion;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    explosion.reserve(50005);
    cin >> N;
    cin >> P[1];
    if (N == 1) {
        cout << 1 << "\n";
        return 0;
    }
    for (int i = 2; i <= N; ++i) {
        cin >> P[i];
        switch (dir) {
            case UP:
                if (prev < cur) continue;
                else if (prev == cur) {
                    dir = SUS; // _--
                    explosion.push_back(i-1);
                    continue;
                }
                else {
                    dir = DOWN; // _-_
                    explosion.push_back(i-1);
                }
                break;
            case SUS:
                if (prev == cur) {
                    explosion.push_back(i-1);
                    continue;
                }
                else if (prev > cur) {
                    dir = DOWN; // --_
                    explosion.push_back(i-1);
                }
                else dir = UP; // __-
                break;
            case DOWN:
                if (prev > cur) continue;
                else if (prev == cur) dir = SUS; // -__
                else dir = UP; // -_-
                break;
        }
    }
    if (P[N-1] <= P[N]) explosion.push_back(N); // last one

    for (int i : explosion) {
        cout << i << "\n";
    }
}