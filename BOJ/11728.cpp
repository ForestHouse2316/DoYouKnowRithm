#include <bits/stdc++.h>
using namespace std;

int N, M;
int a[1000000];
int b[1000000];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> N; cin >> M;
    int in;
    for (int n = 0; n < N; n++) {
        cin >> in;
        a[n] = in;
    }
    for (int m = 0; m < M; m++) {
        cin >> in;
        b[m] = in;
    }

    int iA = 0, iB = 0;
    while (iA < N && iB < M) {
        if (a[iA] <= b[iB]) cout << (a[iA++]) << " ";
        else cout << (b[iB++]) << " ";
    }
    if (iA == N) {
        while (iB < M) {
            cout << b[iB++] << " ";
        }
    }
    else if (iB == M) {
        while (iA < N) {
            cout << a[iA++] << " ";
        }
    }
}