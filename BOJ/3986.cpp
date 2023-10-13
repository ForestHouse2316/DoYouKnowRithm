#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, good = 0;
    string in;
    stack<char> s;
    cin >> N;

    for (int n = 0; n < N; n++) {
        while (!s.empty()) s.pop();
        cin >> in;
        for (char c : in) {
            if (s.empty() || s.top() != c) s.push(c);
            else s.pop();
        }
        if (s.empty()) good++;
    }
    cout << good;
}