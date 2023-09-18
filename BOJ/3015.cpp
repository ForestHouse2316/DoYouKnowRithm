#include <bits/stdc++.h>
using namespace std;
int N;
stack<int> s;
int sum = 0;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;

    int in, maximum;
    for (int n = 0; n < N; n++) {
        cin >> in;

        if (!s.empty() && s.top() > in) {
            // lower input
            s.push(in);
            sum++;
        }
        else {
            while (!s.empty() &&) {

            }
        }
    }
}