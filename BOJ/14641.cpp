#include <bits/stdc++.h>
using namespace std;

int M, N;
bool compatible;
char from, to;
string a, b;
unordered_map<char, vector<char>> trans;
bool vis[26];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> M >> N;
    for (int m = 0; m < M; ++m) {
        cin >> from >> to;
        trans[from].push_back(to);
    }
    for (int n = 0; n < N; ++n) {
        cin >> a >> b;
        if (a.length() != b.length()) cout << "no\n";
        else if (a == b) cout << "yes\n";
        else {
            for (int i = 0; i < a.length(); ++i) {
                if (a[i] == b[i]) continue;

                compatible = false;
                queue<char> q; q.push(a[i]);
                fill(vis, vis+26, false);

                while (!q.empty()) { // check changeable
                    for (char c : trans[q.front()]) {
                        if (vis[c-'a']) continue;
                        if (c == b[i]) compatible = true;
                        else {
                            q.push(c);
                            vis[c - 'a'] = true;
                        }
                    }
                    if (compatible) break;
                    q.pop();
                }
                if (!compatible) { // cannot change
                    cout << "no\n";
                    break;
                }
            }
            if (compatible) cout << "yes\n"; // finished for-statement without unchangeable
        }
    }
}