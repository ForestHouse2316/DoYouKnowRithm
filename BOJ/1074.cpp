#include <bits/stdc++.h>
using namespace std;

int quarter(int N, const int& r, const int& c) {
    if (N == 0) return 0;

    int middle = (int) pow(2, N-1);
    int rOffset = 0;
    int cOffset = 0;
    int preVisitTimes = 0;
    if (r >= middle) {
        rOffset = -middle;
        preVisitTimes += 2 * middle * middle;
    }
    if (c >= middle) {
        cOffset = -middle;
        preVisitTimes += middle * middle;
    }

    return preVisitTimes + quarter(N-1, r + rOffset, c + cOffset);
}

int main() {
    int N, r, c;
    cin >> N;
    cin >> r;
    cin >> c;

    cout << quarter(N, r, c) << endl;
}