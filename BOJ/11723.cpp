#include <bits/stdc++.h>
using namespace std;

int M, in;
string cmd;
set<int> s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M;

    while (M--) {
        cin >> cmd;
        if (cmd == "add") {
            cin >> in;
            s.insert(in);
        }
        else if (cmd == "remove") {
            cin >> in;
            s.erase(in);
        }
        else if (cmd == "check") {
            cin >> in;
            cout << (s.find(in) != s.end()) << "\n";
        }
        else if (cmd == "toggle") {
            cin >> in;
            if (s.find(in) == s.end()) s.insert(in);
            else s.erase(in);
        }
        else if (cmd == "all") {
            for (int i = 1; i <= 20; ++i) {
                s.insert(i);
            }
        }
        else if (cmd == "empty") {
            s.clear();
        }
    }
}