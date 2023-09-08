#include <bits/stdc++.h>
#define cardNumber first
#define counted second
using namespace std;
typedef long long ll;
map<ll, int> counter;
pair<ll, int> maxCount;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    ll i = 0;
    for (int n = 0; n < N; n++) {
        cin >> i;
        if (counter.find(i) != counter.end()) counter[i] += 1;
        else counter.insert({i, 1});
    }
    for (pair<ll, int> current : counter) {
        if (current.counted > maxCount.counted) maxCount = current;
    }
    cout << maxCount.cardNumber << endl;
}

/*
 * Tip : Map version is slower than Sort version. (Map ≠ HashMap in C++)
 * Because the maximum call of counter.insert() is N, which has range 1 to 100k.11652 카드 (Map).cpp
 * Insert time complexity is O(logN).
 * N different values can cause O(NlogN) time.
 * So the final time complexity is : NlogN + NlogN = 2NlogN => O(NlogN)
 */