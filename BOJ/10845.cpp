#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int t;
    cin >> t;
    queue<int> q;
    string cmd;
    while (t--) {
        cin >> cmd;
        if (cmd == "push") {
            int n;
            cin >> n;
            q.push(n);
        }
        else if (cmd == "pop") {
            if (q.empty()) cout << -1 << '\n';
            else {
                cout << q.front() << '\n';
                q.pop();
            }
        }
        else if (cmd == "size") {
            cout << q.size() << '\n';
        }
        else if (cmd == "empty") {
            cout << q.empty() << '\n';
        }
        else if (cmd == "front") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.front() << '\n';
        }
        else if (cmd == "back") {
            if (q.empty()) cout << -1 << '\n';
            else cout << q.back() << '\n';
        }
    }
}