#include <bits/stdc++.h>
#define ARR_MAX 100
using namespace std;

int N, L, height[ARR_MAX][ARR_MAX], result = 0;
bool rowDir, ins[ARR_MAX];

bool install(const int* from, int insIdx) {
    int step = rowDir ? 1 : ARR_MAX;
    int stdH = *from;

    for (int l = 0; l < L; ++l) {
        if (stdH != *(from + l*step)) return false; // flatness
        if (ins[insIdx + l]) return false; // isEmpty
    }

    return true;
}

bool check(int* s) {
    int step = rowDir ? 1 : ARR_MAX;
    int* c; // current
    fill(ins, ins+N, false);

    for (int iter = 1; iter < N; ++iter) {
        c = s + iter*step;
        if (*(c - step) + 1 == *c) { // incline
            if (0 <= iter-L && install(c - L*step, iter-L)) {
                for (int i = iter-L; i < iter; ++i) ins[i] = true;
            }
            else return false;
        }
        else if (*(c - step) == *c + 1) { // decline
            if (iter+L <= N && install(c, iter)) {
                for (int i = iter; i < iter+L; ++i) ins[i] = true;
            }
            else return false;
        }
        else if (*(c - step) != *c) return false; // diff > 1
    }

    return true;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> L;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cin >> height[i][j];
        }
    }

    rowDir = true;
    for (int i = 0; i < N; ++i) if (check(height[i])) result++;
    rowDir = false;
    for (int i = 0; i < N; ++i) if (check(&height[0][i])) result++;

    cout << result;
}