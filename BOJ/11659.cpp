#include <bits/stdc++.h>
using namespace std;
int N, M;
int fenwick[100001] = {0};

int sum(int node) {
    int result = 0;
    while (node > 0) {
        result += fenwick[node];
        node -= node&-node;
    }
    return result;
}

void update(int node, int value) {
    int change = value - (sum(node) - sum(node-1));
    while (node <= N) {
        fenwick[node] += change;
        node += node&-node;
    }
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N; cin >> M;
    int in;
    for (int n = 1; n <= N; n++) {
        cin >> in;
        update(n, in);
    }
    int a, b;
    for (int m = 0; m < M; m++) {
        cin >> a; cin >> b;
        cout << sum(b) - sum(a-1) << "\n";
    }

}