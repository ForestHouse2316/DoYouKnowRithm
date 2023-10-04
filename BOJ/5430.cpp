#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

deque<int> d;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int T, n, converted;
    string p, arrIn;
    bool rev, error;

    cin >> T;
    for (int t = 0; t < T; t++) {
        d.clear();
        error = false;
        rev = false;

        cin >> p;
        cin >> n;
        cin >> arrIn;
        if (n != 0) {
            converted = 0;
            for (char c: arrIn) {
                if (c == '[') continue;

                if (c == ',' || c == ']') {
                    d.push_back(converted);
                    converted = 0;
                } else {
                    converted = converted * 10 + ((int) c - '0');
                }
            }
        }
        for(char c : p) {
            if (c == 'R') rev = !rev;
            else {
                // c == 'D'
                if (d.empty()) {
                    error = true;
                    break;
                }
                if (rev) d.pop_back();
                else d.pop_front();
            }
        }
        if (error) cout << "error" << "\n";
        else {
            cout << "[";
            if (rev) {
                while (!d.empty()) {
                    cout << d.back() << (d.size() == 1 ? "" : ",");
                    d.pop_back();
                }
            }
            else {
                while (!d.empty()) {
                    cout << d.front() << (d.size() == 1 ? "" : ",");
                    d.pop_front();
                }
            }
            cout << "]\n";
        }
    }
}