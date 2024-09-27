#include <bits/stdc++.h>
using namespace std;
typedef unsigned long ul;

int N;
ul elems[100005] = {0};
string in;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> in;
        for (int i = 0; i < in.length(); ++i) {
            if (in[i] == '0') continue;
            elems[n] += (in[i]-'0') * (ul)pow(10, i);
        }
    }

    sort(elems, elems+N);
    for (int n = 0; n < N; ++n) {
        cout << elems[n] << '\n';
    }
}