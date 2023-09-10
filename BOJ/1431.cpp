#include <bits/stdc++.h>
using namespace std;

string str[50];

bool compare(const string& a, const string& b) {  // return true if a < b
    if (a.length() < b.length()) return true;
    if (a.length() > b.length()) return false;
    int aSum=0, bSum=0;
    for (int i = 0; i < a.length(); i++) {
        if (isdigit(a[i])) aSum += a[i] - '0';
        if (isdigit(b[i])) bSum += b[i] - '0';
    }
    if (aSum < bSum) return true;
    if (aSum > bSum) return false;
    return a < b;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N; cin >> N;
    for (int n = 0; n < N; n++) {
        cin >> str[n];
    }
    sort(str, str+N, compare);
    for (int n = 0; n < N; n++) {
        cout << str[n] << "\n";
    }
}