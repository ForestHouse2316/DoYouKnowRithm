#include <bits/stdc++.h>
using namespace std;
#define WEI first
#define TIME second
typedef pair<int, int> pii;

int N, W, L, wei[1000], t=0, curW=0, nextCar=0;
queue<pii> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N >> W >> L;
    for (int n = 0; n < N; ++n) {
        cin >> wei[n];
    }

    while (nextCar < N || !q.empty()) {
        t++;
        if (!q.empty() && t - q.front().TIME >= W) { // escape
            curW -= q.front().WEI;
            q.pop();
        }
        if (nextCar < N && curW + wei[nextCar] <= L) { // enter
            curW += wei[nextCar];
            q.emplace(wei[nextCar++], t);
        }
    }

    cout << t;
}