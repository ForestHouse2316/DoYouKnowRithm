#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define from first
#define height second
ll N;
ll localStart;
ll maxSize;
ll in;
ll firstHeight;
ll localMinimum;
stack<p> s;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);


    while (true) {
        cin >> N;
        if (N == 0) break;

        maxSize = 0;
        localStart = 0;

        // [0]
        cin >> firstHeight;
        localMinimum = firstHeight;  // Except 0 height
        s.emplace(0, firstHeight);


        // Start with [1]
        // TODO 높이 0 나오면 아예 새로 루틴 돌리는 꼼수도 생각해봐도 될듯
        for (ll n = 1; n < N; n++) {
            cin >> in;

            if (in == 0) {
                localStart = n+1;
                continue;
            }

            if (s.top().height < in) {
                // BIG input
                s.emplace(n, in);
            }
            else if (s.top().height > in) {
                // SMALL input
                if (in < localMinimum) localMinimum = in;  // No need to check bigger height cases

                while (s.top().height > in) {
                    maxSize = max(maxSize, s.top().height * (n - s.top().from));
                    s.pop();
                }
            }

            // If same height, pass
        }

        ll localWidth = (N - s.top().from);  // TODO need to be LOCAL. Current : Global
        while (s.size() > 1) {
            maxSize = max(maxSize, s.top().height * localWidth);
            s.pop();
        }
        maxSize = max(maxSize, localMinimum * (N - s.top().from));  // LocalMinimum * LocalWidth

        cout << maxSize << "\n";
    }

}

/*
10 1 2 3 4 5 6 7 8 9 1
10 5 5 5 5 5 5 5 5 5 5
1 10
2 1 2
3 1 1 2
3 1 2 1
3 2 1 1
6 1 5 1 5 1 5
7 2 1 4 5 1 3 3
4 1000 1000 1000 1000
2 1000000000 1000000000
0

 */