#include <bits/stdc++.h>
#define index first
#define value second
using namespace std;
typedef pair<int, int> p;
int N;
stack<p> s;
int result[1000005] = {0};
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    int in;
    for (int n = 0; n < N; n++) {
        cin >> in;
        while (!s.empty() && s.top().value < in) {
            result[s.top().index] = in;
            s.pop();
        }
        s.emplace(n, in);
    }

    while (!s.empty()) {
        result[s.top().index] = -1;
        s.pop();
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}