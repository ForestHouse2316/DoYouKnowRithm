#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

int N, M, T, x, d, k, basis[51] = {}, disc[51][50]; // basis and disc number is 1-indexed
queue<int*> eraseQueue;

void rotate(int n, bool ccw, int time) {
    if (ccw) basis[n] += time;
    else basis[n] += M - time;
    basis[n] %= M;
}

int* get(int i, int j) {
    // exceeding value will be gently wrapped (upward direction only)
    if (i > N) i -= N;
    return &disc[i][(j + basis[i]) % M];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> M >> T;
    for (int n = 1; n <= N; ++n) {
        for (int m = 0; m < M; ++m) {
            cin >> disc[n][m];
        }
    }

    while (T--) {
        cin >> x >> d >> k;
        for(int mul = x; mul <= N; mul+=x) rotate(mul, (bool) d, k);

        int *prev, *cur;
        // N direction adjacency
        for (int m = 0; m < M; ++m) {
            prev = get(1, m);
            for (int n = 2; n <= N; ++n) {
                cur = get(n, m);
                if (*prev != 0 && *prev == *cur) {
                    eraseQueue.push(prev);
                    while(n <= N && *prev == *cur) { // fast-forward
                        eraseQueue.push(cur);
                        cur = get(++n, m);
                    }
                }
                prev = cur;
            }
        }
        // M direction adjacency
        for (int n = 1; n <= N; ++n) {
            prev = get(n, 0);
            for (int m = 1; m < M+1; ++m) { // +1 to compare [M-1] <-> [0]
                cur = get(n, m);
                if (*prev != 0 && *prev == *cur) {
                    eraseQueue.push(prev);
                    while(m < M+1 && *prev == *cur) {
                        eraseQueue.push(cur);
                        cur = get(n, ++m);
                    }
                }
                prev = cur;
            }
        }

        if (eraseQueue.empty()) { // average value based adjusting
            int sum = 0, cnt = 0, *target;
            float avg;
            for (int n = 1; n <= N; ++n) {
                for (int m = 0; m < M; ++m) {
                    target = get(n, m);
                    if (*target == 0) continue;

                    sum += *target;
                    cnt++;
                }
            }
            avg = (float) sum / (float) cnt;
            for (int n = 1; n <= N; ++n) {
                for (int m = 0; m < M; ++m) {
                    target = get(n, m);
                    if (*target == 0) continue;

                    if (*target < avg) (*target)++;
                    else if (*target > avg) (*target)--;
                }
            }
        }
        else { // erase
            while (!eraseQueue.empty()) {
                *eraseQueue.front() = 0;
                eraseQueue.pop();
            }
        }
    }

    int sum = 0;
    for (int n = 1; n <= N; ++n) {
        for (int m = 0; m < M; ++m) {
            sum += *get(n, m);
        }
    }
    cout << sum;
}