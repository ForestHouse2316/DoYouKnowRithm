#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
#define first first
#define second second

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    string in;
    stack<char> s;
    bool error;
    cin >> N;

    for (int n = 0; n < N; n++) {
        // init
        error = false;
        while (!s.empty()) s.pop();

        cin >> in;
        for (char c : in) {
            if (c == '(') s.push(c);
            else if (!s.empty() && c == ')') s.pop();
            else {
                // empty + ')'
                error = true;
                break;
            }
        }
        if (error || !s.empty()) cout << "NO" << "\n";
        else cout << "YES" << "\n";
    }
}