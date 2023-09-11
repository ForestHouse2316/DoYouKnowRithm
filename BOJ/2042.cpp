#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N, M, K;
ll fenwick[1000005] = {0};

ll sum(int node) {
    ll result = 0;
    while(node > 0) {
        result += fenwick[node];
        node -= node&-node;
    }
    return result;
}

void update(int node, ll value) {
    ll change = value - (sum(node) - sum(node-1));
    while(node <= N) {
        fenwick[node] += change;
        node += node&-node;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    cin >> M;
    cin >> K;
    ll in;
    for (int n = 1; n <= N; n++) {
        cin >> in;
        update(n, in);
    }
    int a, b;
    ll c;
    for (int i = 0; i < M+K; i++) {
        cin >> a;
        cin >> b;
        cin >> c;
        if (a == 1) {
            update(b, c);
        }
        else {
            cout << sum((int) c) - sum(b-1) << "\n";
        }
    }
}