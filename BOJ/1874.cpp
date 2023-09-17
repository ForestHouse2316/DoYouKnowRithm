#include <bits/stdc++.h>
using namespace std;
int N;
list<char> result;
stack<int> s;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    int in;
    int maximum = 0;
    bool no = false;
    s.push(0);

    for (int n = 0; n < N; n++) {
        cin >> in;
        if (s.top() > in) {
            cout << "NO";
            no = true;
            break;
        }
        else if (s.top() == in) {
            result.push_back('-');
            s.pop();
        }
        else {
            for (int i = maximum+1; i <= in; i++) {
                result.push_back('+');
                s.push(i);
            }
            maximum = in;
            result.push_back('-');
            s.pop();
        }
    }

    if (!no) {
        for(char c : result) {
            cout << c << "\n";
        }
    }
}