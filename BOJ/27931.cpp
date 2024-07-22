#include <bits/stdc++.h>
using namespace std;
#define P vertex[n-offset]
#define C vertex[n]
typedef pair<int, int> pii;

int N, vertex[500'000], a = 0, oddMin = INT_MAX, evenMin = INT_MAX;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> C;
    }

    sort(vertex, vertex+N);
    if ((vertex[1] - vertex[0]) % 2 == 0) evenMin = vertex[1] - vertex[0];
    else oddMin = vertex[1] - vertex[0];

    for (int n = 2; n < N; ++n) {
        for (int offset = 1; offset <= 2; ++offset) {
            if ((C - P) % 2 == 0) evenMin = min(C - P, evenMin);
            else oddMin = min(C - P, oddMin);
        }
    }

    cout << (evenMin == INT_MAX ? -1 : evenMin) << ' ' << (oddMin == INT_MAX ? -1 : oddMin);
}