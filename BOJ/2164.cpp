#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;
    for (int n = 1; n <= N; n++) {
        q.push(n);
    }

    int temp;
    while(q.size() != 1) {
        q.pop();
        temp = q.front(); q.pop();
        q.push(temp);
    }
    cout << q.front();
}