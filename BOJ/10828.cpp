#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int loopTimes;
    cin >> loopTimes;
    stack<int> s;
    string cmd;
    while (loopTimes--) {
        cin >> cmd;
        if (cmd == "push") {
            int num;
            cin >> num;
            s.push(num);
            continue;
        }
        else if (cmd == "pop") {
            if (s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << s.top() << '\n';
            s.pop();
            continue;
        }
        else if (cmd == "currentSize") {
            cout << s.size() << '\n';
            continue;
        }
        else if (cmd == "empty") {
            cout << s.empty() << '\n';
            continue;
        }
        else if (cmd == "top") {
            if (s.empty()) {
                cout << -1 << '\n';
                continue;
            }
            cout << s.top() << '\n';
            continue;
        }
    }

}