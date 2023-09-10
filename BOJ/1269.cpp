#include <bits/stdc++.h>
using namespace std;
map<int, int> setMap;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int Ai, Bi;
    cin >> Ai; cin >> Bi;
    int total = Ai + Bi;

    int in;
    for (int i = 0; i < total; i++) {
        cin >> in;
        setMap.insert({in,0});
    }
    int setSize = setMap.size();
    int dup = total - setSize;
    cout << total - dup*2;
}

// p.s. This code DOES NOT WORK if the number of set is over 3.