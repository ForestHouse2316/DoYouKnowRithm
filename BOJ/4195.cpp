#include <bits/stdc++.h>
#define MAX 100003
using namespace std;

int T, F, idCnt, ra, rb, parent[MAX*2], num[MAX];
string a, b;
unordered_map<string, int> id;

int root(int child) {
    if (child == parent[child]) return child;
    return root(parent[child]);
}

int assignId(string& name) {
    if (id.find(name) != id.end()) return id[name];
    id[name] = idCnt;
    return idCnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    F = MAX-2;
    cin >> T;
    while (T--) {
        for (int i = 0; i < F*2+1; ++i) {
            parent[i] = i;
        }
        fill(num, num+F+1, 1);
        id.clear();
        idCnt = 0;

        cin >> F;
        for(int f = 0; f < F; ++f) {
            cin >> a >> b;
            assignId(a); assignId(b);
            ra = root(id[a]);
            rb = root(id[b]);
            if (ra != rb) {
                num[rb] += num[ra];
                parent[ra] = rb;
            }
            cout << num[rb] << '\n';
        }
    }
}