#include <bits/stdc++.h>
using namespace std;

int T, F;
string a, b;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> T;
    while (T--) {
        map<string, string**> tree;  // name, group name pptr
        list <string*> namePtr;  // group name pointer
        map<string*, int> size;  // group name, size
        list<string> names;
        cin >> F;
        while(F--) {
            cin >> a >> b;
            if (tree.find(a) == tree.end()) {
                if (tree.find(b) == tree.end()) {  // no a b
                    names.push_front(b);
                    namePtr.push_front(&(*names.begin()));
                    tree[b] = &(*namePtr.begin());
                    size[*tree[b]] = 1;
                }
                // no a
                tree[a] = tree[b];  // a -> b
                size[*tree[b]] += 1;
            }
            else {
                if (tree.find(b) == tree.end()) {  // no b
                    tree[b] = tree[a];  // b -> a
                    size[*tree[a]] += 1;
                }
                else if (**tree[a] != **tree[b]){  // both exist && different group
                    size[*tree[b]] += size[*tree[a]];  // a group size
                    size.erase(*tree[a]);
                    *tree[a] = *tree[b]; // a group name ptr -> b group name ptr
                }
            }
            cout << size[*tree[b]] << '\n';
        }
    }
}