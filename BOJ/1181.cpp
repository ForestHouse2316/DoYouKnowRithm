#include <bits/stdc++.h>
using namespace std;

int N;
string in;
vector<string> lenSepStr[51]; // length-based separated string array, 1-indexed

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> in;
        lenSepStr[in.length()].push_back(in);
    }

    for (int l = 1; l <= 50; ++l) {
        if (lenSepStr[l].empty()) continue;
        sort(lenSepStr[l].begin(), lenSepStr[l].end());

        cout << lenSepStr[l][0] << "\n";
        for (int i = 1; i < lenSepStr[l].size(); ++i) {
            if (lenSepStr[l][i - 1] != lenSepStr[l][i]) cout << lenSepStr[l][i] << "\n";
        }
    }
}