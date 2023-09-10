#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string room;
    cin >> room;
    int cnt[10] = {0};
    for (char c : room) {
        cnt[c-'0']++;
    }
    int ss = cnt[6] + cnt[9];
    int m = 0;
    for (int i = 0; i < 10; i++) {
        if (i == 6 || i == 9) continue;
        m = max(m, cnt[i]);
    }
    if (ss > m*2) cout << (ss+1)/2;
    else cout << m;
}