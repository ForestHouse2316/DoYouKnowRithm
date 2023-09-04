#include <bits/stdc++.h>
using namespace std;

int main() {
    string line;
    bool balanced;
    while (true) {
        stack<char> s;
        balanced = true;
        getline(cin, line);
        if (line == ".") {
            break;
        }

        for (auto c : line) {
            switch (c) {
                case '(':
                case '[':
                    s.push(c);
                    break;
                case ')':
                    if (s.empty() || s.top() != '(') {
                        balanced = false;
                    }
                    else {
                        s.pop();
                    }
                    break;
                case ']':
                    if (s.empty() || s.top() != '[') {
                        balanced = false;
                    }
                    else {
                        s.pop();
                    }
                    break;
                default:
                    break;
            }
            if (!balanced) {
                break;
            }
        }
        if (!s.empty()) balanced = false;
        cout << (balanced ? "yes" : "no") << endl;
    }
}