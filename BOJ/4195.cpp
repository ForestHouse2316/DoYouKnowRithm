#include <bits/stdc++.h>
using namespace std;

int T, F, ra, rb, idCnt, num[200002], parent[200002];
string a, b;
unordered_map<string, int> id;

int root(int child) {
    if (child == parent[child]) return child;
    return parent[child] = root(parent[child]);
}

int getId(string name) {
    if (id.count(name) == 1) return id[name];
    return id[name] = idCnt++;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> T;
    while (T--) {
        for (int i = 0; i < 200002; ++i) {
            parent[i] = i;
        }
        fill(num, num+200002, 1);
        id.clear();
        idCnt = 0;

        cin >> F;
        while(F--) {
            cin >> a >> b;
            ra = root(getId(a));
            rb = root(getId(b));
            if (ra != rb) {
                num[rb] += num[ra];
                parent[ra] = rb;
            }
            cout << num[rb] << '\n';
        }
    }
}