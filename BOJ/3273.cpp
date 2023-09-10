#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int cnt = 0;
    int N;
    int a[100000];
    int x;
    cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> a[n];
    }
    cin >> x;
    sort(a, a+N);

    int i=0, j=N-1;
    int sum;
    while (i < j) {
        sum = a[i] + a[j];
        if (sum == x) {
            cnt++;
            i++; j--;
        }
        else if (sum > x) j--;
        else i++;
    }
    cout << cnt;
}