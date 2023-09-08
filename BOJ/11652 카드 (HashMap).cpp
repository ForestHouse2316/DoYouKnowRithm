#include <bits/stdc++.h>
#define cardNumber first
#define counted second
using namespace std;
typedef long long ll;
unordered_map<ll, int> counter;
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
        if (current.counted > maxCount.counted || current.counted == maxCount.counted && current.cardNumber < maxCount.cardNumber) maxCount = current;
    }
    cout << maxCount.cardNumber << endl;
}

/*
 * Idk why hashmap is slower than sort;;;;;;;;;;
 * But we(me and my friend) think that since each N number can differ, there can be able to exist a pair that cause the hash collision.
 */