#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> p;
#define idx first
#define val second

int result[5000005];
deque<p> minimum;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, L, in;
    cin >> N;
    cin >> L;

    cin >> in;
    minimum.emplace_back(0, in);
    result[0] = in;
    for (int n = 1; n < N; n++) {
        cin >> in;
        if (minimum.front().idx <= n-L) {
            // Delete old one
            minimum.pop_front();
        }

        if (!minimum.empty()) {
            if (minimum.front().val >= in) {
                // Trick for faster execution
                minimum.clear();
            }
            else {
                while (minimum.back().val > in) {
                    minimum.pop_back();
                }
            }
        }
        minimum.emplace_back(n, in);
        result[n] = minimum.front().val;
    }

    for (int i = 0; i < N; i++) {
        cout << result[i] << " ";
    }
}