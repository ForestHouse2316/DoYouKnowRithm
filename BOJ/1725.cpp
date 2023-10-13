#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> p;
#define from first
#define height second
ll N;
ll maxSize;
ll in;
p temp;
stack<p> s;  // Stack will automatically keep ascending order about height

/* SAME PROBLEM WITH 6549, BUT LITTLE DIFFERENCE EXISTS */

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
        cin >> N;
        maxSize = 0;

        // [0]
        cin >> in;
        s.emplace(0, in);


        // Start with [1]
        for (ll n = 1; n < N; n++) {
            cin >> in;

            if (s.top().height < in) {
                // BIG input
                s.emplace(n, in);
            }
            else if (s.top().height > in) {
                // SMALL input
                while (!s.empty() && s.top().height > in) {
                    temp = s.top();
                    maxSize = max(maxSize, temp.height * (n - temp.from));
                    s.pop();
                }

                if (s.empty()) {
                    // Push {0 , in}
                    s.emplace(0, in);
                }
                else if (in == 0) {
                    // stack might be filled with 0
                    while (!s.empty()) {
                        s.pop();
                    }
                    s.emplace(n, 0);  // Set new base
                }
                else {
                    // Cut the height of bar on the temp index and push it
                    s.emplace(temp.from, in);
                }
            }
            // If same height, pass
        }

        while (!s.empty()) {
            maxSize = max(maxSize, s.top().height * (N - s.top().from));
            s.pop();
        }

        cout << maxSize << "\n";
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
7 3 3 1 5 4 1 2
4 1000 1000 1000 1000
2 1000000000 1000000000
5 0 0 0 0 1
11 5 1 1 0 1 2 3 0 6 6 6
10 0 0 0 0 0 0 0 0 0 0
12 0 1 0 2 0 3 0 4 0 5 0 6
10 3 3 1 5 4 1 2 0 1000000000 1000000000
10 1 1 1 1 1 1 1 1 0 9
0


 ANSWER
 25
 50
 10
 2
 3
 3
 3
 6
 8
 8
 4000
 2000000000
 1
 18
 0
 6
 2000000000
 9


 */