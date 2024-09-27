#include <bits/stdc++.h>
using namespace std;

int N, age;
string name;
unordered_map<int, vector<string>> dict;
bool existAges[201] = {false};

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> N;
    for (int n = 0; n < N; ++n) {
        cin >> age >> name;
        dict[age].push_back(name);
        existAges[age] = true;
    }

    for (int a = 1; a <= 200; ++a) {
        if (existAges[a]) for (string& _name : dict[a]) {
                cout << a << " " << _name << "\n";
            }
    }
}