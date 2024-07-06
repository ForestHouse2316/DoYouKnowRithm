#include <bits/stdc++.h>
#define DIV 1'000'000'007
using namespace std;
typedef unsigned long long ull;

ull N;
unordered_map<ull, ull> cache;

ull modOfP(ull n) {
    if (n < 2) return (ull) n;
    if (n < 5) return (ull) n-1;
    if (cache.find(n) == cache.end()) {
        if (n % 2 == 0) { // even
            ull half = n/2;
            cache[n] = (modOfP(half) * (modOfP(half+1) + modOfP(half-1))) % DIV;
        }
        else cache[n] = (modOfP(n/2)*modOfP(n/2) + modOfP(n/2 + 1)*modOfP(n/2 + 1)) % DIV; // odd
    }

    return cache[n];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    cout << modOfP(N);
}