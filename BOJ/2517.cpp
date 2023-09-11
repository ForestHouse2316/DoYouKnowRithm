#include <bits/stdc++.h>
#define num first
#define speed second
using namespace std;
int N;
int fenwick[1000005] = {0};  // 1-indexed Array
pair<int, int> player[500005];

bool compSpeed(pair<int, int> a, pair<int, int> b) {
    return a.speed < b.speed;
}
bool compNum(pair<int, int> a, pair<int, int> b) {
    return a.num < b.num;
}

int sum(int i) {  // Sum to index [i]
    int result = 0;
    while (i > 0) {
        result += fenwick[i];
        i -= i&-i;
    }
    return result;
}

void update(int node, int val) {
    while (node <= N) {
        fenwick[node] += val;  // If we want "set" the value at node, we should use [ val - sum(node) + sum(node-1) ]
        node += node&-node;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> player[n].speed;
        player[n].num = n;
    }

    // Sort by speed
    sort(player, player + N, compSpeed);
    // Set speed in range [1, N]
    for (int normSpeed = 1; normSpeed <= N; normSpeed++) {
        player[normSpeed-1].speed = normSpeed;
    }
    // Sort by starting number
    sort(player, player + N, compNum);  // Tip : If we need more time-complexity diet, we may consider using unordered_map for this

    for (int p = 0; p < N; p++) {
        update(player[p].speed, 1);
        cout << (p+1) - sum(player[p].speed-1) << "\n";  // Starting number - Turtle player number(slow guys)
    }
}