#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll answer[1001];
int N;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    answer[1] = 1;
    answer[2] = 2;
    for (int n = 3; n <= N; n++) {
        answer[n] = (answer[n-1] + answer[n-2]) % 10007;  // (start w/ [2x1] block) + (start w/ [1x2] block)
    }
    cout << answer[N];
}
