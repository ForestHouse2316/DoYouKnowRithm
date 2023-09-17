#include <bits/stdc++.h>
using namespace std;
int ps[100005];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int K;
    cin >> K;

    int i = 1;
    int in;
    ps[0] = 0;
    for (int k = 0; k < K; k++) {
        cin >> in;
        if (in == 0) i--;
        else {
            ps[i] = ps[i-1] + in;
            i++;
        }
    }
    cout << ps[i-1];
}