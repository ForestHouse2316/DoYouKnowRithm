#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll mod(ll a, ll p, ll c) {
    if (p == 1) {
        return a % c;
    }
    ll halfMod = mod(a, p/2, c);
    if (p % 2 == 0) {
        return (halfMod * halfMod) % c;
    }
    else {
        return ((halfMod * halfMod % c) * a) % c;
    }
}

int main() {
    int a,b,c;
    cin >> a;
    cin >> b;
    cin >> c;

    ll result = mod(a, b, c);
    cout << result << endl;
}

