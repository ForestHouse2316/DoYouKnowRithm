#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    string cmd;
    int in;
    for (int n = 0; n < N; n++) {
        cin >> cmd;
        if(cmd == "push") {
            cin >> in;
            q.push(in);
        }
        else if(cmd == "pop") {
            if(q.empty()) cout << -1 << "\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        }
        else if(cmd == "size") cout << q.size() << "\n";
        else if(cmd == "empty") cout << q.empty() << "\n";
        else if(cmd == "front") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.front() << "\n";
        }
        else if(cmd == "back") {
            if (q.empty()) cout << -1 << "\n";
            else cout << q.back() << "\n";
        }
    }
}