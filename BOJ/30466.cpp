#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int N;
ll B, D;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N;
    if (N%2) {
        B = (N-1)/2;
        D = B-1;
    }
    else {
        B = D = N/2 - 1;
    }
    cout << 2 * B * D << "\n";
    for (int b = 2; b <= B+2; ++b) {
        cout << "1 " << b << "\n";
    }
    if (N != 3) cout << "2 " << B+3 << "\n";
    for (int d = B+4; d <= N; ++d) {
        cout << d-1 << " " << d << "\n";
    }
}