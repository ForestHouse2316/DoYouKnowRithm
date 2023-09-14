#include <bits/stdc++.h>
using namespace std;
list<char> pw;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N;
    cin >> N;

    string str;
    auto it = pw.begin();
    auto del = it;
    for (int n = 0; n < N; n++) {
        cin >> str;
        for (char c : str) {
            switch (c) {
                case '<':
                    if (it != pw.begin()) it--;
                    break;
                case '>':
                    if (it != pw.end()) it++;
                    break;
                case '-':
                    if (it == pw.begin()) break;
                    del = it;
                    del--;
                    pw.erase(del);
                    break;
                default:
                    pw.insert(it, c);
                    break;
            }
        }

        for (char c : pw) {
            cout << c;
        }
        cout << "\n";
        pw.clear();
        it = pw.begin();
    }
}